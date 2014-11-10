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

// Inlines

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





