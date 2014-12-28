//
//  RayTracer.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 27/12/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef RayTracer_RayTracer_h
#define RayTracer_RayTracer_h

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <glm/gtc/type_ptr.hpp>

using Point  = glm::vec3;
using Vector = glm::vec3;
using Normal = glm::vec3;

float radians (float d) {
    return static_cast<float>(d * M_PI / 180);
}

inline float clamp(float x, float a, float b) {
    return x < a ? a : (x > b ? b : x);
}

inline bool quadratic(float A, float B, float C, float* t0, float* t1) {
    float d = B * B - 4.f * A * C;
    if (d <= 0) return false;
    
    float r_d = sqrtf(d);
    float q;
    
    if (B < 0) q = -.5f * (B - r_d);
    else       q = -.5f * (B + r_d);
    
    *t0 = q / A;
    *t1 = C / q;
    
    if (*t0 > *t1) std::swap(*t0, *t1);
    return true;
}

#endif
