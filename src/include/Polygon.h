//
//  Polygon.h
//  canvas
//
//  Created by Арсений Войкин on 06.11.2022.
//

#ifndef Polygon_h
#define Polygon_h

#include <iostream>
#include "Shape.h"
#include "Point.h"
#include "Line.h"

class Polygon : public Shape {
private:
    int count;
    Point *apexes;
    bool filled;
    int outline_color;
public:
    Polygon(Point *apexes, int count, bool filled, int outline_color);
    int* get_coordinates();
    void show();
    std::string get_info();
};

#endif /* Polygon_h */
