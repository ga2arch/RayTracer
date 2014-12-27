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

float radians (float d) {
    return static_cast<float>(d * M_PI / 180);
}

#endif
