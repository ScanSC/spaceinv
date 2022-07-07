/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** level.h
*/

#pragma once
#include "game_struct.h"
#include <stdlib.h>

sprite_t *init_sprite(char *filepath, sfVector2f pos, sfVector2i *dim);
void move_rect(sfIntRect *rect, int max_value);
