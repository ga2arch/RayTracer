//
//  Intersection.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__Intersection__
#define __RayTracer__Intersection__

#include <stdio.h>
#include "Ray.h"
#include "Vector.h"
#include "Shape.h"
#include "Color.h"

class Intersection {
    
    Ray ray;
    float t;
    Shape* shape;
    Color color;
    Vector normal;
    
    Intersection();
    Intersection(const Intersection& i);
    Intersection(const Ray& r);
    
    Intersection& operator =(const Intersection& i);
    
    bool hit() const;
    Point position() const;
    
};

#endif /* defined(__RayTracer__Intersection__) */
