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

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/type_ptr.hpp>

using Point  = glm::vec3;
using Vector = glm::vec3;

class Ray {
    
public:
    Ray(): mint(0.f), maxt(INFINITY), time(0.f), depth(0) {}
    Ray(const Point& origin, const Vector& direction, const Ray& parent,
        float start, float end = INFINITY)
    : o(origin), d(direction), mint(start), maxt(end),
    time(parent.time), depth(parent.depth + 1) {}
    
    Point operator()(float t) { return o + d * t; }
    
    Point o;
    Vector d;
    
    mutable float mint, maxt;
    float time;
    int depth;
};

#endif /* defined(__RayTracer__Ray__) */
