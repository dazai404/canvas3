//
//  Point.cpp
//  canvas
//
//  Created by Арсений Войкин on 06.11.2022.
//

#include <iostream>
#include "../include/Point.h"
#include "SFML/Graphics.hpp"

Point::Point():x(0), y(0){}

Point::Point(int x, int y):x(x), y(y){}

int* Point::get_coordinates() {
    int *data = new int[2];
    data[0] = this->x;
    data[1] = this->y;
    return data;
}

void Point::show() {
//    for (int i = 0; i < 22; i++) {
//        std::cout << "||";
//        for (int j = 0; j < 50; j++) {
//            if (i == 0 || i == 21) {
//                std::cout << "=";
//                continue;
//            }
//            if (x == j && y+1 == i) {
//                std::cout << "#";
//            } else {
//                std::cout << "-";
//            }
//        }
//        std::cout << "||";
//        std::cout << "\n";
//    }
//    std::cout << "\n";
    sf::CircleShape point;
    point.setPosition((float) x, (float) y);
    point.setRadius(3);
    sf::RenderWindow win(sf::VideoMode(500, 500), "Rendering Point");
    while (win.isOpen()) {
        sf::Event ev;
        while(win.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) {
                win.close();
            }
        }
        win.clear(sf::Color::Black);
        win.draw(point);
        win.display();
    }
    return;
}

int Point::get_x() {
    return x;
}

int Point::get_y() {
    return y;
}

std::string Point::get_info() {
    std::string info;
    info = "(x = " + std::to_string(x) + ", y = " + std::to_string(y) + ")";
    return info;
}
