#include "canvas.h"

#include "element.h"

#include <stdlib.h>

void on_list_destroy(void* list)
{
    ListStruct(PenneElement*)* l = list;

    size_t i;
    for (i = 0; i < l->size; i++) {
        PenneElement_destroy(l->list[i]);
    }
}

void on_list_erase(void* list, size_t index)
{
    ListStruct(PenneElement*)* l = list;
    free(l->list[index]);
}


PenneCanvas* PenneCanvas_new(int xpos, int ypos, int width, int height)
{
    PenneCanvas* c = malloc(sizeof(PenneCanvas));
    c->xpos = xpos;
    c->ypos = ypos;
    c->width = width;
    c->height = height;
    ListInit(c->elements, on_list_destroy, on_list_erase);

    return c;
}

void PenneCanvas_add(PenneCanvas* c, PenneElement* e)
{
    List_Append(c->elements, e);
}

void PenneCanvas_draw(PenneCanvas* c, WINDOW* window)
{
    size_t i;

    for (i = 0; i < c->elements->size; i++) {
        PenneElement* e = c->elements->list[i];
        if (!e->visible) { continue; }
        e->draw(e, window);
    }
}

void PenneCanvas_destroy(PenneCanvas* c)
{
    List_Destroy(c->elements);
    free(c);
}
