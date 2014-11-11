//
//  main.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>

#include "RayTracer.h"
#include "PPMImage.h"

// Shapes
#include "Sphere.h"
#include "Plane.h"

// Lights
#include "RectangleLight.h"

int main(int argc, const char * argv[]) {
    
    ShapeSet scene;
    RayTracer raytracer(scene, 512, 512, 12);
    
    Plane plane(Point(0.0f, -2.0f, 0.0f),
                Vector(0.0f, 1.0f, 0.0f),
                Color(1.0f, 0.5f, 0.8f), true);
    
    scene.add_shape(&plane);
    
    Sphere sphere(Point(0.0f, -2.0f, 0.0f),
                  Vector(0.0f, 1.0f, 0.0f),
                  Color(1.0f, 0.3f, 0.3f),1.0);
    
    scene.add_shape(&sphere);
    
    RectangleLight areaLight(Point(-2.5f, 2.0f, -2.5f),
                             Vector(5.0f, 0.0f, 0.0f),
                             Vector(0.0f, 0.0f, 5.0f),
                             Color(1.0f, 0.5f, 1.0f),
                             3.0f);
    scene.add_shape(&areaLight);
    
    // Add another area light below it, darker, that will make a shadow too.
    RectangleLight smallAreaLight(Point(-2.0f, -1.0f, -2.0f),
                                  Vector(4.0f, 0.0f, 0.0f),
                                  Vector(0.0f, 0.0f, 4.0f),
                                  Color(1.0f, 1.0f, 0.5f),
                                  0.75f);
    scene.add_shape(&smallAreaLight);
   
    raytracer.draw();
}
