//
//  Ellipse.cpp
//  canvas
//
//  Created by Арсений Войкин on 11.11.2022.
//

#define PI 3.1415926535898

#include <iostream>
#include "../include/Ellipse.h"
#include "SFML/Graphics.hpp"
#include <cmath>

Ellipse::Ellipse(Point top_left, Point down_right, bool filled, int outline_color):filled(filled), outline_color(outline_color){
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

int* Ellipse::get_coordinates() {
    int *data = new int[4];
    int *data_top_left = top_left.get_coordinates();
    int *data_down_right = down_right.get_coordinates();
    data[0] = data_top_left[0];
    data[1] = data_top_left[1];
    data[2] = data_down_right[0];
    data[3] = data_down_right[1];
    return data;
}

void Ellipse::show() {
    int x1 = top_left.get_coordinates()[0];
    int y1 = top_left.get_coordinates()[1];
    int x2 = down_right.get_coordinates()[0];
    int y2 = down_right.get_coordinates()[1];
    int len_x = x2-x1;
    int len_y = y2-y1;
    
    int quality = 350;
    sf::ConvexShape ellipse;
    ellipse.setPointCount(quality);
    for(unsigned short i=0;i<quality;++i){
        float rad=(360/quality*i)/(360/PI/2);
        float x=cos(rad)*len_x/2;
        float y=sin(rad)*len_y/2;

        ellipse.setPoint(i,sf::Vector2f(x,y));
    };
    
    ellipse.setOutlineThickness(5);
    
    if (filled) {
        ellipse.setFillColor(sf::Color::White);
    } else {
        ellipse.setFillColor(sf::Color::Black);
    }
    
    switch (outline_color) {
        case 1:
            ellipse.setOutlineColor(sf::Color::Red);
            break;
        case 2:
            ellipse.setOutlineColor(sf::Color::Green);
            break;
        case 3:
            ellipse.setOutlineColor(sf::Color::Blue);
            break;
        case 4:
            ellipse.setOutlineColor(sf::Color::Yellow);
            break;
        default:
            ellipse.setOutlineColor(sf::Color::Red);
            break;
    }
    
    ellipse.setPosition(top_left.get_x()+len_x/2, top_left.get_y()+len_y/2);
    
    sf::RenderWindow win(sf::VideoMode(500, 500), "Rendering Ellipse");
    
    while (win.isOpen()) {
        sf::Event ev;
        while(win.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) {
                win.close();
            }
        }
        win.clear();
        win.draw(ellipse);
        win.display();
    }
    return;
}

std::string Ellipse::get_info() {
    std::string info;
    info = "Top left point: " + top_left.get_info() + "\nDown right point: " + down_right.get_info();
    return info;
}
