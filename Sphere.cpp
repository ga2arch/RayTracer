//
//  Sphere.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 28/12/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "Sphere.h"

Sphere::Sphere(const Transform* o2w, const Transform* w2o, bool ro,
               float rad, float z0, float z1, float pm)
: Shape(o2w, w2o, ro) {
    
    radius = rad,

    zmin = clamp(fmin(z0, z1), -radius, radius);
    zmax = clamp(fmax(z0, z1), -radius, radius);

    theta_min = acosf(clamp(zmin/radius, -1.f, 1.f));
    theta_max = acosf(clamp(zmax/radius, -1.f, 1.f));
    
    phi_max = radians(clamp(pm, 0.0f, 360.0f));
}

bool Sphere::intersect(const Ray &r, float *thit, float *ray_e) const {
    float phi;
    float phi_t;
    
    auto ray = (*world_to_object)(r);
    
    float A = powf(ray.d.x, 2) + powf(ray.d.y, 2) + powf(ray.d.z, 2);
    float B = 2 * (ray.d.x*ray.o.x + ray.d.y*ray.o.y + ray.d.z*ray.o.z);
    float C = powf(ray.o.x, 2) + powf(ray.o.y, 2) + powf(ray.o.z, 2) - powf(radius, 2);
    
    float t0, t1;
    if (!quadratic(A, B, C, &t0, &t1))
        return false;
    
    if (t0 > ray.maxt || t1 < ray.mint)
        return false;
    
    thit = &t0;
    if (t0 < ray.mint) {
        thit = &t1;
        if (*thit > ray.maxt) return false;
    }
    
    // TODO: add rest of the method
    
    return true;
}