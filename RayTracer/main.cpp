//
//  main.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "Shape.h"
#include "Ray.h"

const size_t kWidth = 512;
const size_t kHeight = 512;

Ray make_camera_ray(float fov,
                    const Point& origin,
                    const Vector& target,
                    const Vector& targetUp,
                    float xPos,
                    float yPos) {
    
    Vector forward = (target - origin).normalized();
    Vector right = cross(forward, targetUp).normalized();
    Vector up = cross(right, forward).normalized();
    
    float tanFov = std::tan(fov * M_PI / 180.0f);
    
    Ray ray;
    ray.origin = origin;
    ray.dir = forward + right * (xPos - 0.5f) * tanFov
              + up  * (yPos - 0.5f) * tanFov;
    ray.dir.normalize();
    
    return ray;

}


int main(int argc, const char * argv[]) {
    
    
    ShapeSet shapet_set;
    
    Plane plane(Point(0.0f, -2.0f, 0.0f),
                Vector(0.0f, 1.0f, 0.0f),
                Color(1.0f, 0.5f, 0.8f), true);
    
    shapet_set.add_shape(&plane);
    
    std::ostringstream header;
    header << "P6\n";
    header << kWidth << ' ' << kHeight << '\n';
    header << "255\n";
    std::ofstream fileStream("out.ppm", std::ios::out | std::ios::binary);
    fileStream << header.str();

    for (size_t y = 0; y < kHeight; y++) {
        float yu = 1.0f - (float(y) / float(kHeight - 1));
        
        for (size_t x = 0; x < kWidth; ++x) {
            float xu = float(x) / float(kWidth - 1);
            
            // Find where this pixel sample hits in the scene
            Ray ray = make_camera_ray(30.0f,
                                    Point(0.0f, 0.0f, 0.0f),
                                    Point(0.0f, 0.0f, 1.0f),
                                    Point(0.0f, 1.0f, 0.0f),
                                    xu,
                                    yu);
            
            Intersection intersection(ray);
            bool intersected = shapet_set.intersect(intersection);

            Color pixel_color(0.0f, 0.0f, 0.0f);
            if (intersected)
                pixel_color = intersection.color;
            
            pixel_color.clamp();
            
            unsigned char r, g, b;
            r = static_cast<unsigned char>(pixel_color.r * 255.0f);
            g = static_cast<unsigned char>(pixel_color.g * 255.0f);
            b = static_cast<unsigned char>(pixel_color.b * 255.0f);
            fileStream << r << g << b;
        }
    }
}
