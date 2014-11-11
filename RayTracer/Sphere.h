//
//  Sphere.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 11/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__Sphere__
#define __RayTracer__Sphere__

#include <stdio.h>
#include "Shape.h"

class Sphere: public Shape {
    
public:
    Sphere(const Point& pos,
           const Vector& norm,
           const Color& col,
           float radius);
    
    virtual ~Sphere() {};
    
    virtual bool intersect(Intersection& i);
    
protected:
    Point pos;
    Vector norm;
    Color col;
    float radius;
    
};

#endif /* defined(__RayTracer__Sphere__) */
