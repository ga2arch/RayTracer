//
//  Ray.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "Ray.h"

Ray::Ray(): origin(), dir(0.0,0.0,1.0), tmax(kRayTMax) {}
Ray::Ray(const Ray& r): origin(r.origin), dir(r.dir), tmax(r.tmax) {}
Ray::Ray(Point& origin_, Vector& dir_, float tmax): origin(origin_),
                                                    dir(dir_),
                                                    tmax(tmax) {}


Ray& Ray::operator=(const Ray &r) {
    origin = r.origin;
    dir = r.dir;
    tmax = r.tmax;
    
    return *this;
}

Point Ray::calculate(const float t) const {
    return origin + t*dir;
}

// Utils

Ray make_camera_ray(float fov,
                    const Point& origin,
                    const Vector& target,
                    const Vector& targetUp,
                    float xPos,
                    float yPos) {
    
    Vector forward = (target - origin).normalized();
    Vector right = cross(forward, targetUp).normalized();
    Vector up = cross(right, forward).normalized();
    
    float tanFov = std::tan(fov * M_PI / 180.0f);
    
    Ray ray;
    ray.origin = origin;
    ray.dir = forward + right * (xPos - 0.5f) * tanFov
    + up  * (yPos - 0.5f) * tanFov;
    ray.dir.normalize();
    
    return ray;
    
}
