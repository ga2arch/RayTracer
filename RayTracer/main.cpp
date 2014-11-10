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
#include "Light.h"

const size_t kWidth = 512;
const size_t kHeight = 512;
const size_t kNumPixelSamples = 128;

struct Rng
{
    unsigned int m_z, m_w;
    
    Rng(unsigned int z = 362436069, unsigned int w = 521288629) : m_z(z), m_w(w) { }

    float nextFloat() {
        unsigned int i = nextUInt32();
        return i * 2.328306e-10f;
    }
    
    unsigned int nextUInt32() {
        m_z = 36969 * (m_z & 65535) + (m_z >> 16);
        m_w = 18000 * (m_w & 65535) + (m_w >> 16);
        return (m_z << 16) + m_w;  /* 32-bit result */
    }
};

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
    
    Rng rng;
    ShapeSet scene;
    
    Plane plane(Point(0.0f, -2.0f, 0.0f),
                Vector(0.0f, 1.0f, 0.0f),
                Color(1.0f, 0.5f, 0.8f), true);
    
    scene.add_shape(&plane);
    
    Sphere sphere(Point(0.0f, -2.0f, 0.0f),
                  Vector(0.0f, 1.0f, 0.0f),
                  Color(1.0f, 0.3f, 0.3f),1.0);
    
    scene.add_shape(&sphere);
    
    RectangleLight areaLight(Point(-2.5f, 2.0f, -2.5f),
                             Vector(5.0f, 0.0f, 0.0f),
                             Vector(0.0f, 0.0f, 5.0f),
                             Color(1.0f, 0.5f, 1.0f),
                             3.0f);
    scene.add_shape(&areaLight);
    
    // Add another area light below it, darker, that will make a shadow too.
    RectangleLight smallAreaLight(Point(-2.0f, -1.0f, -2.0f),
                                  Vector(4.0f, 0.0f, 0.0f),
                                  Vector(0.0f, 0.0f, 4.0f),
                                  Color(1.0f, 1.0f, 0.5f),
                                  0.75f);
    scene.add_shape(&smallAreaLight);
    
    std::list<Shape*> lights;
    scene.find_lights(lights);
    
    std::ostringstream header;
    header << "P6\n";
    header << kWidth << ' ' << kHeight << '\n';
    header << "255\n";
    std::ofstream fileStream("out.ppm", std::ios::out | std::ios::binary);
    fileStream << header.str();

    for (size_t y = 0; y < kHeight; y++) {

        for (size_t x = 0; x < kWidth; x++) {
            
            Color pixel_color(0.0f, 0.0f, 0.0f);
            
            for (size_t si = 0; si < kNumPixelSamples; si++) {
            
                float yu = 1.0f - ((y + rng.nextFloat()) / float(kHeight - 1));
                float xu = (x + rng.nextFloat()) / float(kWidth - 1);
                
                // Find where this pixel sample hits in the scene
                Ray ray = make_camera_ray(45.0f,
                                          Point(0.0f, 5.0f, 15.0f),
                                          Point(0.0f, 0.0f, 0.0f),
                                          Point(0.0f, 1.0f, 0.0f),
                                          xu,
                                          yu);
                
                Intersection i(ray);
                if (scene.intersect(i)) {
                    pixel_color += i.emitted;
                    Point pos = i.position();
                    
                    for (Shape* light: lights) {
                        Point light_point;
                        Vector light_normal;
                        Light* light_shape = dynamic_cast<Light*>(light);
                        light_shape->sample_surface(rng.nextFloat(),
                                                    rng.nextFloat(),
                                                    pos,
                                                    light_point,
                                                    light_normal);
                        
                        Vector to_light = light_point - pos;
                        float light_distance = to_light.normalize();
                        Ray shadow_ray(pos, to_light, light_distance);
                        Intersection shadow_intersection(shadow_ray);
                        bool intersected = scene.intersect(shadow_intersection);
                        
                        if (!intersected || shadow_intersection.shape == light_shape) {
                            float lightAttenuation = std::max(0.0f, dot(i.normal, to_light));
                            pixel_color += i.color * light_shape->emitted() * lightAttenuation;
                        }
                    }
                }
            }
            
            pixel_color /= kNumPixelSamples;
            pixel_color.clamp();
            
            unsigned char r, g, b;
            r = static_cast<unsigned char>(pixel_color.r * 255.0f);
            g = static_cast<unsigned char>(pixel_color.g * 255.0f);
            b = static_cast<unsigned char>(pixel_color.b * 255.0f);
            fileStream << r << g << b;
        }
    }
}
