/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** spaceinv.h
*/

#pragma once
#include "game_struct.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

level_t *init_level(void);
menu_t *init_menu(void);
player_t *init_player(void);
hud_t *init_hud(void);
sfRenderWindow *my_create_window(int height, int width, char *name);
void manage_menu(game_t *game);
void manage_game(game_t *game);
void check_event(game_t *game, sfEvent evt);
sfIntRect create_rect(int width, int height);

