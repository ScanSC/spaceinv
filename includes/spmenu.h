/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** spmenu.h
*/

#pragma once
#include <stdlib.h>
#include "game_struct.h"

sprite_t *init_sprite(char *filepath, sfVector2f pos, sfVector2i *dim);
button_t *init_bp(char *str, sfVector2f pos, sfVector2f size);
void bp_update(sfRenderWindow *win, button_t *bp);
