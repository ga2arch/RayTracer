//
//  Transform.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 27/12/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__Transform__
#define __RayTracer__Transform__

#include <stdio.h>
#include "Ray.h"
#include "RayTracer.h"

class Transform {
    
public:
    Transform();
    Transform(const glm::mat4x4& m_);
    Transform(const glm::mat4x4& m_, const glm::mat4x4& m_inv_);
    
    static Transform Inverse(const Transform& t);
    static Transform Translate(const Vector& delta);
    static Transform Scale(float x, float y, float z);
    
    static Transform RotateX(float angle);
    static Transform RotateY(float angle);
    static Transform RotateZ(float angle);

    static Transform LookAt(const Point& pos, const Point& look, const Vector& up);
    static Transform Perspective(float fov, float n, float f);

    glm::vec3 operator()(const glm::vec3& pt) const;
    Ray operator()(const Ray& ray) const;
    Transform operator*(const Transform &t) const;
    
private:
    glm::mat4x4 m, m_inv;
    
};

//inline Vector Transform::operator()(const Vector &v) const {
//    return Vector(m[0][0]*v.x + m[0][1]*v.y + m[0][2]*v.z,
//                  m[1][0]*v.x + m[1][1]*v.y + m[1][2]*v.z,
//                  m[2][0]*v.x + m[2][1]*v.y + m[2][2]*v.z);
//}
//
//inline Normal Transform::operator()(const Normal &n) const {
//    return Vector(m[0][0]*n.x + m[0][1]*n.y + m[0][2]*n.z,
//                  m[1][0]*n.x + m[1][1]*n.y + m[1][2]*n.z,
//                  m[2][0]*n.x + m[2][1]*n.y + m[2][2]*n.z);
//}


#endif /* defined(__RayTracer__Transform__) */
