//
//  Shape.cpp
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#include "Shape.h"

void ShapeSet::add_shape(Shape *shape) {
    shapes.push_back(shape);
}

void ShapeSet::clear_shapes() {
    shapes.clear();
}