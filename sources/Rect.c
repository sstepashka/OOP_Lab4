#include "Rect.h"
#include "Shape.h"

#include <stdlib.h>
#include <stdio.h>

void printRect (Rect *rect) {
    printf("Rect X = %i, Y = %i, W = %i, H = %i;\n", rect->getX(rect), rect->getY(rect), rect->getW(rect), rect->getH(rect));
}

void initRect(Rect *rect, int x, int y, int w, int h) {
    Shape *shape = (Shape *)rect;
    initShape(shape, x, y);

    rect->getW = &getW;
    rect->getH = &getH;
    rect->setW = &setW;
    rect->setH = &setH;

    rect->w = w;
    rect->h = h;

    rect->print = &printRect;
}

Rect *newRect(int x, int y, int w, int h) {
    Rect *rect = (Rect *)malloc(sizeof(Rect));

    initRect(rect, x, y, w, h);

    return rect;
}

int getW(Rect *self) {
    return self->w;
}

void setW(Rect *self, int w) {
    self->w = w;
}

int getH(Rect *self) {
    return self->h;
}

void setH(Rect *self, int h) {
    self->h = h;
}
