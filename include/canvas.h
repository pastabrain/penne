#pragma once

#include "types/list.h"
#include "penne.h"
#include <ncurses.h>

struct PenneCanvas {
    int xpos;
    int ypos;
    int width;
    int height;
    ListStruct(PenneElement*)* elements;
};

PenneCanvas* PenneCanvas_new(int xpos, int ypos, int width, int height);

void PenneCanvas_add(PenneCanvas* c, PenneElement* e);

void PenneCanvas_draw(PenneCanvas* c, WINDOW* window);

void PenneCanvas_destroy(PenneCanvas* c);
