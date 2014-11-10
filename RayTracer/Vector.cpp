//
//  Vector.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "Vector.h"
#include <cmath>

Vector::Vector(): x(0), y(0), z(0) {};
Vector::Vector(const Vector& v_): x(v_.x), y(v_.y), z(v_.z) {};

Vector::Vector(float x_, float y_, float z_): x(x_), y(y_), z(z_) {};
Vector::Vector(float f): x(f), y(f), z(f) {};

float Vector::length() const {
    return sqrtf(length2());
}

float Vector::length2() const {
    return x*x + y*y + z*z;
}

void Vector::normalize() {
    auto len = length();
    *this /= len;
}

Vector Vector::normalized() const {
    Vector r(*this);
    r.normalize();
    return r;
}

// Operators

Vector& Vector::operator=(const Vector& v) {
    x = v.x;
    y = v.y;
    z = v.z;
    
    return *this;
}

Vector& Vector::operator+=(const Vector& v) {
    x += v.x;
    y += v.y;
    z += v.z;
    
    return *this;
}

Vector& Vector::operator-=(const Vector& v) {
    x -= v.x;
    y -= v.y;
    z -= v.z;
    
    return *this;
}

Vector& Vector::operator*=(const float f) {
    x *= f;
    y *= f;
    z *= f;
    
    return *this;
}

Vector& Vector::operator/=(const float f) {
    x /= f;
    y /= f;
    z /= f;
    
    return *this;
}






