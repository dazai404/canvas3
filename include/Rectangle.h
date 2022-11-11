//
//  Header.h
//  canvas
//
//  Created by Арсений Войкин on 07.11.2022.
//

#ifndef Rectangle_h
#define Rectangle_h

#include <iostream>
#include "Shape.h"
#include "Point.h"

class Rectangle : public Shape {
private:
    Point top_left;
    Point down_right;
    bool filled;
    int outline_color;
public:
    Rectangle(Point top_left, Point down_right, bool filled, int outline_color);
    int* get_coordinates();
    void show();
    std::string get_info();
};


#endif /* Rectangle_h */
