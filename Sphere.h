//
//  Sphere.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 28/12/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__Sphere__
#define __RayTracer__Sphere__

#include <stdio.h>
#include "Shape.h"

class Sphere: public Shape {
    
public:
    Sphere(const Transform* o2w, const Transform* w2o, bool ro,
           float rad, float z0, float z1, float pm);
    
    bool intersection(const Ray& r, float* thit, float* ray_e) const;
    
private:
    float radius;
    float phi_max;
    float zmin, zmax;
    float theta_max, theta_min;

};

#endif /* defined(__RayTracer__Sphere__) */
