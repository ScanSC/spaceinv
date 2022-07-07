/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** free_all.c
*/

#include "free_all.h"

void free_all(game_t *game)
{
    free(game);
    return;
}