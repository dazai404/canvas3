//
//  Line.cpp
//  canvas
//
//  Created by Арсений Войкин on 06.11.2022.
//

#include <iostream>
#include <cmath>
#include "../include/Line.h"
#include "SFML/Graphics.hpp"

Line::Line():a(Point()), b(Point()){}

Line::Line(Point a, Point b){
    int x1 = a.get_coordinates()[0];
    int y1 = a.get_coordinates()[1];
    int x2 = b.get_coordinates()[0];
    int y2 = b.get_coordinates()[0];
    if (x1 <= x2 && y1 <= y2) {
        this->a = a;
        this->b = b;
    } else if (x1 > x2 && y1 > y2) {
        this->a = b;
        this->b = a;
    } else if (x1 > x2 && y1 < y2) {
        this->a = Point(x2, y1);
        this->b = Point(x1, y2);
    } else {
        this->a = Point(x1, y2);
        this->b = Point(x2, y1);
    }
}

int* Line::get_coordinates() {
    int *data = new int[4];
    int *a = this->a.get_coordinates();
    int *b = this->b.get_coordinates();
    data[0] = a[0];
    data[1] = a[1];
    data[2] = b[0];
    data[3] = b[1];
    return data;
}

double Line::digression(double x1, double y1, double x2, double y2, int in, int jn) {
    double i = (double) in;
    double j = (double) jn;
    double delta_x = x2 - x1;
    double delta_y = y2 - y1;
    double c = -x1 * delta_y + y1*delta_x;
    double norm;
    if (c < 0) {
        norm = 1/sqrt(delta_y*delta_y + delta_x*delta_x);
    } else {
        norm = -1/sqrt(delta_y*delta_y + delta_x*delta_x);
    }
    return abs(j*delta_y*norm - i*delta_x*norm + c*norm);
}

void Line::show() {
//    double x1 = (double) a.get_coordinates()[0];
//    double y1 = (double) a.get_coordinates()[1]+1;
//    double x2 = (double) b.get_coordinates()[0];
//    double y2 = (double) b.get_coordinates()[1]+1;
//    for (int i = 0; i < 22; i++) {
//        std::cout << "||";
//        for (int j = 0; j < 50; j++) {
//            double dig = digression(x1, y1, x2, y2, i, j);
//            if (i == 0 || i == 21) {
//                std::cout << "=";
//                continue;
//            }
//            if (dig < 0.5 && i >= y1 && i <= y2 && j >= x1 && j <= x2) {
//                std::cout << "#";
//            } else {
//                std::cout << "-";
//            }
//        }
//        std::cout << "||";
//        std::cout << "\n";
//    }
//    std::cout << "\n";
    sf::Vertex line[2];
    line[0].position = sf::Vector2f(a.get_coordinates()[0], a.get_coordinates()[1]);
    line[1].position = sf::Vector2f(b.get_coordinates()[0], b.get_coordinates()[1]);
    
    sf::RenderWindow win(sf::VideoMode(500, 500), "Rendering Line");
    while (win.isOpen()) {
        sf::Event ev;
        while(win.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) {
                win.close();
            }
        }
        win.clear(sf::Color::Black);
        win.draw(line, 2, sf::Lines);
        win.display();
    }
    return;
}

std::string Line::get_info() {
    std::string info;
    info = "First point: " + a.get_info() + "\nSecond point: " + b.get_info();
    return info;
}
