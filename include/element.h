#pragma once

#include <stdbool.h>
#include <ncurses.h>

#include "penne.h"

#define PENNE_EXTRA_ELEMENT_SPACE 256

#define PENNE_ELEMENT_BASE_MEMBERS int xpos; \
                                  int ypos; \
                                  bool visible; \
                                  PenneCanvas* canvas; \
                                  void (*draw)(PenneElement* e, \
                                               WINDOW* window); \
                                  void (*on_destroy)(PenneElement* e);

struct PenneElement {
    PENNE_ELEMENT_BASE_MEMBERS
    char extra[PENNE_EXTRA_ELEMENT_SPACE];
};

#define PENNE_ELEMENT_SIZE sizeof(PenneElement)

/// Creates a new PenneElement instance.
PenneElement* PenneElement_new(PenneCanvas* c, int xpos, int ypos);

void PenneElement_move(PenneElement* e, int nx, int ny);

void PenneElement_draw(PenneElement* e, WINDOW* window);

void PenneElement_destroy(PenneElement* e);
