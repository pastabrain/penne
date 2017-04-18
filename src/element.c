#include "element.h"

#include "canvas.h"

#include <stdlib.h>

PenneElement* PenneElement_new(PenneCanvas* canvas, int xpos, int ypos)
{
    PenneElement* e = malloc(PENNE_ELEMENT_SIZE);
    e->xpos = xpos;
    e->ypos = ypos;
    e->visible = TRUE;
    e->canvas = canvas;
    e->on_destroy = PenneElement_destroy; // Default "destructor" function

    return e;
}

void PenneElement_move(PenneElement* e, int nx, int ny)
{
    e->xpos = nx;
    e->ypos = ny;
}

void PenneElement_destroy(PenneElement* e)
{
    free(e);
}
