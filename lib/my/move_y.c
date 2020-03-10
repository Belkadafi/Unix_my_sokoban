/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** move_y
*/

#include "sokoban.h"

void move_y(char **map, int offset, map_t *base, int **reference)
{
    char c = ' ';

    if (reference[base->position.y + offset][base->position.x] == 0)
        c = 'O';
    if (map[base->position.y + offset][base->position.x] == 'X') {
        if ((map[base->position.y + 2 * offset]
            [base->position.x] != '#') && (map[base->position.y + 2 * offset]
            [base->position.x] != 'X')) {
            base->position.y += offset;
            map[base->position.y + offset][base->position.x] = 'X';
            map[base->position.y][base->position.x] = c;
        }
    }
    else
        base->position.y += offset;
}