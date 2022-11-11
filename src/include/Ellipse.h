//
//  Ellipse.h
//  canvas
//
//  Created by Арсений Войкин on 11.11.2022.
//

#ifndef Ellipse_h
#define Ellipse_h

#include <iostream>
#include "Shape.h"
#include "Point.h"

class Ellipse : public Shape {
private:
    Point top_left;
    Point down_right;
    bool filled;
    int outline_color;
public:
    Ellipse(Point top_left, Point down_right, bool filled, int outline_color);
    int* get_coordinates();
    void show();
    std::string get_info();
};

#endif /* Ellipse_h */
