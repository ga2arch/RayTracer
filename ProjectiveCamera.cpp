//
//  ProjectiveCamera.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 01/01/15.
//  Copyright (c) 2015 Gabriele Carrettoni. All rights reserved.
//

#include "ProjectiveCamera.h"

ProjectiveCamera::ProjectiveCamera(const Transform& c2w, const Transform& proj,
                                   const float screen_window[4], float sopen, float sclose,
                                   Film *film)
: Camera(c2w, sopen, sclose) {
    
    screen_to_raster = Transform::Scale(float(film->x_res),
                                        float(film->y_res),
                                        float(1.f)) *
        Transform::Scale(1.f / (screen_window[1] - screen_window[0]),
                         1.f / (screen_window[2] - screen_window[3]),
                         1.f) *
        Transform::Translate(Vector(-screen_window[0], -screen_window[3], 0.f));
    
    camera_to_screen = proj;
    raster_to_camera = Transform::Inverse(camera_to_screen) * raster_to_screen;
}