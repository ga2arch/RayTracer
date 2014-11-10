//
//  Light.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "Light.h"

Light::Light(const Color& color, const float power): color(color), power(power) {};

RectangleLight::RectangleLight(const Point& pos,
                               const Vector& side1,
                               const Vector& side2,
                               const Color& color,
                               float power):
    Light(color, power), side1(side1), side2(side2) {};

bool RectangleLight::intersect(Intersection& i) {
    
    Vector norm = cross(side1, side2).normalized();
    float dot_prod = dot(norm, i.ray.dir);
    
    if (dot_prod >= 0.0f) return false;
    
    float t = (dot(norm, position) - dot(i.ray.origin, norm)) / (dot_prod);
    
    if (t >= i.t || t < kRayTMin) return false;
    
    Vector side1_norm = side1;
    Vector side2_norm = side2;
    float side1_length = side1_norm.normalize();
    float side2_length = side2_norm.normalize();
    
    Point world_point = i.ray.calculate(t);
    Point world_relpoint = world_point - position;
    Point local_point = Point(dot(world_relpoint, side1_norm),
                              dot(world_relpoint, side2_norm),
                              0.0f);
    
    // Do the actual range check
    if (local_point.x < 0.0f || local_point.x > side1_length ||
        local_point.y < 0.0f || local_point.y > side2_length)
    {
        return false;
    }
    
    i.t = t;
    i.shape = this;
    i.color = Color();
    i.emitted = color*power;
    i.normal = norm;
    
    if (dot(i.normal, i.ray.dir) > 0.0f)
        i.normal *= -1.0f;
    
    return true;
}
