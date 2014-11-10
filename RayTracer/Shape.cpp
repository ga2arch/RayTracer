//
//  Shape.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "Shape.h"

// ShapeSet

void ShapeSet::add_shape(Shape *shape) {
    shapes.push_back(shape);
}

void ShapeSet::clear_shapes() {
    shapes.clear();
}

// Plane

Plane::Plane(const Point& pos, const Vector& norm, const Color& col): pos(pos),
                                                                      norm(norm.normalized()),
                                                                      col(col) {};

bool Plane::intersect(Intersection& i) {
    
    float dot_prod = dot(norm, i.ray.dir);
    
    if (dot_prod >= 0.0f) return false;
    
    float t = (dot(norm, pos) - dot(i.ray.origin, norm)) / (dot_prod);
    
    if (t >= i.t || t < kRayTMin) return false;
    
    i.t = t;
    i.shape = this;
    i.color = col;
    i.normal = norm;
    
    return true;
}
