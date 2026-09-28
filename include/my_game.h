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

typedef struct game_s {
    sfRenderWindow *window;
} game_t;

game_t *game_init(void);
void game_run(game_t *game);
void game_destroy(game_t *game);

#endif /* !MY_GAME_H_ */
