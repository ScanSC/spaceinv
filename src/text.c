/*
** EPITECH PROJECT, 2021
** spaceinv
** File description:
** text.c
*/

#include "spaceinv.h"

sfText *init_text(char *str, sfVector2f pos, int size, sfColor col)
{
    sfFont *font = sfFont_createFromFile("assets/menu.otf");
    sfText *text = sfText_create();

    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    sfText_setColor(text, col);
    sfText_setCharacterSize(text, size);
    return text;
}