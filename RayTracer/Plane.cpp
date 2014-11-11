//
//  Plane.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 11/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "Plane.h"

Plane::Plane(const Point& pos,
             const Vector& norm,
             const Color& col,
             bool beye):
    pos(pos), norm(norm.normalized()),
    col(col), bullseye(beye) {};

bool Plane::intersect(Intersection& i) {
    
    float dot_prod = dot(norm, i.ray.dir);
    
    if (dot_prod >= 0.0f) return false;
    
    float t = (dot(norm, pos) - dot(i.ray.origin, norm)) / (dot_prod);
    
    if (t >= i.t || t < kRayTMin) return false;
    
    i.t       = t;
    i.shape   = this;
    i.color   = col;
    i.emitted = Color();
    i.normal  = norm;
    
    if (bullseye && std::fmod((i.position() - pos).length() * 0.25f, 1.0f) > 0.5f) {
        i.color *= 0.2f;
    }
    
    return true;
}
