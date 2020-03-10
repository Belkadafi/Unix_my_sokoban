/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** collision
*/

#include "sokoban.h"

dimension_t get_start(map_t base, int *x)
{
    dimension_t start;
    start.heigth = (LINES - base.map.heigth) / 2;
    start.length = (COLS - base.map.length) / 2;
    *x = start.heigth;
    return start;
}

void draw_map(dimension_t start, int *x, char **map, map_t base)
{
    for (int i = 0; map[i] != NULL; i += 1) {
        mvprintw(*x, start.length, map[i]);
        *x += 1;
    }
    mvprintw(start.heigth + base.position.y,
        start.length + base.position.x, "P");
}

void move_all(int ch , map_t *base, char **map, int **maps)
{
    reference_t reference;

    reference.reference = maps;
    switch (ch) {
        case KEY_LEFT :
            if (map[base->position.y][base->position.x - 1] != '#') {
                reference.offset = -1;
                manage_collision(base, map, reference, 'x');
            }
            break;
        case KEY_RIGHT :
            if (map[base->position.y][base->position.x + 1] != '#') {
                reference.offset = 1;
                manage_collision(base, map, reference, 'x');
            }
            break;
    }
}

void my_free(char **map, int **reference)
{
    endwin();
    for (int i = 0; map[i] != NULL; i += 1) {
        free(map[i]);
        free(reference[i]);
    }
    free(map);
    free(reference);
}

void disp_map(map_t base, dimension_t start, char **map, int *x)
{
    start = get_start(base, x);
    clear();
    draw_map(start, x, map, base);
    refresh();
    endwin();
}