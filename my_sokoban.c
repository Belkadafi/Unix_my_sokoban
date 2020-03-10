/*
** EPITECH PROJECT, 2019
** my_sokoban
** File description:
** my_sokoban
*/

#include "sokoban.h"

map_t get_size(char **map)
{
    int length = 0;
    int height = 0;
    map_t base;

    for (int i = 0; map[0][i] != '\0'; i += 1)
        length += 1;
    for (int i = 0; map[i] != NULL; i += 1)
        height += 1;
    base.map.length = length;
    base.map.heigth = height;
    return (base);
}

int game_init(char **map)
{
    map_t base = get_size(map);
    vector_t position = get_p_position(map);
    dimension_t start;

    if (position.x == -23) {
        write(2, "Missing player\n", 16);
        return 9;
    }
    base.position = position;
    map[base.position.y][base.position.x] = ' ';
    initscr();
    cbreak();
    noecho();
    curs_set(0);
    keypad(stdscr, TRUE);
    start.heigth = (LINES - base.map.heigth) / 2;
    start.length = (COLS - base.map.length) / 2;
    return (game_loop(map, start, base));
}

char **file_opener(char *filepath)
{
    char *str;
    struct stat st;
    int fd = open(filepath, O_RDONLY);
    char **map;

    if (fd < 0) {
        write(2, "No such file or directory\n", 27);
        return (NULL);
    }
    stat(filepath, &st);
    if (st.st_size == 0) {
        write(2, "empty file\n", 12);
        return (NULL);
    }
    str = malloc(sizeof(char) * st.st_size + 1);
    read(fd, str, st.st_size);
    str[st.st_size] = 0;
    map = my_str_to_word_array(str);
    free(str);
    return (map);
}

void my_print_help(void)
{
    my_putstr("USAGE\n     ./my_sokoban map\nDESCRIPTION\n     ");
    my_putstr("map file representingthe warehouse map, ");
    my_putstr("containing ‘#’ for walls,\n");
    my_putstr("     ‘P’ for the player, ‘X’ for boxes and ‘O’");
    my_putstr(" for storage locations.\n");
}

int main(int ac, char **av)
{
    char **map;
    int test = 5;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        my_print_help();
        return 0;
    }
    map = file_opener(av[1]);
    if (map == NULL)
        return 84;
    if (check_error(map)) {
        write(2, "Invalid map\n", 13);
        return 84;
    }
    test = game_init(map);
    if (test == 1)
        return 0;
    if (test == 0)
        return 1;
    return 84;
}