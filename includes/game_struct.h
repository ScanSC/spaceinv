/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** main.h
*/

#pragma once

#include "csfml_includes.h"
#include <stdbool.h>

typedef struct sprite_s {
    sfVector2f pos;
    sfVector2f scale;
    char *filepath;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    float last_frame;
    int status;
} sprite_t;

typedef struct button_s {
    sfText *text;
    sfColor color;
    sfRectangleShape *shape;
    sfFloatRect rect;
    int status;
} button_t;

typedef struct menu_s {
    sprite_t *background;
    button_t *bp_play;
    button_t *bp_quit;
    sfSound *music;
} menu_t;

typedef struct player_s {
    sprite_t *sprite;
    sprite_t *shield;
    int sp;
    int spmax;
    int hp;
    int hpmax;
    int speed;
} player_t;

typedef struct level_s {
    sprite_t *background;
    int status;
} level_t;

typedef struct bar_s {
    sfRectangleShape *back;
    sfRectangleShape *fill;
} bar_t;

typedef struct hud_s {
    bar_t *bar_hp;
    bar_t *bar_sp;
} hud_t;

typedef struct my_clock_s {
    sfClock *clock;
    sfTime time;
    float seconds;
} my_clock_t;

typedef struct game_s {
    player_t *player;
    level_t *level;
    menu_t *menu;
    hud_t *hud;
    my_clock_t *clock;
    sfRenderWindow *window;
    int status;
} game_t;
