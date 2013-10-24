#include "Composite.h"
#include "Shape.h"
#include <stdlib.h>
#include <stdio.h>

void moveComposite(Composite *self, int x, int y) {
    self->setX(self, self->getX(self) + x);
    self->setY(self, self->getY(self) + y);

    for (int i = 0; i < 255; i++) {
        ArrayElement *element = self->array[i];
        if (element->shape) {
            element->shape->move(element->shape, x, y);
        }
    }
}

void printComposite(Composite *self) {
    printf("Begin Composite X = %i, Y = %i;\n", self->getX(self), self->getY(self));

    for (int i = 0; i < 255; i++) {
        ArrayElement *element = self->array[i];
        if (element->shape) {
            element->shape->print(element->shape);
        }
    }

    printf("End Composite X = %i, Y = %i;\n", self->getX(self), self->getY(self));
}

void addShape(Composite *composite, Shape *shape) {
    for (int i = 0; i < 255; i++) {
        ArrayElement *element = composite->array[i];
        if (!element->shape) {
            element->shape = shape;
            break;
        }
    }
}

void removeShape(Composite *composite, Shape *shape) {
    for (int i = 0; i < 255; i++) {
        ArrayElement *element = composite->array[i];
        if (element->shape == shape) {
            element->shape = 0;
            break;
        }
    }
}

Composite *newComposite(int x, int y) {
    Composite *composite = (Composite *)malloc(sizeof(Composite));
    Shape *shape = (Shape *)composite;

    initShape(shape, x, y);

    composite->array = (ArrayElement **)malloc(sizeof(ArrayElement *) * 255);

    for (int i = 0; i < 255; ++i)
    {
        ArrayElement *element = (ArrayElement *)malloc(sizeof(ArrayElement));
        element->shape = 0;
        composite->array[i] = element;
    }

    composite->print = &printComposite;
    composite->addShape = &addShape;
    composite->removeShape = &removeShape;
    composite->move = &moveComposite;

    return composite;
}

void eraseComposite(Composite *composite) {

    for (int i = 0; i < 255; ++i)
    {
        free(composite->array[i]);
    }

    free(composite->array);
}
