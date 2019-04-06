//
// Created by jacel on 4/6/2019.
//

#ifndef GRAPHICS_STARTER_CIRCLE_H
#define GRAPHICS_STARTER_CIRCLE_H

#include "shapes.h"
#include <iostream>

class Circle : public Shape {

    private:
        double radius;
    public:
        Circle();
        Circle(double radius);

        int get_radius() const;

        // must be >= 0
        void set_radius(int radius);

        virtual double get_area() const override;
        virtual double get_perimeter() const override;
        virtual void draw() const override;
        // for overriding << operator
        std::ostream& doprint(std::ostream& out) const override;
};



#endif //GRAPHICS_STARTER_CIRCLE_H
