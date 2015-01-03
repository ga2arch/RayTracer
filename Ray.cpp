//
//  Ray.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 27/12/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "Ray.h"

Ray::Ray(): mint(0.f), maxt(INFINITY), time(0.f), depth(0) {}

Ray::Ray(const Point& origin,
         const Vector& direction,
         float start, float end)

: o(origin), d(direction), mint(start), maxt(end),
  time(0), depth(1) {}

Point Ray::operator()(float t) { return o + d * t; }