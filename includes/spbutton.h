/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** spbutton.h
*/

#pragma once
#include <stdlib.h>
#include "game_struct.h"

sprite_t *init_sprite(char *filepath, sfVector2f pos, sfVector2i *dim);
sfText *init_text(char *str, sfVector2f pos, int size, sfColor col);
int mouse_collide(sfVector2i mouse_co, sfFloatRect rect);
