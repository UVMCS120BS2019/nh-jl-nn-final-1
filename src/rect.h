//
// Created by jacel on 4/6/2019.
//

#ifndef GRAPHICS_STARTER_RECT_H
#define GRAPHICS_STARTER_RECT_H

#include "rect.h"

class Rect : public Shape {
private:
    double width;
    double length;
public:
    Rect();
    Rect(double width, double length);
    double get_width() const;
    double get_length() const;

    // must be >= 0
    void set_width(const double& width);
    void set_length(const double& length);

    virtual double get_area() const override;
    virtual double get_perimeter() const override;
    virtual void draw() const override;

    // for overriding <<
    std::ostream& doprint(std::ostream& out) const override;
};

#endif //GRAPHICS_STARTER_RECT_H
