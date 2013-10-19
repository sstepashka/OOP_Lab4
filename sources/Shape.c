#include "Shape.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getX(Shape *self) {
    return self->x;
}

void setX(Shape *self, int x) {
    self->x = x;
}

int getY(Shape *self) {
    return self->y;
}

void setY(Shape *self, int y) {
    self->y = y;
}

void move(Shape *self, int x, int y) {
    self->setX(self, self->getX(self) + x);
    self->setY(self, self->getY(self) + y);
}

void print(Shape *self) {
    printf("Shape %i, %i;\n", self->getX(self), self->getX(self));
}

void initShape(Shape *shape, int x, int y)
{
    shape->move = &move;
    shape->print = &print;

    shape->x = x;
    shape->y = y;

    shape->getX = &getX;
    shape->getY = &getY;

    shape->setX = &setX;
    shape->setY = &setY;
}

Shape *newShape(int x, int y) {
    Shape *shape = (Shape *)malloc(sizeof(Shape));

    initShape(shape, x, y);

    return shape;
}
