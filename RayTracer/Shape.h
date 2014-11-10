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
        bool intersect_any = false;
        for (auto& shape: shapes) {
            
            if (shape->intersect(i))
                intersect_any = true;
        }
        
        return intersect_any;
    };
    
    void add_shape(Shape* shape);
    void clear_shapes();
    
protected:
    std::list<Shape*> shapes;
    
};

class Plane: public Shape {
    
public:
    Plane(const Point& pos, const Vector& norm, const Color& col);
    
    virtual ~Plane() {};
    
    virtual bool intersect(Intersection& i);
    
protected:
    Point pos;
    Vector norm;
    Color col;
    
};

#endif /* defined(__RayTracer__Shape__) */
