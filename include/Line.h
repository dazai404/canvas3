//
//  Line.h
//  canvas
//
//  Created by Арсений Войкин on 06.11.2022.
//

#ifndef Line_h
#define Line_h

#include <iostream>
#include "Shape.h"
#include "Point.h"

class Line : public Shape
{
private:
    Point a;
    Point b;
public:
    Line();
    Line(Point a, Point b);
    int* get_coordinates();
    void show();
    static double digression(double, double, double, double, int, int);
    std::string get_info();
};

#endif /* Line_h */
