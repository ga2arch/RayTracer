//
//  Camera.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 31/12/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "Camera.h"

Camera::Camera(const Transform& c2w, float sopen, float sclose)
: cam2world(c2w), shutter_open(sopen), shutter_close(sclose) {}

