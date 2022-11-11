//
//  main.cpp
//  canvas
//
//  Created by Арсений Войкин on 06.11.2022.
//

#include <iostream>

#include "include/Point.h"
#include "include/Line.h"
#include "include/Polygon.h"
#include "include/Rectangle.h"
#include "include/Ellipse.h"
#include "include/Canvas.h"

void print_coordinates(int *arr, int num) {
    num *= 2;
    for (int i = 0; i < num; i++) {
        std::cout << arr[i] << " ";
        if (i % 2 == 1) {
            std::cout << "\n";
        }
    }
    std::cout << "\n";
}

void menu_create_point(Canvas *canvas) {
    int x, y;
    std::cout << "----- CREATING A POINT -----\nEnter x, y: ";
    std::cin >> x >> y;
    Point point(x, y);
    canvas->append(point);
    std::cout << "----- SUCCESS -----\n\n";
    return;
}

void menu_create_line(Canvas *canvas) {
    int x, y;
    std::cout << "---- CREATING A LINE -----\nEnter x, y for first point: ";
    std::cin >> x >> y;
    Point first_point(x, y);
    std::cout << "Enter x, y for second point: ";
    std::cin >> x >> y;
    Point second_point(x, y);
    Line line(first_point, second_point);
    canvas->append(line);
    std::cout << "----- SUCCESS -----\n\n";
}

void menu_create_rectangle(Canvas *canvas) {
    int x, y;
    std::cout << "----- CREATING A RECTANGLE -----\nEnter x, y for first point: ";
    std::cin >> x >> y;
    Point first_point(x, y);
    std::cout << "Enter x, y for second point: ";
    std::cin >> x >> y;
    Point second_point(x, y);
    bool flag = true;
    int filling = 0;
    std::cout << "Press 1 to fill rectangle and 0 to keep it clear: ";
    while (flag) {
        std::cin >> filling;
        switch (filling) {
            case 1:
                flag = false;
                break;
            case 0:
                flag = false;
                break;
            default:
                std::cout << "Uncorrect number. Try again: ";
                break;
        }
    }
    bool fill;
    if (filling == 1) {
        fill = true;
    } else {
        fill = false;
    }
    std::cout << "Choose a color of outline: \n1.Red\n2.Green\n3.Blue\n4.Yellow\n";
    int color = 1;
    flag = true;
    while (flag) {
        std::cout << "> ";
        std::cin >> color;
        switch (color) {
            case 1:
                flag = false;
                break;
            case 2:
                flag = false;
                break;
            case 3:
                flag = false;
                break;
            case 4:
                flag = false;
                break;
            default:
                std::cout << "Uncorrect number. Try again: ";
                break;
        }
    }
    Rectangle rectangle(first_point, second_point, fill, color);
    canvas->append(rectangle);
    std::cout << "----- SUCCESS -----\n\n";
}

void menu_create_ellipse(Canvas *canvas) {
    int x, y;
    std::cout << "----- CREATING AN ELLIPSE -----\nEnter x, y for first point: ";
    std::cin >> x >> y;
    Point first_point(x, y);
    std::cout << "Enter x, y for second point: ";
    std::cin >> x >> y;
    Point second_point(x, y);
    bool flag = true;
    int filling = 0;
    std::cout << "Press 1 to fill ellipse and 0 to keep it clear: ";
    while (flag) {
        std::cin >> filling;
        switch (filling) {
            case 1:
                flag = false;
                break;
            case 0:
                flag = false;
                break;
            default:
                std::cout << "Uncorrect number. Try again: ";
                break;
        }
    }
    bool fill;
    if (filling == 1) {
        fill = true;
    } else {
        fill = false;
    }
    std::cout << "Choose a color of outline: \n1.Red\n2.Green\n3.Blue\n4.Yellow\n";
    int color = 1;
    flag = true;
    while (flag) {
        std::cout << "> ";
        std::cin >> color;
        switch (color) {
            case 1:
                flag = false;
                break;
            case 2:
                flag = false;
                break;
            case 3:
                flag = false;
                break;
            case 4:
                flag = false;
                break;
            default:
                std::cout << "Uncorrect number. Try again: ";
                break;
        }
    }
    Ellipse ellipse(first_point, second_point, fill, color);
    canvas->append(ellipse);
    std::cout << "----- SUCCESS -----\n\n";
}

