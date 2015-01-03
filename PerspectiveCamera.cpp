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
                   screen_window, sopen, sclose, film) {}
