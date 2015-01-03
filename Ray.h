//
//  Ray.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 27/12/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__Ray__
#define __RayTracer__Ray__

#include <stdio.h>
#include "RayTracer.h"


class Ray {
    
public:
    Ray();
    Ray(const Point& origin, const Vector& direction,
        float start, float end = INFINITY);
    
    Point operator()(float t);
    
    Point o;
    Vector d;
    
    mutable float mint, maxt;
    float time;
    int depth;
};

#endif /* defined(__RayTracer__Ray__) */
