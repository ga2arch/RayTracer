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
#include "RayTracer.h"

class Transform {
    
public:
    Transform();
    Transform(const glm::mat4x4& m_);
    Transform(const glm::mat4x4& m_, const glm::mat4x4& m_inv_);
    
    static Transform Inverse(const Transform& t);
    static Transform Translate(const Vector& delta);
    static Transform Scale(float x, float y, float z);
    
private:
    glm::mat4x4 m, m_inv;
    
};

#endif /* defined(__RayTracer__Transform__) */
