/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** window.c
*/

#include "spaceinv.h"

sfRenderWindow *my_create_window(int height, int width, char *name)
{
    sfRenderWindow *window;
    sfVideoMode mode;

    mode.height = height;
    mode.width = width;
    mode.bitsPerPixel = 32;

    window = sfRenderWindow_create(mode, name, sfClose | sfTitlebar | sfResize, NULL);
    return window;
}
