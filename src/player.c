/*
** EPITECH PROJECT, 2026
** Git-Introduction-Repository-Testing
** File description:
** player
*/

#include <stdlib.h>
#include "my_game.h"

player_t *player_create(void)
{
    player_t *player = malloc(sizeof(player_t));

    if (player == NULL)
        return NULL;
    player->position.x = WINDOW_WIDTH / 2.f;
    player->position.y = WINDOW_HEIGHT / 2.f;
    player->shape = sfRectangleShape_create();
    sfRectangleShape_setSize(player->shape,
        (sfVector2f){PLAYER_SIZE, PLAYER_SIZE});
    sfRectangleShape_setFillColor(player->shape, sfGreen);
    sfRectangleShape_setPosition(player->shape, player->position);
    return player;
}

void player_update(player_t *player, sfRenderWindow *window)
{
    (void)window;
    if (sfKeyboard_isKeyPressed(sfKeyUp))
        player->position.y -= PLAYER_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyDown))
        player->position.y += PLAYER_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyLeft))
        player->position.x -= PLAYER_SPEED;
    if (sfKeyboard_isKeyPressed(sfKeyRight))
        player->position.x += PLAYER_SPEED;
    sfRectangleShape_setPosition(player->shape, player->position);
}

void player_draw(sfRenderWindow *window, player_t *player)
{
    sfRenderWindow_drawRectangleShape(window, player->shape, NULL);
}

void player_destroy(player_t *player)
{
    sfRectangleShape_destroy(player->shape);
    free(player);
}

sfFloatRect player_get_bounds(player_t *player)
{
    return sfRectangleShape_getGlobalBounds(player->shape);
}
