//
//  PPMImage.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 11/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "PPMImage.h"

PPMImage::PPMImage(const std::string filename, int w, int h):
    filename(filename),
    file(filename, std::ios::out | std::ios::binary),
    w(w), h(h) {
    
    write_header();
}

void PPMImage::write_header() {
    std::ostringstream header;
    header << "P6\n";
    header << w << ' ' << h << '\n';
    header << "255\n";
    file << header.str();
}

void PPMImage::write_color(Color& pixel_color) {
    unsigned char r, g, b;
    r = static_cast<unsigned char>(pixel_color.r * 255.0f);
    g = static_cast<unsigned char>(pixel_color.g * 255.0f);
    b = static_cast<unsigned char>(pixel_color.b * 255.0f);
    file << r << g << b;
}