/*
** EPITECH PROJECT, 2026
** Git-Introduction-Repository-Testing
** File description:
** game
*/

#include <stdlib.h>
#include "my_game.h"

game_t *game_init(void)
{
    game_t *game = malloc(sizeof(game_t));
    sfVideoMode mode = {WINDOW_WIDTH, WINDOW_HEIGHT, 32};

    if (game == NULL)
        return NULL;
    game->window = sfRenderWindow_create(mode, WINDOW_TITLE,
        sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(game->window, 60);
    return game;
}

static void game_handle_events(game_t *game)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(game->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(game->window);
    }
}

void game_run(game_t *game)
{
    while (sfRenderWindow_isOpen(game->window)) {
        game_handle_events(game);
        sfRenderWindow_clear(game->window, sfBlack);
        sfRenderWindow_display(game->window);
    }
}

void game_destroy(game_t *game)
{
    sfRenderWindow_destroy(game->window);
    free(game);
}
