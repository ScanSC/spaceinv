/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** button.c
*/

#include "spbutton.h"

static void bp_sethover(button_t *bp)
{
    sfRectangleShape_setOutlineThickness(bp->shape, 4);
    sfRectangleShape_setOutlineColor(bp->shape, sfWhite);
}

static void bp_setunhover(button_t *bp)
{
    sfRectangleShape_setOutlineThickness(bp->shape, 2);
    sfRectangleShape_setOutlineColor(bp->shape, (sfColor) {155, 155, 255, 0});
}

button_t *init_bp(char *str, sfVector2f pos, sfVector2f size)
{
    button_t *bp = malloc(sizeof(button_t));
    sfFloatRect tmp_text;

    bp->status = 0;
    bp->color = sfBlue;
    bp->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(bp->shape, size);
    sfRectangleShape_setFillColor(bp->shape, (sfColor) {155, 155, 255, 155});
    sfRectangleShape_setPosition(bp->shape, pos);
    sfRectangleShape_setOutlineThickness(bp->shape, 2);
    sfRectangleShape_setOutlineColor(bp->shape, (sfColor) {155, 155, 255, 0});
    bp->text = init_text(str, pos, 30, sfWhite);
    tmp_text = sfText_getGlobalBounds(bp->text);
    bp->rect = sfRectangleShape_getGlobalBounds(bp->shape);
    pos.x = bp->rect.left + 30;
    pos.y = bp->rect.top + (bp->rect.height / 2) - (tmp_text.height / 2) + 6;
    sfText_setPosition(bp->text, pos);
    return bp;
}

void bp_update(sfRenderWindow *win, button_t *bp)
{
    sfVector2i mouse_co = sfMouse_getPositionRenderWindow(win);

    if (mouse_collide(mouse_co, sfRectangleShape_getGlobalBounds(bp->shape)))
        bp_sethover(bp);
    else
        bp_setunhover(bp);
}