void menu_create_polygon(Canvas *canvas) {
    std::cout << "----- CREATING A POLYGON -----\nEnter a number of vertexes: ";
    int count;
    std::cin >> count;
    Point *apexes = new Point;
    for (int i = 0; i < count; i++) {
        int x, y;
        std::cout << "Enter x, y: ";
        std::cin >> x >> y;
        apexes[i] = Point(x, y);
    }
    bool flag = true;
    int filling = 0;
    std::cout << "Press 1 to fill polygon and 0 to keep it clear: ";
    while (flag) {
        std::cin >> filling;
        switch (filling) {
            case 1:
                flag = false;
                break;
            case 0:
                flag = false;
                break;
            default:
                std::cout << "Uncorrect number. Try again: ";
                break;
        }
    }
    bool fill;
    if (filling == 1) {
        fill = true;
    } else {
        fill = false;
    }
    std::cout << "Choose a color of outline: \n1.Red\n2.Green\n3.Blue\n4.Yellow\n";
    int color = 1;
    flag = true;
    while (flag) {
        std::cout << "> ";
        std::cin >> color;
        switch (color) {
            case 1:
                flag = false;
                break;
            case 2:
                flag = false;
                break;
            case 3:
                flag = false;
                break;
            case 4:
                flag = false;
                break;
            default:
                std::cout << "Uncorrect number. Try again: ";
                break;
        }
    }
    Polygon polygon(apexes, count, fill, color);
    canvas->append(polygon);
    std::cout << "----- SUCCESS -----\n\n";
}

void menu_get_info(Canvas canvas) {
    std::cout << "----- ALL INFORMATION -----\n";
    bool flag = false;
    for (int i = 0; i < canvas.get_points().size(); i++) {
        flag = true;
        std::cout << "Single point: " << canvas.get_points()[i].get_info() << "\n";
        if (i == canvas.get_points().size() - 1) {
            std::cout << "\n";
        }
    }
    for (int i = 0; i < canvas.get_lines().size(); i++) {
        flag = true;
        std::cout << "Line:\n" << canvas.get_lines()[i].get_info() << "\n";
        if (i == canvas.get_lines().size() - 1) {
            std::cout << "\n";
        }
    }
    for (int i = 0; i < canvas.get_rectangles().size(); i++) {
        flag = true;
        std::cout << "Rectangle:\n" << canvas.get_rectangles()[i].get_info() << "\n";
        if (i == canvas.get_rectangles().size() - 1) {
            std::cout << "\n";
        }
    }
    for (int i = 0; i < canvas.get_polygons().size(); i++) {
        flag = true;
        std::cout << "Polygon:\n" << canvas.get_polygons()[i].get_info() << "\n";
    }
    for (int i = 0; i < canvas.get_ellipses().size(); i++) {
        flag = true;
        std::cout << "Ellipse:\n" << canvas.get_ellipses()[i].get_info() << "\n";
        if (i == canvas.get_ellipses().size() - 1) {
            std::cout << "\n";
        }
    }
    if (flag) {
        std::cout << "----- IT`S ALL -----\n\n";
    } else {
        std::cout << "----- IT`S NOTHING TO PRINT -----\n\n";
    }
}

void menu_render_point(Canvas canvas) {
    if (canvas.get_points().size() == 0) {
        std::cout << "----- IT`S NOTHING TO RENDER -----\n\n";
        return;
    }
    std::cout << "----- RENDERING A POINT -----\n";
    for (int i = 0; i < canvas.get_points().size(); i++) {
        std::cout << i+1 << ". Point: " << canvas.get_points()[i].get_info() << "\n";
    }
    std::cout << "Select a point: ";
    int num;
    while (true) {
        std::cin >> num;
        if (num > 0 && num < canvas.get_points().size() + 1) {
            break;
        } else {
            std::cout << "Uncorrect number. Try again: ";
        }
    }
    canvas.get_points()[num-1].show();
    std::cout << "----- SUCCESS -----\n\n";
}

void menu_render_line(Canvas canvas) {
    if (canvas.get_lines().size() == 0) {
        std::cout << "----- IT`S NOTHING TO RENDER -----\n\n";
        return;
    }
    std::cout << "----- RENDERING A LINE -----\n";
    for (int i = 0; i < canvas.get_lines().size(); i++) {
        std::cout << i+1 << ". Line:\n" << canvas.get_lines()[i].get_info() << "\n";
    }
    std::cout << "Select a line: ";
    int num;
    while (true) {
        std::cin >> num;
        if (num > 0 && num < canvas.get_lines().size() + 1) {
            break;
        } else {
            std::cout << "Uncorrect number. Try again: ";
        }
    }
    canvas.get_lines()[num-1].show();
    std::cout << "----- SUCCESS -----\n\n";
}

