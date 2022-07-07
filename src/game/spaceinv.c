/*
** EPITECH PROJECT, 2022
** spaceinv
** File description:
** spaceinv.c
*/

#include "spaceinv.h"

void manage_status(game_t *game)
{
    switch (game->status) {
    case 0:
        manage_menu(game);
        break;
    case 1:
        manage_game(game);
        break;
    case 2:
        //run_pause(game);
        break;
    case 4:
        //run_win(game);
        break;
    case 5:
        //un_lose(game);
        break;
    }
}

void my_loop(game_t *game)
{
    sfEvent evt;

    game->clock = malloc(sizeof(my_clock_t));
    game->clock->clock = sfClock_create();
    game->window = my_create_window(1080, 1920, "spaceinv");
    sfRenderWindow_setFramerateLimit(game->window, 45);
    //sfRenderWindow_setMouseCursorVisible(game->window, sfFalse);
    //sfSound_play(game->menu->music);
    while (sfRenderWindow_isOpen(game->window)) {
        game->clock->time = sfClock_getElapsedTime(game->clock->clock);
        game->clock->seconds = game->clock->time.microseconds / 1000000.0;
        sfRenderWindow_clear(game->window, sfBlack);
        check_event(game, evt);
        manage_status(game);
        sfRenderWindow_display(game->window);
    }
}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->menu = init_menu();
    game->player = init_player();
    game->level = init_level();
    game->hud = init_hud();
    game->status = 0;
    return game;
}

int spaceinv(void)
{
    game_t *game = init_game();

    if (game == NULL)
        return 84;
    my_loop(game);
    printf("ok\n");
    return 0;
}
