//
// Created by jacel on 4/6/2019.
//

#ifndef GRAPHICS_STARTER_CIRCLE_H
#define GRAPHICS_STARTER_CIRCLE_H

#include "shapes.h"
#include <iostream>
#include "graphics.h"

class Circle : public Shape {

    private:
        double radius;
    public:
        Circle();
        Circle(double radius);

        int getRadius() const;

        // must be >= 0
        void setRadius(int radius);

        virtual void draw() const override;
        // for overriding << operator
        std::ostream& doprint(std::ostream& out) const override;
};



#endif //GRAPHICS_STARTER_CIRCLE_H
