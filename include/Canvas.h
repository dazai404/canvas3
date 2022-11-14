//
//  Canvas.h
//  canvas
//
//  Created by Арсений Войкин on 11.11.2022.
//

#ifndef Canvas_h
#define Canvas_h

#include <iostream>
#include <vector>

#include "Point.h"
#include "Line.h"
#include "Rectangle.h"
#include "Polygon.h"
#include "Ellipse.h"

class Canvas {
private:
    std::vector<Point> points;
    std::vector<Line> lines;
    std::vector<Rectangle> rectangles;
    std::vector<Polygon> polygons;
    std::vector<Ellipse> ellipses;
public:
    Canvas();
    ~Canvas();
    void append(Point point);
    void append(Line line);
    void append(Rectangle rectangle);
    void append(Polygon polygon);
    void append(Ellipse ellipse);
    std::vector<Point> get_points();
    std::vector<Line> get_lines();
    std::vector<Rectangle> get_rectangles();
    std::vector<Polygon> get_polygons();
    std::vector<Ellipse> get_ellipses();
    void delete_point(int i);
    void delete_line(int i);
    void delete_rectangle(int i);
    void delete_polygon(int i);
    void delete_ellipse(int i);
    void clear();
};


#endif /* Canvas_h */
