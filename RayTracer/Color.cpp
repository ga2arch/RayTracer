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
    g = std::max(min, std::min(max, g));
    b = std::max(min, std::min(max, b));
}

std::tuple<uchar, uchar, uchar> Color::to_rgb() {
    uchar r_, g_, b_;
    r_ = static_cast<unsigned char>(r * 255.0f);
    g_ = static_cast<unsigned char>(g * 255.0f);
    b_ = static_cast<unsigned char>(b * 255.0f);
    
    return std::make_tuple(r_, g_, b_);
}

std::ostream& operator <<(std::ostream& out, Color& color) {
    auto rgb = color.to_rgb();
    out << std::get<0>(rgb) << std::get<1>(rgb) << std::get<2>(rgb);
    return out;
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