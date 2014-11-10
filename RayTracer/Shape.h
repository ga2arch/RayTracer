//
//  Shape.h
//  RayTracer
//
//  Created by Gabriele Carrettoni on 10/11/14.
//  Copyright (c) 2014 Gabriele Carrettoni. All rights reserved.
//

#ifndef __RayTracer__Shape__
#define __RayTracer__Shape__

#include <stdio.h>
#include <list>
#include "Vector.h"
#include "Ray.h"
#include "Intersection.h"


class Shape {
    
public:
    virtual ~Shape() {};
    
    virtual bool intersect(Intersection& i) = 0;
};

class ShapeSet: public Shape {
    
public:
    virtual ~ShapeSet() {};
    
    virtual bool intersect(Intersection& i) {
        for (auto& shape: shapes) {
            
            if (shape->intersect(i))
                return true;
        }
        
        return false;
    };
    
    void add_shape(Shape* shape);
    void clear_shapes();
    
protected:
    std::list<Shape*> shapes;
    
};

#endif /* defined(__RayTracer__Shape__) */
