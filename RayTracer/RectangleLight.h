//
//  RectangleLight.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 11/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__RectangleLight__
#define __RayTracer__RectangleLight__

#include <stdio.h>
#include "Light.h"

class RectangleLight: public Light {
    
public:
    RectangleLight(const Point& pos,
                   const Vector& side1,
                   const Vector& side2,
                   const Color& color,
                   float power);
    
    virtual bool intersect(Intersection& i);
    virtual bool sample_surface(float u1,
                                float u2,
                                const Point& ref_pos,
                                Point& out_pos,
                                Vector& out_norm);
    
    virtual ~RectangleLight() {};
    
protected:
    Point position;
    Vector side1, side2;
    
};

#endif /* defined(__RayTracer__RectangleLight__) */
