//
//  Shape.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 27/12/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "Shape.h"

Shape::Shape(const Transform* o2w, const Transform* w2o, bool ro)
:object_to_world(o2w), world_to_object(w2o),
 reverse_orientation(ro), shape_id(next_shape_id++) {}

bool Shape::can_intersect() {
    return true;
}

bool Shape::intersect(const Ray &ray, float *thit, float *ray_e) const {
    return false;
}

bool Shape::intersect_p(const Ray &ray) const {
    return false;
}