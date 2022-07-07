/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** manage rect for sprites
*/

#include "spaceinv.h"

sprite_t *init_sprite(char *filepath, sfVector2f pos, sfVector2i *dim)
{
    sprite_t *sprite = malloc(sizeof(sprite_t));

    sprite->sprite = sfSprite_create();
    sprite->texture = sfTexture_createFromFile(filepath, NULL);
    sfSprite_setTexture(sprite->sprite, sprite->texture, sfFalse);
    if (dim) {
        sprite->rect = create_rect(dim->x, dim->y);
        sfSprite_setTextureRect(sprite->sprite, sprite->rect);
    }
    sprite->pos = pos;
    sfSprite_setPosition(sprite->sprite, sprite->pos);
    sprite->status = 0;
    sprite->last_frame = 0;
    return sprite;
}

sfIntRect create_rect(int width, int height)
{
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.width = width;
    rect.height = height;
    return rect;
}

void move_rect(sfIntRect *rect, int max_value)
{
    if (rect->left + rect->width >= max_value) {
        rect->left = 0;
    } else {
        rect->left += rect->width;
    }
}
