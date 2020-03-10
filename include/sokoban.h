/*
** EPITECH PROJECT, 2019
** sokoban
** File description:
** sokoban.h
*/

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdarg.h>
#include <ncurses.h>


typedef struct vector_s
{
    int x;
    int y;
} vector_t;

typedef struct dimension_s
{
    int length;
    int heigth;
} dimension_t;

typedef struct map_s
{
    dimension_t map;
    vector_t position;
} map_t;

typedef struct ref_s
{
    int **reference;
    int ch;
} ref_t;

typedef struct O_position_s
{
    vector_t *position;
    int nb;
    int score;
} O_position_t;

typedef struct reference_s
{
    int **reference;
    int offset;
} reference_t;

typedef struct ptr_s
{
    char c;
    void (*ptr)(char **, int, map_t *, int **);
} ptr_t;

#include "my.h"

#endif /* SOKOBAN_H_ */