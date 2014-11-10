//
//  Intersection.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "Intersection.h"

Intersection::Intersection(): ray(), t(kRayTMax),
                              shape(nullptr), color(), normal() {};

Intersection::Intersection(const Intersection& i): ray(i.ray), t(i.t),
                                                   shape(i.shape), color(i.color),
                                                   normal(i.normal) {}

Intersection::Intersection(const Ray& r): ray(r),
                                          t(r.tmax),
                                          shape(nullptr),
                                          color(), normal() {}

bool Intersection::hit() const {
    return !(shape == nullptr);
}

Point Intersection::position() const {
    return ray.calculate(t);
}