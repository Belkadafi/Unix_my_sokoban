/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** mouvement
*/

#include "sokoban.h"

static const ptr_t tab[] = {
    {'x', move_x},
    {'y', move_y}
};

vector_t get_p_position(char **map)
{
    vector_t position = {-23, -23};

    for (int i = 0; map[i] != NULL; i += 1) {
        for (int j = 0; map[i][j] != '\0'; j += 1) {
            if (map[i][j] == 'P') {
            position.x = j;
            position.y = i;
            return (position);
            }
        }
    }
    return (position);
}

int **my_parser(char **map)
{
    map_t base = get_size(map);
    int **reference = malloc(sizeof(int *) * (base.map.heigth));

    for (int i = 0; map[i] != NULL; i += 1) {
        reference[i] = malloc(sizeof(int) * (my_strlen(map[i])));
        for (int j = 0; map[i][j] != '\0'; j += 1) {
            if (map[i][j] == ' ')
                reference[i][j] = 1;
            if (map[i][j] == '#' || map[i][j] == '\n')
                reference[i][j] = -3;
            if (map[i][j] == 'X')
                reference[i][j] = 5;
            if (map[i][j] == 'O')
                reference[i][j] = 0;
        }
    }
    return reference;
}

void manage_collision(map_t *base, char **map, reference_t reference, char c)
{
    for (int i = 0; i < 2; i += 1) {
        if (tab[i].c == c) {
            tab[i].ptr(map, reference.offset, base, reference.reference);
        }
    }
}

void move_p(int ch , map_t *base, char **map, int **maps)
{
    reference_t reference;

    reference.reference = maps;
    switch (ch) {
        case KEY_UP :
            if (map[base->position.y - 1][base->position.x] != '#') {
                reference.offset = -1;
                manage_collision(base, map, reference, 'y');
            }
            break;
        case KEY_DOWN :
            if (map[base->position.y + 1][base->position.x] != '#') {
                reference.offset = 1;
                manage_collision(base, map, reference, 'y');
            }
            break;
    }
    move_all(ch, base, map, maps);
}

int game_loop(char **map, dimension_t start, map_t base)
{
    int x = start.heigth;
    int **reference = my_parser(map);
    int ch = 0;
    vector_t ref = base.position;

    while (!is_win(map, reference) &&
        !check_stuck(map, reference)) {
        clear();
        start = get_start(base, &x);
        if (ch == ' ')
            reset_all(map, reference, &base, ref);
        draw_map(start, &x, map, base);
        ch = getch();
        move_p(ch, &base, map, reference);
        refresh();
    }
    disp_map(base, start, map, &x);
    if (check_stuck(map, reference))
        return 0;
    return 1;
}