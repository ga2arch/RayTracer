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

Transform Transform::RotateX(float angle) {
    float sin_t = sinf(radians(angle));
    float cos_t = cosf(radians(angle));
    
    glm::mat4x4 m(1, 0, 0, 0,
                  0, cos_t, -sin_t, 0,
                  0, sin_t, cos_t, 0,
                  0, 0, 0, 0);
    
    return Transform(m, glm::transpose(m));
}

Transform Transform::RotateY(float angle) {
    float sin_t = sinf(radians(angle));
    float cos_t = cosf(radians(angle));
    
    glm::mat4x4 m(cos_t, 0, sin_t, 0,
                  0, 1, 0, 0,
                  -sin_t, 0, cos_t, 0,
                  0, 0, 0, 1);
    
    return Transform(m, glm::transpose(m));
}

Transform Transform::RotateZ(float angle) {
    float sin_t = sinf(radians(angle));
    float cos_t = cosf(radians(angle));
    
    glm::mat4x4 m(cos_t, -sin_t, 0, 0,
                  sin_t, cos_t, 0, 0,
                  0, 0, 1, 0,
                  0, 0, 0, 1);
    
    return Transform(m, glm::transpose(m));
}

Transform Transform::LookAt(const Point &pos, const Point &look, const Vector &up) {
    auto dir = glm::normalize(look - pos);
    auto left = glm::normalize(glm::cross(glm::normalize(up), dir));
    auto new_up = glm::cross(dir, left);
    
    glm::mat4x4 m;
    m[0][0] = left.x;
    m[1][0] = left.y;
    m[2][0] = left.z;
    m[3][0] = 0;

    m[0][1] = new_up.x;
    m[1][1] = new_up.y;
    m[2][1] = new_up.z;
    m[3][1] = 0;
    
    m[0][2] = dir.x;
    m[1][2] = dir.y;
    m[2][2] = dir.z;
    m[3][2] = 0;
    
    m[0][3] = pos.x;
    m[1][3] = pos.y;
    m[2][3] = pos.z;
    m[3][3] = 1;
    
    return Transform(glm::inverse(m), m);
}

glm::vec3 Transform::operator()(const glm::vec3 &pt) const {
    float xp = m[0][0]*pt.x + m[0][1]*pt.y + m[0][2]*pt.z;
    float yp = m[1][0]*pt.x + m[1][1]*pt.y + m[1][2]*pt.z;
    float zp = m[2][0]*pt.x + m[2][1]*pt.y + m[2][2]*pt.z;
    float wp = m[3][0]*pt.x + m[3][1]*pt.y + m[3][2]*pt.z;
    
    if (wp == 1. || !wp) return glm::vec3(xp, yp, zp);
    else return glm::vec3(xp, yp, zp)/wp;
}

Ray Transform::operator()(const Ray& r) const {
    auto ret = r;
    ret.o = (*this)(ret.o);
    ret.d = (*this)(ret.d);
    return ret;
}
