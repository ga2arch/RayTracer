//
//  Color.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "Color.h"

Color::Color(): r(0),g(0),b(0) {};
Color::Color(float r_, float g_, float b_): r(r_), g(g_), b(b_) {};
Color::Color(const Color& c): r(c.r), g(c.g), b(c.b) {};
Color::Color(const float f): r(f), g(f), b(f) {};

void Color::clamp(float min, float max) {
    r = std::max(min, std::min(max, r));
    g = std::max(min, std::min(max, r));
    b = std::max(min, std::min(max, r));
}

Color& Color::operator=(const Color& c) {
    r = c.r;
    g = c.g;
    b = c.b;
    
    return *this;
}

Color& Color::operator+=(const Color& c) {
    r += c.r;
    g += c.g;
    b += c.b;

    return *this;
}

Color& Color::operator-=(const Color& c) {
    r -= c.r;
    g -= c.g;
    b -= c.b;
    
    return *this;
}

Color& Color::operator*=(const float f) {
    r *= f;
    g *= f;
    b *= f;
    
    return *this;
}

Color& Color::operator/=(const float f) {
    r /= f;
    g /= f;
    b /= f;
    
    return *this;
}