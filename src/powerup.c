/*
** EPITECH PROJECT, 2026
** Git-Introduction-Repository-Testing
** File description:
** powerup
*/

#include <stdlib.h>
#include "my_game.h"

powerup_t *powerup_create(float x, float y)
{
    powerup_t *powerup = malloc(sizeof(powerup_t));

    if (powerup == NULL)
        return NULL;
    powerup->position.x = x;
    powerup->position.y = y;
    powerup->active = 1;
    powerup->shape = sfCircleShape_create();
    sfCircleShape_setRadius(powerup->shape, POWERUP_RADIUS);
    sfCircleShape_setFillColor(powerup->shape, sfYellow);
    sfCircleShape_setPosition(powerup->shape, powerup->position);
    return powerup;
}

void powerup_draw(sfRenderWindow *window, powerup_t *powerup)
{
    if (powerup->active)
        sfRenderWindow_drawCircleShape(window, powerup->shape, NULL);
}

int powerup_check_collision(powerup_t *powerup, player_t *player)
{
    sfFloatRect player_bounds = player_get_bounds(player);
    sfFloatRect powerup_bounds = sfCircleShape_getGlobalBounds(
        powerup->shape);

    if (!powerup->active)
        return 0;
    if (sfFloatRect_intersects(&player_bounds, &powerup_bounds, NULL)) {
        powerup->active = 0;
        return 1;
    }
    return 0;
}

void powerup_destroy(powerup_t *powerup)
{
    sfCircleShape_destroy(powerup->shape);
    free(powerup);
}
