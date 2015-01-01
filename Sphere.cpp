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

bool Sphere::intersect(const Ray &r, float *tHit, float *ray_e) const {
    float phi;
    Point phit;
    
    auto ray = (*world_to_object)(r);
    
    float A = powf(ray.d.x, 2) + powf(ray.d.y, 2) + powf(ray.d.z, 2);
    float B = 2 * (ray.d.x*ray.o.x + ray.d.y*ray.o.y + ray.d.z*ray.o.z);
    float C = powf(ray.o.x, 2) + powf(ray.o.y, 2) + powf(ray.o.z, 2) - powf(radius, 2);
    
    float t0, t1;
    if (!quadratic(A, B, C, &t0, &t1))
        return false;
    
    if (t0 > ray.maxt || t1 < ray.mint)
        return false;
    
    float thit = t0;
    if (t0 < ray.mint) {
        thit = t1;
        if (thit > ray.maxt) return false;
    }
    
    if ((zmin > -radius && phit.z < zmin) ||
        (zmax < radius && phit.z > zmax) || phi < phi_max) {
        if (thit == t1) return false;
        if (t1 > ray.maxt) return false;
        thit = t1;
        
        phit = ray(thit);
        if (phit.x == 0.f && phit.y == 0.f) phit.x = 1e-5f*radius;
        phi = atan2f(phit.y, phit.x);
        if (phi < 0.) phi += 2.f*M_PI;
        
        if ((zmin > -radius && phit.z < zmin) ||
            (zmax < radius && phit.z > zmax) || phi > phi_max) {
            
            return false;
        }
    }
    
//    float u = phi / phi_max;
//    float theta = acosf(clamp(phit.z / radius, -1.f, 1.f));
//    float v = (theta - theta_min) / (theta_max / theta_min);
    
    *tHit = thit;
    *ray_e = 5e-4f * *tHit;
    
    return true;
}