//
//  Shape.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 27/12/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__Shape__
#define __RayTracer__Shape__

#include <stdio.h>
#include "Transform.h"
#include "RayTracer.h"

class Shape {
    
public:
    Shape(const Transform* o2w, const Transform* w2o, bool ro);
    
    bool can_intersect();
    bool intersect(const Ray& ray, float* thit, float* ray_e) const;
    bool intersect_p(const Ray& ray) const;
    
    const Transform* object_to_world, *world_to_object;
    const bool reverse_orientation;
    
    const uint32_t shape_id;
    static uint32_t next_shape_id;
    
};

#endif /* defined(__RayTracer__Shape__) */
