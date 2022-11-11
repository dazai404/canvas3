//
//  Shape.h
//  canvas
//
//  Created by Арсений Войкин on 06.11.2022.
//

#ifndef Shape_h
#define Shape_h

class Shape {
public:
    virtual int* get_coordinates();
    virtual void show();
    virtual std::string get_info();
};

#endif /* Shape_h */
