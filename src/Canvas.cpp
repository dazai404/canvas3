//
//  Canvas.cpp
//  canvas
//
//  Created by Арсений Войкин on 11.11.2022.
//

#include <stdio.h>
#include "../include/Canvas.h"

Canvas::Canvas() {
    points;
    lines;
    rectangles;
    polygons;
    ellipses;
}

Canvas::~Canvas() {
    points.clear();
    lines.clear();
    rectangles.clear();
    polygons.clear();
    ellipses.clear();
}

void Canvas::append(Point val) {
    points.push_back(val);
}

void Canvas::append(Line val) {
    lines.push_back(val);
}

void Canvas::append(Rectangle val) {
    rectangles.push_back(val);
}

void Canvas::append(Polygon val) {
    polygons.push_back(val);
}

void Canvas::append(Ellipse val) {
    ellipses.push_back(val);
}

std::vector<Point> Canvas::get_points() {
    return points;
}

std::vector<Line> Canvas::get_lines() {
    return lines;
}

std::vector<Rectangle> Canvas::get_rectangles() {
    return rectangles;
}

std::vector<Ellipse> Canvas::get_ellipses() {
    return ellipses;
}

std::vector<Polygon> Canvas::get_polygons() {
    return polygons;
}

void Canvas::delete_point(int i) {
    points.erase(points.begin() + i);
}

void Canvas::delete_line(int i) {
    lines.erase(lines.begin() + i);
}

void Canvas::delete_rectangle(int i) {
    rectangles.erase(rectangles.begin() + i);
}

void Canvas::delete_polygon(int i) {
    polygons.erase(polygons.begin() + i);
}

void Canvas::delete_ellipse(int i) {
    ellipses.erase(ellipses.begin() + i);
}

void Canvas::clear() {
    points.clear();
    lines.clear();
    rectangles.clear();
    polygons.clear();
    ellipses.clear();
}
