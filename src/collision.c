/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** collision.c
*/

#include "spaceinv.h"

int mouse_collide(sfVector2i mouse_co, sfFloatRect rect)
{
    if (mouse_co.x <= rect.left + rect.width
        && mouse_co.x >= rect.left
        && mouse_co.y <= rect.top + rect.height
        && mouse_co.y >= rect.top)
        return 1;
    return 0;
}
