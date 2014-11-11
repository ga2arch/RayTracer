//
//  PPMImage.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 11/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__PPMImage__
#define __RayTracer__PPMImage__

#include <stdio.h>
#include <sstream>
#include <fstream>
#include <iostream>
#include "Color.h"

class PPMImage {
    
public:
    PPMImage(const std::string filename, int w, int h);
    
    void write_header();
    void write_color(Color& pixel_color);
   
private:
    std::string filename;
    std::ofstream file;
    
    int w, h;
    
};


#endif /* defined(__RayTracer__PPMImage__) */
