#include <stdlib.h>
#include <stdio.h>

#include "Rect.h"
#include "Cyrcle.h"
#include "Shape.h"
#include "Box.h"
#include "Composite.h"

int main (int argc, char *argv[])
{
    printf("\n");

    Cyrcle *cyrcle = newCyrcle(1, 2, 3);
    Cyrcle *cyrcle1 = newCyrcle(3, 3, 5);
    Cyrcle *cyrcle2 = newCyrcle(3, 3, 5);

    Rect *rect = newRect(5, 6, 7, 2);
    Box *box = newBox(1, 6, 4);

    printf("print cyrcle (1 ,2 ,3)\n");
    cyrcle->print(cyrcle);
    printf("\n");

    printf("print cyrcle 1 (3, 3, 5)\n");
    cyrcle1->print(cyrcle1);
    printf("\n");

    printf("print rect (5, 6, 7, 2)\n");
    rect->print(rect);
    printf("\n");

    printf("print box (1, 6, 4)\n");
    box->print(box);
    printf("\n");

    printf("print composite (8, 4) empty\n");
    Composite *composite = newComposite(8, 4);
    composite->print(composite);
    printf("\n");


    composite->addShape(composite, (Shape *)cyrcle);
    composite->addShape(composite, (Shape *)cyrcle1);
    composite->addShape(composite, (Shape *)rect);

    printf("print composite (8, 4) with objects\n");
    composite->print(composite);
    printf("\n");

    Composite *composite1 = newComposite(2, 6);
    composite1->addShape(composite1, (Shape *)box);
    composite1->addShape(composite1, (Shape *)cyrcle2);

    composite->addShape(composite, (Shape *)composite1);

    printf("print composite (8, 4) with composite and objects\n");
    composite->print(composite);
    printf("\n");

    printf("move composite (8, 4) by (10, 10)\n");
    composite->move(composite, 10, 10);
    composite->print(composite);
    printf("\n");

    printf("move previous composite (8, 4) by (-10, -10)\n");
    composite->move(composite, -10, -10);
    composite->print(composite);
    printf("\n");

    free(cyrcle);
    free(cyrcle1);
    free(cyrcle2);

    free(rect);
    free(box);

    eraseComposite(composite);
    eraseComposite(composite1);

    free(composite);
    free(composite1);

    return 0;
}
