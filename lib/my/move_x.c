/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** move_x
*/

#include "sokoban.h"

void move_x(char **map, int offset, map_t *base, int **reference)
{
    char c = ' ';

    if (reference[base->position.y][base->position.x + offset] == 0)
        c = 'O';
    if (map[base->position.y][base->position.x + offset] == 'X') {
        if ((map[base->position.y]
            [base->position.x + 2 * offset] != '#')
            && (map[base->position.y]
            [base->position.x + 2 * offset] != 'X')) {
                base->position.x += offset;
                map[base->position.y][base->position.x + offset] = 'X';
                map[base->position.y][base->position.x] = c;
            }
        }
    else
        base->position.x += offset;
}