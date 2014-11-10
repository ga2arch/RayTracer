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

Plane::Plane(const Point& pos,
             const Vector& norm,
             const Color& col,
             bool beye): pos(pos), norm(norm.normalized()),
                         col(col), bullseye(beye) {};

bool Plane::intersect(Intersection& i) {
    
    float dot_prod = dot(norm, i.ray.dir);
    
    if (dot_prod >= 0.0f) return false;
    
    float t = (dot(norm, pos) - dot(i.ray.origin, norm)) / (dot_prod);
    
    if (t >= i.t || t < kRayTMin) return false;
    
    i.t = t;
    i.shape = this;
    i.color = col;
    i.emitted = Color();
    i.normal = norm;
    
    if (bullseye && std::fmod((i.position() - pos).length() * 0.25f, 1.0f) > 0.5f) {
        i.color *= 0.2f;
    }
    
    return true;
}

// Sphere

Sphere::Sphere(const Point& pos,
               const Vector& norm,
               const Color& col,
               float radius): pos(pos),
                              norm(norm.normalized()),
                              col(col), radius(radius) {};

bool Sphere::intersect(Intersection& i) {
    
    float t0, t1; // solutions for t if the ray intersects
    // geometric solution
    auto L = pos - i.ray.origin;
    
    float tca = dot(L, i.ray.dir);
    if (tca < 0) return false;
    
    float d2 = dot(L, L) - tca * tca;
    if (d2 > radius*radius) return false;
    float thc = sqrt(radius*radius - d2);
    t0 = tca - thc;
    t1 = tca + thc;
    if (t0 > i.ray.tmax) return false;
    else i.ray.tmax = t0;
    
    i.t = t0;
    i.shape = this;
    i.color = col;
    i.emitted = Color();
    i.normal = norm;
    
    return true;
    
}

