//
//  PerspectiveCamera.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 03/01/15.
//  Copyright (c) 2015 Gabriele Carrettoni. All rights reserved.
//

#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera(const Transform& c2w,
                                     const float screen_window[4],
                                     float sopen, float sclose,
                                     float fov, Film *film)
: ProjectiveCamera(c2w, Transform::Perspective(fov, 1e-2f, 1000.f),
                   screen_window, sopen, sclose, film) {

    dx_cam = raster_to_camera(Point(1,0,0)) - raster_to_camera(Point(0,0,0));
    dy_cam = raster_to_camera(Point(0,1,0)) - raster_to_camera(Point(0,0,0));

}

float PerspectiveCamera::generate_ray(const Point &p, Ray *ray) {
    *ray = Ray(Point(0,0,0), Vector(p), 0.f, INFINITY);
    *ray = cam2world(*ray);
    
    return 1.f;
}
