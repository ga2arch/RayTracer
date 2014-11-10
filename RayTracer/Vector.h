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
    Vector normalized() const;
    
    Vector& operator  =(const Vector& v);
    Vector& operator +=(const Vector& v);
    Vector& operator -=(const Vector& v);
    Vector& operator *=(const float f);
    Vector& operator /=(const float f);
    
};

typedef Vector Point;

inline Vector operator +(const Vector& v1, const Vector& v2) {
    Vector v(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
    return v;
}

inline Vector operator *(const Vector& v1, const Vector& v2) {
    Vector v(v1.x * v2.x, v1.y * v2.y, v1.z * v2.z);
    return v;
}

inline Vector operator -(const Vector& v1, const Vector& v2) {
    Vector v(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
    return v;
}

inline Vector operator *(const Vector& v1, const float f) {
    Vector v(v1.x * f, v1.y * f, v1.z * f);
    return v;
}

inline Vector operator *(const float f, const Vector& v1) {
    Vector v(v1.x * f, v1.y * f, v1.z * f);
    return v;
}

inline float dot(const Vector& v1, const Vector& v2) {
    return v1.x*v2.x + v1.y*v2.y + v1.z*v2.z;
}

inline Vector cross(const Vector& v1, const Vector& v2) {
    Vector v (v1.y * v2.z - v1.z * v2.y,
              v1.z * v2.x - v1.x * v2.z,
              v1.x * v2.y - v1.y * v2.x);
    return v;
}

#endif /* defined(__RayTracer__Vector__) */
