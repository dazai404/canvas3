//
//  Rectangle.cpp
//  canvas
//
//  Created by Арсений Войкин on 07.11.2022.
//

#include <iostream>
#include "../include/Rectangle.h"
#include "SFML/Graphics.hpp"

Rectangle::Rectangle(Point top_left, Point down_right, bool filled, int outline_color):filled(filled), outline_color(outline_color){
    int x1 = top_left.get_coordinates()[0];
    int y1 = top_left.get_coordinates()[1];
    int x2 = down_right.get_coordinates()[0];
    int y2 = down_right.get_coordinates()[0];
    if (x1 <= x2 && y1 <= y2) {
        this->top_left = top_left;
        this->down_right = down_right;
    } else if (x1 > x2 && y1 > y2) {
        this->top_left = down_right;
        this->down_right = top_left;
    } else if (x1 < x2 && y1 > y2) {
        this->top_left = Point(x2, y1);
        this->down_right = Point(x1, y2);
    } else {
        this->top_left = Point(x1, y2);
        this->down_right = Point(x2, y1);
    }
}

int* Rectangle::get_coordinates() {
    int *data = new int[4];
    int *data_top_left = top_left.get_coordinates();
    int *data_down_right = down_right.get_coordinates();
    data[0] = data_top_left[0];
    data[1] = data_top_left[1];
    data[2] = data_down_right[0];
    data[3] = data_down_right[1];
    return data;
}

void Rectangle::show() {
//    int x1 = top_left.get_coordinates()[0];
//    int y1 = top_left.get_coordinates()[1]+1;
//    int x2 = down_right.get_coordinates()[0];
//    int y2 = down_right.get_coordinates()[1]+1;
//    for (int i = 0; i < 22; i++) {
//        std::cout << "||";
//        for (int j = 0; j < 50; j++) {
//            if (i == 0 || i == 21) {
//                std::cout << "=";
//                continue;
//            }
//            if (i >= y1 && i <= y2 && j >= x1 && j <= x2) {
//                std::cout << "#";
//            } else {
//                std::cout << "-";
//            }
//        }
//        std::cout << "||";
//        std::cout << "\n";
//    }
//    std::cout << "\n";
    
    int x1 = top_left.get_coordinates()[0];
    int y1 = top_left.get_coordinates()[1];
    int x2 = down_right.get_coordinates()[0];
    int y2 = down_right.get_coordinates()[1];
    int len_x = x2-x1;
    int len_y = y2-y1;
    
    sf::RectangleShape rect(sf::Vector2f(len_x, len_y));
    
    rect.setOutlineThickness(5);
    
    switch (outline_color) {
        case 1:
            rect.setOutlineColor(sf::Color::Red);
            break;
        case 2:
            rect.setOutlineColor(sf::Color::Green);
            break;
        case 3:
            rect.setOutlineColor(sf::Color::Blue);
            break;
        case 4:
            rect.setOutlineColor(sf::Color::Yellow);
            break;
        default:
            rect.setOutlineColor(sf::Color::Red);
            break;
    }
    
    if (filled) {
        rect.setFillColor(sf::Color::White);
    } else {
        rect.setFillColor(sf::Color::Black);
    }
    
    rect.setPosition((float) x1, (float) y1);
    
    sf::RenderWindow win(sf::VideoMode(500, 500), "Rendering Rectangle");
    
    while (win.isOpen()) {
        sf::Event ev;
        while(win.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) {
                win.close();
            }
        }
        win.clear();
        win.draw(rect);
        win.display();
    }
    return;
}

std::string Rectangle::get_info() {
    std::string info;
    info = "Top left point: " + top_left.get_info() + "\nDown right point: " + down_right.get_info();
    return info;
}
