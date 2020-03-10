/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** check_win
*/

#include "sokoban.h"

void reset_all(char **map, int **reference, map_t *base, vector_t ref)
{
    for (int i = 0; map[i] != NULL; i += 1) {
        for (int j = 0; map[i][j] != '\0'; j += 1) {
            if (reference[i][j] == 5)
                map[i][j] = 'X';
            if (reference[i][j] == 1)
                map[i][j] = ' ';
        }
    }
    base->position = ref;
}

void is_stuck(char **map, int **reference, int *count, vector_t coor)
{
    if ((map[coor.y][coor.x] == 'X' && reference[coor.y][coor.x + 1] == -3
    && reference[coor.y + 1][coor.x] == -3 ) || (
    map[coor.y][coor.x] == 'X' && reference[coor.y][coor.x - 1] == -3
    && reference[coor.y - 1][coor.x] == -3)) {
        if (map[coor.y][coor.x] == 'X' && reference[coor.y][coor.x + 1] == -3
        && reference[coor.y + 1][coor.x] == -3)
            *count -= 1;
        else
            *count -= 1;
    }
    else if ((map[coor.y][coor.x] == 'X' && reference[coor.y][coor.x + 1] == -3
            && reference[coor.y - 1][coor.x] == -3) || (
            map[coor.y][coor.x] == 'X' && reference[coor.y][coor.x - 1] == -3
            && reference[coor.y + 1][coor.x] == -3)) {
        if (map[coor.y][coor.x] == 'X' && reference[coor.y][coor.x - 1] == -3
            && reference[coor.y - 1][coor.x] == -3)
            *count -= 1;
        else
            *count -= 1;
        }
}

int check_stuck(char **map, int **reference)
{
    int count = 0;
    vector_t coor;

    for (int i = 0; map[i] != NULL; i += 1) {
        for (int j = 0; map[i][j] != '\0'; j += 1) {
            if (map[i][j] == 'X')
                count += 1;
        }
    }
    for (int i = 0; map[i] != NULL; i += 1) {
        for (int j = 0; map[i][j] != '\0'; j += 1) {
            coor.y = i;
            coor.x = j;
            is_stuck(map, reference, &count, coor);
        }
    }
    if (count != 0)
        return 0;
    return 1;
}

int is_win(char **map, int **reference)
{
    for (int i = 0; map[i] != NULL; i += 1) {
        for (int j = 0; map[i][j] != '\0'; j += 1) {
            if (reference[i][j] != 0 && map[i][j] == 'X')
                return (0);
        }
    }
    return (1);
}

int check_error(char **map)
{
    int count = 0;

    for (int i = 0; map[i] != NULL; i += 1) {
        for (int j = 0; map[i][j] != '\0'; j += 1) {
            if (map[i][j] == 'X')
                count += 1;
            if (map[i][j] == 'O')
                count -= 1;
            if (map[i][j] != 'X' && map[i][j] != 'O' && map[i][j] != ' '
            && map[i][j] != '\n' && map[i][j] != '\0' && map[i][j] != '#'
            && map[i][j] != 'P')
                return 1;
        }
    }
    if (count < 0)
        return 1;
    return 0;
}