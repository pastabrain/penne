#include "elements/string.h"

#include "penne.h"

PenneString* PenneString_new(PenneCanvas* c, char* text, int xpos, int ypos)
{
    PenneString* e = (PenneString*) PenneElement_new(c, xpos, ypos);
    e->draw = PenneString_draw;
    e->on_destroy = PenneString_destroy;
    e->text = strdup(text);

    return e;
}

void PenneString_draw(PenneString* e, WINDOW* win)
{
    if (e->ypos >= e->canvas->height || e->ypos < e->canvas->ypos
        || e->xpos >= e->canvas->width || e->xpos < e->canvas->xpos) {
        return;
    }

    mvwprintw(win, e->ypos, e->xpos, e->text);
}

void PenneString_destroy(PenneString* e)
{
    free(e->text);
    free(e);
}
