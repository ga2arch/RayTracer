//
//  Vector.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__Vector__
#define __RayTracer__Vector__

#include <stdio.h>

class Vector {
    
public:
    float x, y, z;
    
    Vector();
    Vector(const Vector& v_);
    
    explicit Vector(float x_, float y_, float z_);
    explicit Vector(float f);
    
    
    float length() const;
    float length2() const;
    
    void normalize();
    void normalized();
    
    Vector& operator  =(const Vector& v);
    Vector& operator +=(const Vector& v);
    Vector& operator -=(const Vector& v);
    Vector& operator *=(const float f);
    Vector& operator /=(const float f);
    
};

#endif /* defined(__RayTracer__Vector__) */
