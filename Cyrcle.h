#ifndef CYRCLE_H
#define CYRCLE_H

typedef struct _Cyrcle
{
    int x, y;

    int (*getX)(struct _Cyrcle *);
    void (*setX)(struct _Cyrcle *, int);

    int (*getY)(struct _Cyrcle *);
    void (*setY)(struct _Cyrcle *, int);

    void (*print)(struct _Cyrcle *);
    void (*move)(struct _Cyrcle *, int, int);

    int r;

    int (*getR)(struct _Cyrcle *);
    void (*setR)(struct _Cyrcle *, int);
} Cyrcle;

void initCyrcle(Cyrcle *, int, int, int);
Cyrcle *newCyrcle(int, int, int);

int getR(Cyrcle *self);
void setR(Cyrcle *self, int);

#endif
