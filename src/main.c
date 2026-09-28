/*
** EPITECH PROJECT, 2026
** Git-Introduction-Repository-Testing
** File description:
** main
*/

#include "my_game.h"

int main(void)
{
    game_t *game = game_init();

    if (game == NULL)
        return 84;
    game_run(game);
    game_destroy(game);
    return 0;
}
