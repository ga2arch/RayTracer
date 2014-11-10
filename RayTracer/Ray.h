//
//  Ray.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__Ray__
#define __RayTracer__Ray__

#include <stdio.h>
#include "Vector.h"
#include <cmath>

const float kRayTMin = 0.00001f;
const float kRayTMax = 1.0e30f;

class Ray {
    
public:
    Point origin;
    Vector dir;
    
    float tmax;
    
    Ray();
    Ray(const Ray& r);
    Ray(Point& origin_, Vector& dir_, float tmax = kRayTMax);
    
    Ray& operator =(const Ray& r);
    
    Point calculate(const float t) const;
};

#endif /* defined(__RayTracer__Ray__) */
