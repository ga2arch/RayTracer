//
//  Transform.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 27/12/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "Transform.h"

Transform::Transform(const glm::mat4x4& m_): m(m_), m_inv(glm::inverse(m_)) {};
Transform::Transform(const glm::mat4x4& m_, const glm::mat4x4& m_inv_): m(m_), m_inv(m_inv_) {};

Transform Transform::Inverse(const Transform &t) {
    return Transform(t.m_inv, t.m);
}

Transform Transform::Translate(const Vector &delta) {
    glm::mat4x4 m(1, 0, 0, delta.x,
                  0, 1, 0, delta.y,
                  0, 0, 1, delta.z,
                  0, 0, 0, 1);
    
    glm::mat4x4 m_inv(1, 0, 0, -delta.x,
                      0, 1, 0, -delta.y,
                      0, 0, 1, -delta.z,
                      0, 0, 0, 1);
    
    return Transform(m, m_inv);
}

Transform Transform::Scale(float x, float y, float z) {
    glm::mat4x4 m(x, 0, 0, 0,
                  0, y, 0, 0,
                  0, 0, z, 0,
                  0, 0, 0, 1);
    
    glm::mat4x4 m_inv(1.f/x, 0, 0, 0,
                      0, 1.f/y, 0, 0,
                      0, 0, 1.f/z, 0,
                      0, 0, 0,     1);
    
    return Transform(m, m_inv);
}
