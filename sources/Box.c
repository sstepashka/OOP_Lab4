#include "Box.h"
#include "Rect.h"

#include <stdlib.h>
#include <stdio.h>

void printBox (Box *box) {
    printf("Box X = %i, Y = %i, S = %i;\n", box->getX(box), box->getY(box), box->getW(box));
}

void initBox(Box *box, int x, int y, int s) {
    Rect *rect = (Rect*)box;
    initRect(rect, x, y, s, s);

    rect->getW = &getW;
    rect->getH = &getW;

    rect->setW = &setW;
    rect->setH = &setW;

    box->print = &printBox;
}

Box *newBox(int x, int y, int s) {
    Box *box = (Box *)malloc(sizeof(Box));

    initBox(box, x, y, s);

    return box;
}
