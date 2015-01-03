//
//  ProjectiveCamera.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 01/01/15.
//  Copyright (c) 2015 Gabriele Carrettoni. All rights reserved.
//

#include "ProjectiveCamera.h"

ProjectiveCamera::ProjectiveCamera(const Transform& c2w, const Transform& proj,
                                   const float screen_window[4], float sopen, float sclose)
: Camera(c2w, sopen, sclose) {
    
    auto screen_to_raster = glm::scale(<#const detail::tmat4x4<T, P> &m#>, <#const detail::tvec3<T, P> &v#>)
    
    camera_to_screen = proj;
    raster_to_camera = glm::inverse(camera_to_screen) * raster_to_screen;
}