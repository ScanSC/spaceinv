/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** game.h
*/

#pragma once
#include "game_struct.h"
void update_player(game_t *game);
void displayer_player(sfRenderWindow *win, player_t *player);
void display_hud(game_t *game);
void update_hud(game_t *game);
