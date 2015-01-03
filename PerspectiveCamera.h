//
//  PerspectiveCamera.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 03/01/15.
//  Copyright (c) 2015 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__PerspectiveCamera__
#define __RayTracer__PerspectiveCamera__

#include <stdio.h>
#include "ProjectiveCamera.h"

class PerspectiveCamera: public ProjectiveCamera {
    
public:
    PerspectiveCamera(const Transform& c2w,
                      const float screen_window[4],
                      float sopen, float sclose,
                      float fov, Film *film);

    
};

#endif /* defined(__RayTracer__PerspectiveCamera__) */
