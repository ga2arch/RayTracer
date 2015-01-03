//
//  Camera.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 31/12/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__Camera__
#define __RayTracer__Camera__

#include <stdio.h>
#include "Transform.h"

class Camera {
    
public:
    Camera(const Transform& c2w, float sopen, float sclose);
    
    virtual float generate_ray(Ray& ray) const =0;
    
    Transform cam2world;
    const float shutter_open, shutter_close;
    
};


#endif /* defined(__RayTracer__Camera__) */
