#pragma once

#include "penne.h"

typedef struct {
    PENNE_ELEMENT_BASE_MEMBERS
    char* text;
} PenneString;

PenneString* PenneString_new(PenneCanvas* c, char* string, int xpos, int ypos);

void PenneString_draw(PenneString* e, WINDOW* window);

void PenneString_destroy(PenneString* e);
