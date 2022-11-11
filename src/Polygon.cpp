//
//  Polygon.cpp
//  canvas
//
//  Created by Арсений Войкин on 06.11.2022.
//

#include <iostream>
#include "../include/Polygon.h"
#include "SFML/Graphics.hpp"

Polygon::Polygon(Point *apexes, int count, bool filled, int outline_color):apexes(apexes), count(count), filled(filled), outline_color(outline_color){}

int* Polygon::get_coordinates() {
    int* data = new int[count*2];
    for (int i = 0; i < count; i ++) {
        int* temp = apexes[i].get_coordinates();
        data[i*2] = temp[0];
        data[i*2+1] = temp[1];
    }
    return data;
}

void Polygon::show() {
//    std::string fild[20][50];
//    for (int i = 0; i < 20; i++) {
//        for (int j = 0; j < 50; j++) {
//            fild[i][j] = "-";
//        }
//    }
//    Point temp1;
//    Point temp2;
//    Line templine;
//    for (int k = 0; k < count; k++) {
//        if (k == count - 1) {
//            temp2 = apexes[count-1];
//            temp1 = apexes[0];
//        } else {
//            temp1 = apexes[k];
//            temp2 = apexes[k+1];
//        }
//        templine = Line(temp1, temp2);
//        double x1 = (double) temp1.get_coordinates()[0];
//        double y1 = (double) temp1.get_coordinates()[1];
//        double x2 = (double) temp2.get_coordinates()[0];
//        double y2 = (double) temp2.get_coordinates()[1];
//        for (int i = 0; i < 20; i++) {
//            for (int j = 0; j < 50; j++) {
//                double dig = Line::digression(x1, y1, x2, y2, i, j);
//                if (dig < 0.5) {
//                    fild[i][j] = "#";
//                    std::cout << "MATCHED!\n";
//                }
//            }
//        }
//    }
//    for (int i = 0; i < 20; i++) {
//        for (int j = 0; j < 50; j++) {
//            std::cout << fild[i][j];
//        }
//        std::cout << "\n";
//    }
    sf::ConvexShape polygon;
    polygon.setPointCount(count);
    Point temp;
    int x, y;
    for (int i = 0; i < count; i++) {
        temp = apexes[i];
        x = temp.get_x();
        y = temp.get_y();
        polygon.setPoint(i, sf::Vector2f(x, y));
    }
    
    polygon.setOutlineThickness(5);
    
    switch (outline_color) {
        case 1:
            polygon.setOutlineColor(sf::Color::Red);
            break;
        case 2:
            polygon.setOutlineColor(sf::Color::Green);
            break;
        case 3:
            polygon.setOutlineColor(sf::Color::Blue);
            break;
        case 4:
            polygon.setOutlineColor(sf::Color::Yellow);
            break;
        default:
            polygon.setOutlineColor(sf::Color::Red);
            break;
    }
    
    if (filled) {
        polygon.setFillColor(sf::Color::White);
    } else {
        polygon.setFillColor(sf::Color::Black);
    }
    
    sf::RenderWindow win(sf::VideoMode(500, 500), "Rendering Polygon");
    
    while (win.isOpen()) {
        sf::Event ev;
        while(win.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) {
                win.close();
            }
        }
        win.clear(sf::Color::Black);
        win.draw(polygon);
        win.display();
    }
    return;
}

std::string Polygon::get_info() {
    std::string info;
    for (int i = 0; i < count; i++) {
        Point temp = apexes[i];
        info += std::to_string(i+1) + " point: " + temp.get_info() + "\n";
    }
    return info;
}
