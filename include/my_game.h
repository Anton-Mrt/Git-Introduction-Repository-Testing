/*
** EPITECH PROJECT, 2026
** Git-Introduction-Repository-Testing
** File description:
** my_game
*/

#ifndef MY_GAME_H_
    #define MY_GAME_H_

    #include <SFML/Graphics.h>
    #include <SFML/Window.h>
    #include <SFML/System.h>

    #define WINDOW_WIDTH 800
    #define WINDOW_HEIGHT 600
    #define WINDOW_TITLE "My Game"
    #define PLAYER_SPEED 4.f
    #define PLAYER_SIZE 32.f

typedef struct player_s {
    sfRectangleShape *shape;
    sfVector2f position;
} player_t;

typedef struct game_s {
    sfRenderWindow *window;
    player_t *player;
} game_t;

game_t *game_init(void);
void game_run(game_t *game);
void game_destroy(game_t *game);

player_t *player_create(void);
void player_update(player_t *player, sfRenderWindow *window);
void player_draw(sfRenderWindow *window, player_t *player);
void player_destroy(player_t *player);

#endif /* !MY_GAME_H_ */
