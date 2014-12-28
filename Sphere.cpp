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
