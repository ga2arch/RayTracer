//
//  Light.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__Light__
#define __RayTracer__Light__

#include <stdio.h>
#include "Shape.h"

class Light: public Shape {
    
public:
    Light(const Color& color, const float power);
    
    virtual ~Light() {};
    virtual void find_lights(std::list<Shape*>& out_ligths) {
        out_ligths.push_back(this);
    };
    
    virtual Color emitted() const {
        return color * power;
    }
    
protected:
    Color color;
    float power;
    
};

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

#endif /* defined(__RayTracer__Light__) */
