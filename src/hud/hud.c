/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** hud.c
*/

#include "hud.h"

hud_t *init_hud(void)
{
    hud_t *hud = malloc(sizeof(hud_t));

    hud->bar_hp = init_bar((sfColor) {255, 50, 50, 255}
    , (sfVector2f) {160, 910});
    hud->bar_sp = init_bar((sfColor) {50, 50, 255, 255}
    , (sfVector2f) {160, 970});
    return hud;
}

void update_hud(game_t *game)
{
    sfRectangleShape_setSize(game->hud->bar_hp->fill, (sfVector2f)
    {(float) game->player->hp / (float) game->player->hpmax * (float) 300, 30});
    sfRectangleShape_setSize(game->hud->bar_sp->fill, (sfVector2f)
    {(float) game->player->sp / (float) game->player->spmax * (float) 300, 30});
}

static void display_bar(game_t *game, bar_t *bar)
{
    sfRenderWindow_drawRectangleShape(game->window, bar->back, NULL);
    sfRenderWindow_drawRectangleShape(game->window, bar->fill, NULL);
}

void display_hud(game_t *game)
{
    display_bar(game, game->hud->bar_hp);
    display_bar(game, game->hud->bar_sp);
}