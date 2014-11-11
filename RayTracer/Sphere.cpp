//
//  Sphere.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 11/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "Sphere.h"

Sphere::Sphere(const Point& pos,
               const Vector& norm,
               const Color& col,
               float radius):
    pos(pos),
    norm(norm.normalized()),
    col(col), radius(radius) {};

bool Sphere::intersect(Intersection& i) {
    
    float t0, t1; // solutions for t if the ray intersects
    // geometric solution
    auto L = pos - i.ray.origin;
    
    float tca = dot(L, i.ray.dir);
    if (tca < 0) return false;
    
    float d2 = dot(L, L) - tca * tca;
    if (d2 > radius*radius) return false;
    float thc = sqrt(radius*radius - d2);
    t0 = tca - thc;
    t1 = tca + thc;
    if (t0 > i.ray.tmax) return false;
    else i.ray.tmax = t0;
    
    i.t       = t0;
    i.shape   = this;
    i.color   = col;
    i.emitted = Color();
    i.normal  = norm;
    
    return true;
    
}