void menu_render_rectangle(Canvas canvas) {
    if (canvas.get_rectangles().size() == 0) {
        std::cout << "----- IT`S NOTHING TO RENDER -----\n\n";
        return;
    }
    std::cout << "----- RENDERING A RECTANGLE -----\n";
    for (int i = 0; i < canvas.get_rectangles().size(); i++) {
        std::cout << i+1 << ". Rectangle:\n" << canvas.get_rectangles()[i].get_info() << "\n";
    }
    std::cout << "Select a rectangle: ";
    int num;
    while (true) {
        std::cin >> num;
        if (num > 0 && num < canvas.get_rectangles().size() + 1) {
            break;
        } else {
            std::cout << "Uncorrect number. Try again: ";
        }
    }
    canvas.get_rectangles()[num-1].show();
    std::cout << "----- SUCCESS -----\n\n";
}

void menu_render_polygon(Canvas canvas) {
    if (canvas.get_polygons().size() == 0) {
        std::cout << "----- IT`S NOTHING TO RENDER -----\n\n";
        return;
    }
    std::cout << "----- RENDERING A POLYGON -----\n";
    for (int i = 0; i < canvas.get_polygons().size(); i++) {
        std::cout << i+1 << ". Polygon:\n" << canvas.get_polygons()[i].get_info() << "\n";
    }
    std::cout << "Select a polygon: ";
    int num;
    while (true) {
        std::cin >> num;
        if (num > 0 && num < canvas.get_polygons().size() + 1) {
            break;
        } else {
            std::cout << "Uncorrect number. Try again: ";
        }
    }
    canvas.get_polygons()[num-1].show();
    std::cout << "----- SUCCESS -----\n\n";
}

void menu_render_ellipse(Canvas canvas) {
    if (canvas.get_ellipses().size() == 0) {
        std::cout << "----- IT`S NOTHING TO RENDER -----\n\n";
        return;
    }
    std::cout << "----- RENDERING A ELLIPSE -----\n";
    for (int i = 0; i < canvas.get_ellipses().size(); i++) {
        std::cout << i+1 << ". Ellipse:\n" << canvas.get_ellipses()[i].get_info() << "\n";
    }
    std::cout << "Select an ellipse: ";
    int num;
    while (true) {
        std::cin >> num;
        if (num > 0 && num < canvas.get_ellipses().size() + 1) {
            break;
        } else {
            std::cout << "Uncorrect number. Try again: ";
        }
    }
    canvas.get_ellipses()[num-1].show();
    std::cout << "----- SUCCESS -----\n\n";
}

void menu_remove_point(Canvas *canvas) {
    if (canvas->get_points().size() == 0) {
        std::cout << "----- IT`S NOTHING TO REMOVE -----\n\n";
        return;
    }
    std::cout << "----- REMOVING A POINT -----\n";
    for (int i = 0; i < canvas->get_points().size(); i++) {
        std::cout << i+1 << ". Point: " << canvas->get_points()[i].get_info() << "\n";
    }
    std::cout << "Select a point: ";
    int num;
    while (true) {
        std::cin >> num;
        if (num > 0 && num < canvas->get_points().size() + 1) {
            break;
        } else {
            std::cout << "Uncorrect number. Try again: ";
        }
    }
    canvas->delete_point(num-1);
    std::cout << "----- SUCCESS -----\n\n";
}

void menu_remove_line(Canvas *canvas) {
    if (canvas->get_lines().size() == 0) {
        std::cout << "----- IT`S NOTHING TO REMOVE -----\n\n";
        return;
    }
    std::cout << "----- REMOVING A LINE -----\n";
    for (int i = 0; i < canvas->get_lines().size(); i++) {
        std::cout << i+1 << ". Line:\n" << canvas->get_lines()[i].get_info() << "\n";
    }
    std::cout << "Select a line: ";
    int num;
    while (true) {
        std::cin >> num;
        if (num > 0 && num < canvas->get_lines().size() + 1) {
            break;
        } else {
            std::cout << "Uncorrect number. Try again: ";
        }
    }
    canvas->delete_line(num-1);
    std::cout << "----- SUCCESS -----\n\n";
}

