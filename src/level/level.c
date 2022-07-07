/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** level.c
*/

#include "level.h"

level_t *init_level(void)
{
    level_t *level = malloc(sizeof(level_t));

    level->background = init_sprite("assets/level/space1.jpg", (sfVector2f) {0, 0}, NULL);
    level->status = 0;
    return level;
}

void display_level(sfRenderWindow *win, level_t *level)
{
    sfRenderWindow_drawSprite(win, level->background->sprite, NULL);
}