/*
** EPITECH PROJECT, 2022
** rpg
** File description:
** bar.c
*/

#include "hud.h"

static sfRectangleShape *create_rectangle(sfColor color)
{
    sfRectangleShape *rect = sfRectangleShape_create();

    sfRectangleShape_setFillColor(rect, color);
    sfRectangleShape_setSize(rect, (sfVector2f) {300, 30});
    return rect;
}

bar_t *init_bar(sfColor color, sfVector2f pos)
{
    bar_t *bar = malloc(sizeof(bar_t));

    bar->back = create_rectangle((sfColor) {155, 155, 155, 255});
    sfRectangleShape_setOutlineThickness(bar->back, 4);
    sfRectangleShape_setOutlineColor(bar->back, sfBlack);
    bar->fill = create_rectangle(color);
    sfRectangleShape_setPosition(bar->back, pos);
    sfRectangleShape_setPosition(bar->fill, pos);
    return bar;
}
