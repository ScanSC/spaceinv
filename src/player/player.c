/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** player.c
*/

#include "player.h"
#include <stdio.h>

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->sprite = init_sprite("assets/player/ship_sprite.png", (sfVector2f) {1920 / 2 - 188 / 2, 800}, &(sfVector2i) {188, 206});
    player->hpmax = 100;
    player->hp = player->hpmax;
    player->spmax = 100;
    player->sp = player->spmax;
    player->speed = 10;
    player->shield = init_sprite("assets/player/shield.png", (sfVector2f) {player->sprite->pos.x, player->sprite->pos.y - 15}, NULL);
    return player;
}

static void anim_player(game_t *game)
{
    switch (game->player->sprite->status) {
    case 0:
        game->player->sprite->rect.top = 0;
        break;
    case 1:
        game->player->sprite->rect.top = 206;
        break;
    case 2:
        game->player->sprite->rect.top = 412;
        break;
    }
    if (game->player->sprite->last_frame + 0.1 <= game->clock->seconds) {
        move_rect(&game->player->sprite->rect, 188 * 3);
        game->player->sprite->last_frame = game->clock->seconds;
    }
}

void update_player(game_t *game)
{
    anim_player(game);
    sfSprite_setTextureRect(game->player->sprite->sprite, game->player->sprite->rect);
    sfSprite_setPosition(game->player->shield->sprite, (sfVector2f) {game->player->sprite->pos.x, game->player->sprite->pos.y - 15});
}

void displayer_player(sfRenderWindow *win, player_t *player)
{
    sfRenderWindow_drawSprite(win, player->sprite->sprite, NULL);
    if (player->shield->status)
        sfRenderWindow_drawSprite(win, player->shield->sprite, NULL);
}