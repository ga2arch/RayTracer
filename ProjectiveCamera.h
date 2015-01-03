//
//  ProjectiveCamera.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 01/01/15.
//  Copyright (c) 2015 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__ProjectiveCamera__
#define __RayTracer__ProjectiveCamera__

#include <stdio.h>
#include "Camera.h"

class ProjectiveCamera: public Camera {
    
public:
    ProjectiveCamera(const Transform& c2w, const Transform& proj,
                     const float screen_window[4], float sopen, float sclose);
    
    
    Transform camera_to_screen; raster_to_camera;
};

#endif /* defined(__RayTracer__ProjectiveCamera__) */
