/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** event.c
*/

#include "event.h"

static void event_menu(game_t *game, sfEvent evt)
{
    sfVector2i mouse_co = sfMouse_getPositionRenderWindow(game->window);

    if (evt.mouseButton.button == sfMouseLeft && mouse_collide(mouse_co, game->menu->bp_play->rect))
        game->status = 1;
    if (evt.mouseButton.button == sfMouseLeft && mouse_collide(mouse_co, game->menu->bp_quit->rect))
        sfRenderWindow_close(game->window);
}


static void manage_click(game_t *game, sfEvent evt)
{
    switch (game->status) {
    case 0:
        event_menu(game, evt);
        break;
    case 1:
        /*if (evt.mouseButton.button == sfMouseLeft)
            player_attack(game);*/
        if (evt.mouseButton.button == sfMouseRight)
            game->player->shield->status = 1;
        break;
    default: break;
    }
}

static player_t *move_player(player_t *player, int x, int y)
{
    if (x < 0)
        player->sprite->status = 1;
    else if (x > 0)
        player->sprite->status = 2;
    player->sprite->pos.x += x * player->speed;
    player->sprite->pos.y += y * player->speed;
    sfSprite_setPosition(player->sprite->sprite, player->sprite->pos);
    return player;
}

static void move_events(game_t *game)
{
    if (sfKeyboard_isKeyPressed(sfKeyQ))
        move_player(game->player, -1, 0);
    if (sfKeyboard_isKeyPressed(sfKeyD))
        move_player(game->player, 1, 0);
    if (sfKeyboard_isKeyPressed(sfKeyZ))
        move_player(game->player, 0, -1);
    if (sfKeyboard_isKeyPressed(sfKeyS))
        move_player(game->player, 0, 1);
}

void check_event(game_t *game, sfEvent evt)
{
    if (game->status == 1)
        move_events(game);
    while (sfRenderWindow_pollEvent(game->window, &evt)) {
        if (evt.type == sfEvtClosed) {
            sfRenderWindow_close(game->window);
            return;
        }
        if (evt.type == sfEvtMouseButtonPressed)
            manage_click(game, evt);
        if (evt.type == sfEvtMouseButtonReleased && evt.mouseButton.button == sfMouseRight)
            game->player->shield->status = 0;
        if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyEscape)
            game->status = 0;
        if (evt.type == sfEvtKeyReleased && (evt.key.code == sfKeyQ
            || evt.key.code == sfKeyD
            || evt.key.code == sfKeyZ
            || evt.key.code == sfKeyS))
            game->player->sprite->status = 0;
    }
}