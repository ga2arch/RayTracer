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
    
    virtual bool sample_surface(float u1,
                                float u2,
                                const Point& ref_point,
                                Point& out_pos,
                                Vector& out_normal) {
        return false;
    };
    
    virtual void find_lights(std::list<Shape*>& out_lights) {};
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
    
    virtual void find_lights(std::list<Shape*>& out_lights) {
        
        for (Shape* shape: shapes) {
            shape->find_lights(out_lights);
        }

    };

    
    void add_shape(Shape* shape);
    void clear_shapes();
    
protected:
    std::list<Shape*> shapes;
    
};

#endif /* defined(__RayTracer__Shape__) */
