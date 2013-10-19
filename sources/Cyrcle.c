#include "Cyrcle.h"
#include "Shape.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void printCyrcle (Cyrcle *cyrcle) {
    printf("Cyrcle X = %i, Y = %i, R = %i;\n", cyrcle->getX(cyrcle), cyrcle->getY(cyrcle), cyrcle->getR(cyrcle));
}

int getR(Cyrcle *self) {
    return self->r;
}

void setR(Cyrcle *self, int r){
    self->r = r;
}

void initCyrcle(Cyrcle *cyrcle, int x, int y, int r) {
    Shape *shape = (Shape *)cyrcle;
    initShape(shape, x, y);

    cyrcle->getR = &getR;
    cyrcle->setR = &setR;

    cyrcle->r = r;
    cyrcle->print = &printCyrcle;
}

Cyrcle *newCyrcle(int x, int y, int r) {
    Cyrcle *cyrcle = (Cyrcle *)malloc(sizeof(Cyrcle));
    memset(cyrcle, 0, sizeof(Cyrcle));

    initCyrcle(cyrcle, x, y, r);

    return cyrcle;
}
