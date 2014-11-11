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


#endif /* defined(__RayTracer__Light__) */
