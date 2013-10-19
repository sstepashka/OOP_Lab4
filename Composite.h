#ifndef COMPOSITE_H
#define COMPOSITE_H
#include "Shape.h"
#import "ArrayElement.h"

typedef struct _Composite
{
    int x, y;

    int (*getX)(struct _Composite *);
    void (*setX)(struct _Composite *, int);

    int (*getY)(struct _Composite *);
    void (*setY)(struct _Composite *, int);

    void(*print)(struct _Composite *);
    void (*move)(struct _Composite *, int, int);

    ArrayElement **array;

    void (*addShape)(struct _Composite *, Shape *);
    void (*removeShape)(struct _Composite *, Shape *);
} Composite;

Composite *newComposite(int, int);
void eraseComposite(Composite *);

#endif
