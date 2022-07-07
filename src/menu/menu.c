/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** level.c
*/

#include "spmenu.h"

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));

    menu->background = init_sprite("assets/menu/background.jpg", (sfVector2f) {0, 0}, NULL);
    menu->bp_play = init_bp("PLAY", (sfVector2f) {50, 500}, (sfVector2f) {500, 80});
    menu->bp_quit = init_bp("QUIT", (sfVector2f) {50, 700}, (sfVector2f) {500, 80});
    return menu;
}

void display_menu(sfRenderWindow *win, menu_t *menu)
{
    sfRenderWindow_drawSprite(win, menu->background->sprite, NULL);
    sfRenderWindow_drawRectangleShape(win, menu->bp_play->shape, NULL);
    sfRenderWindow_drawText(win, menu->bp_play->text, NULL);
    sfRenderWindow_drawRectangleShape(win, menu->bp_quit->shape, NULL);
    sfRenderWindow_drawText(win, menu->bp_quit->text, NULL);
}

void manage_menu(game_t *game)
{
    bp_update(game->window, game->menu->bp_play);
    bp_update(game->window, game->menu->bp_quit);
    display_menu(game->window, game->menu);
}
