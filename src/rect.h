//
// Created by jacel on 4/6/2019.
//

#ifndef GRAPHICS_STARTER_RECT_H
#define GRAPHICS_STARTER_RECT_H

#include "shapes.h"
#include "rect.h"

class Rect : public Shape {
private:
    double width;
    double height;
public:
    Rect();
    Rect(double width, double height);
    double getWidth() const;
    double getLength() const;

    // must be >= 0
    void setWidth(const double& width);
    void setLength(const double& height);

    virtual void draw() const override;

    // for overriding <<
    std::ostream& doprint(std::ostream& out) const override;
};

#endif //GRAPHICS_STARTER_RECT_H
