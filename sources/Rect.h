#ifndef RECT_H
#define RECT_H

typedef struct _Rect
{
    int x, y;

    int (*getX)(struct _Rect *);
    void (*setX)(struct _Rect *, int);

    int (*getY)(struct _Rect *);
    void (*setY)(struct _Rect *, int);

    void(*print)(struct _Rect *);
    void (*move)(struct _Rect *, int, int);

    int w, h;

    int (*getW)(struct _Rect *);
    void (*setW)(struct _Rect *, int);

    int (*getH)(struct _Rect *);
    void (*setH)(struct _Rect *, int);
} Rect;

Rect *newRect(int, int, int, int);
void initRect(Rect *rect, int, int, int, int);

int getW(Rect *self);
void setW(Rect *self, int);
int getH(Rect *self);
void setH(Rect *self, int);

#endif
