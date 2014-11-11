//
//  RayTracer.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__RayTracer__
#define __RayTracer__RayTracer__

#include <stdio.h>
#include "Shape.h"
#include "Ray.h"
#include "Light.h"

const size_t kWidth = 512;
const size_t kHeight = 512;
const size_t kNumPixelSamples = 128;

struct Rng {
    unsigned int m_z, m_w;
    
    Rng(unsigned int z = 362436069, unsigned int w = 521288629) : m_z(z), m_w(w) { }
    
    float nextFloat() {
        unsigned int i = nextUInt32();
        return i * 2.328306e-10f;
    }
    
    unsigned int nextUInt32() {
        m_z = 36969 * (m_z & 65535) + (m_z >> 16);
        m_w = 18000 * (m_w & 65535) + (m_w >> 16);
        return (m_z << 16) + m_w;  /* 32-bit result */
    }
};

Ray make_camera_ray(float fov,
                    const Point& origin,
                    const Vector& target,
                    const Vector& targetUp,
                    float xPos,
                    float yPos);

Color trace(ShapeSet& scene,
            std::list<Shape*>& lights,
            float x, float y);


#endif /* defined(__RayTracer__RayTracer__) */
