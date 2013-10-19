#ifndef BOX_H
#define BOX_H

typedef struct _Box
{
    int x, y;

    int (*getX)(struct _Box *);
    void (*setX)(struct _Box *, int);

    int (*getY)(struct _Box *);
    void (*setY)(struct _Box *, int);

    void(*print)(struct _Box *);
    void (*move)(struct _Box *, int, int);

    int w, h;

    int (*getW)(struct _Box *);
    void (*setW)(struct _Box *, int);

    int (*getH)(struct _Box *);
    void (*setH)(struct _Box *, int);
} Box;

Box *newBox(int, int, int);

#endif
