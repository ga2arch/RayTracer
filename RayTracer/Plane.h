//
//  Plane.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 11/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__Plane__
#define __RayTracer__Plane__

#include <stdio.h>
#include "Shape.h"

class Plane: public Shape {
    
public:
    Plane(const Point& pos, const Vector& norm, const Color& col, bool beye);
    
    virtual ~Plane() {};
    
    virtual bool intersect(Intersection& i);
    
protected:
    Point pos;
    Vector norm;
    Color col;
    bool bullseye;
    
};

#endif /* defined(__RayTracer__Plane__) */