void menu_remove_rectangle(Canvas *canvas) {
    if (canvas->get_rectangles().size() == 0) {
        std::cout << "----- IT`S NOTHING TO REMOVE -----\n\n";
        return;
    }
    std::cout << "----- REMOVING A RECTANGLE -----\n";
    for (int i = 0; i < canvas->get_rectangles().size(); i++) {
        std::cout << i+1 << ". Rectangle:\n" << canvas->get_rectangles()[i].get_info() << "\n";
    }
    std::cout << "Select a rectangle: ";
    int num;
    while (true) {
        std::cin >> num;
        if (num > 0 && num < canvas->get_rectangles().size() + 1) {
            break;
        } else {
            std::cout << "Uncorrect number. Try again: ";
        }
    }
    canvas->delete_rectangle(num-1);
    std::cout << "----- SUCCESS -----\n\n";
}

void menu_remove_polygon(Canvas *canvas) {
    if (canvas->get_polygons().size() == 0) {
        std::cout << "----- IT`S NOTHING TO REMOVE -----\n\n";
        return;
    }
    std::cout << "----- REMOVING A POLYGON -----\n";
    for (int i = 0; i < canvas->get_polygons().size(); i++) {
        std::cout << i+1 << ". Polygon:\n" << canvas->get_polygons()[i].get_info() << "\n";
    }
    std::cout << "Select a polygon: ";
    int num;
    while (true) {
        std::cin >> num;
        if (num > 0 && num < canvas->get_polygons().size() + 1) {
            break;
        } else {
            std::cout << "Uncorrect number. Try again: ";
        }
    }
    canvas->delete_polygon(num-1);
    std::cout << "----- SUCCESS -----\n\n";
}

void menu_remove_ellipse(Canvas *canvas) {
    if (canvas->get_ellipses().size() == 0) {
        std::cout << "----- IT`S NOTHING TO REMOVE -----\n\n";
        return;
    }
    std::cout << "----- REMOVING A ELLIPSE -----\n";
    for (int i = 0; i < canvas->get_ellipses().size(); i++) {
        std::cout << i+1 << ". Ellipse:\n" << canvas->get_ellipses()[i].get_info() << "\n";
    }
    std::cout << "Select an ellipse: ";
    int num;
    while (true) {
        std::cin >> num;
        if (num > 0 && num < canvas->get_ellipses().size() + 1) {
            break;
        } else {
            std::cout << "Uncorrect number. Try again: ";
        }
    }
    canvas->delete_ellipse(num-1);
    std::cout << "----- SUCCESS -----\n\n";
}

int menu() {
    std::cout << "0. Exit\n1. Create a point\n2. Create a line\n3. Create a rectangle\n4. Create a polygon\n5. Create an ellipse\n6. Show list\n7. Render a point\n8. Render a line\n9. Render a rectangle\n10. Render a polygon\n11. Render an ellipse\n12. Remove a point\n13. Remove a line\n14. Remove a rectangle\n15. Remove a polygon\n16. Remove an ellipse\n\nSelect a command\n> ";
    int num;
    std::cin >> num;
    return num;
}

int main() {
    std::cout << "----- WELCOME -----\n\n";
    Canvas canvas;
    bool flag = true;
    while (flag) {
        switch (menu()) {
            case 0:
                std::cout << "----- SEE YA -----\n";
                flag = false;
                break;
            case 1:
                menu_create_point(&canvas);
                break;
            case 2:
                menu_create_line(&canvas);
                break;
            case 3:
                menu_create_rectangle(&canvas);
                break;
            case 4:
                menu_create_polygon(&canvas);
                break;
            case 5:
                menu_create_ellipse(&canvas);
                break;
            case 6:
                menu_get_info(canvas);
                break;
            case 7:
                menu_render_point(canvas);
                break;
            case 8:
                menu_render_line(canvas);
                break;
            case 9:
                menu_render_rectangle(canvas);
                break;
            case 10:
                menu_render_polygon(canvas);
                break;
            case 11:
                menu_render_ellipse(canvas);
                break;
            case 12:
                menu_remove_point(&canvas);
                break;
            case 13:
                menu_remove_line(&canvas);
                break;
            case 14:
                menu_remove_rectangle(&canvas);
                break;
            case 15:
                menu_remove_polygon(&canvas);
                break;
            case 16:
                menu_remove_ellipse(&canvas);
                break;
            default:
                break;
        }
    }
}
