//
//  Color.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__Color__
#define __RayTracer__Color__

#include <stdio.h>
#include <iostream>
#include <algorithm>

class Color {
    
public:
    float r, g, b;
    
    Color();
    Color(const Color& c);
    explicit Color(float r_, float g_, float b_);
    explicit Color(float f);
    
    void clamp(float min = 0.0f, float max = 1.0f);
    
    Color& operator  =(const Color& v);
    Color& operator +=(const Color& v);
    Color& operator -=(const Color& v);
    Color& operator *=(const float f);
    Color& operator /=(const float f);
};

inline Color operator +(const Color& c1, const Color& c2) {
    Color c(c1.r + c2.r, c1.g + c2.g, c1.b + c2.b);
    return c;
}

inline Color operator -(const Color& c1, const Color& c2) {
    Color c(c1.r - c2.r, c1.g - c2.g, c1.b - c2.b);
    return c;
}

inline Color operator *(const Color& c1, const Color& c2) {
    Color c(c1.r * c2.r, c1.g * c2.g, c1.b * c2.b);
    return c;
}


inline Color operator *(const Color& c1, const float f) {
    Color c(c1.r * f, c1.g * f, c1.b * f);
    return c;
}

inline Color operator *(const float f, const Color& c1) {
    Color c(c1.r * f, c1.g * f, c1.b * f);
    return c;
}

#endif /* defined(__RayTracer__Color__) */
