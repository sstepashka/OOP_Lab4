#include "Composite.h"
#include "Shape.h"
#include <stdlib.h>
#include <stdio.h>

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

    return composite;
}

void eraseComposite(Composite *composite) {

    for (int i = 0; i < 255; ++i)
    {
        free(composite->array[i]);
    }

    free(composite->array);
}
