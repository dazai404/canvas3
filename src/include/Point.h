//
//  Point.h
//  canvas
//
//  Created by Арсений Войкин on 06.11.2022.
//

#ifndef Point_h
#define Point_h

#include <iostream>
#include "Shape.h"

class Point : public Shape
{
private:
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    int* get_coordinates();
    void show();
    int get_x();
    int get_y();
    std::string get_info();
};

#endif /* Point_h */
