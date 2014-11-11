//
//  RayTracer.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "RayTracer.h"

RayTracer::RayTracer(ShapeSet& scene): scene(scene) {};

Ray RayTracer::make_camera_ray(float fov,
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

Color RayTracer::trace(float x, float y) {
    Rng rng;
    Color pixel_color(0.0f, 0.0f, 0.0f);
    
    for (size_t si = 0; si < kNumPixelSamples; si++) {
        
        
        float yu = 1.0f - ((y + rng.nextFloat()) / float(kHeight - 1));
        float xu = (x + rng.nextFloat()) / float(kWidth - 1);
        
        // Find where this pixel sample hits in the scene
        Ray ray = make_camera_ray(45.0f,
                                  Point(0.0f, 5.0f, 15.0f),
                                  Point(0.0f, 0.0f, 0.0f),
                                  Point(0.0f, 1.0f, 0.0f),
                                  xu, yu);
        
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
                    float light_attenuation = std::max(0.0f, dot(i.normal, to_light));
                    pixel_color += i.color * light_shape->emitted() * light_attenuation;
                }
            }
        }
    }
    
    return pixel_color;
}

void RayTracer::draw() {
    PPMImage image("out.ppm", kWidth, kHeight);

    std::list<Shape*> lights;
    scene.find_lights(lights);
    
    for (size_t y = 0; y < kHeight; y++) {
        for (size_t x = 0; x < kWidth; x++) {
            auto pixel_color = trace(x, y);
            
            pixel_color /= kNumPixelSamples;
            pixel_color.clamp();
            
            image.write_color(pixel_color);
        }
    }
}
