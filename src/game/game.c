/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** game.c
*/

#include "game.h"

void manage_game(game_t *game)
{
    sfRenderWindow_drawSprite(game->window, game->level->background->sprite, NULL);
    update_player(game);
    displayer_player(game->window, game->player);
    update_hud(game);
    display_hud(game);
}