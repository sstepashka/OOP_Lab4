#ifndef SHAPE_H
#define SHAPE_H

typedef struct _Shape
{
    int x, y;

    int (*getX)(struct _Shape *);
    void (*setX)(struct _Shape *, int);

    int (*getY)(struct _Shape *);
    void (*setY)(struct _Shape *, int);

    void (*print)(struct _Shape *);
    void (*move)(struct _Shape *, int, int);
} Shape;

int getX(Shape *);
void setX(Shape *, int);
int getY(Shape *);
void setY(Shape *, int);
void move(Shape *, int, int);
void print(Shape *);

Shape *newShape(int, int);
void initShape(Shape *, int, int);

#endif
