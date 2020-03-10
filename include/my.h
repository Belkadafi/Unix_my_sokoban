/*
** EPITECH PROJECT, 2019
** my.h
** File description:
** all prototypes
*/
#include <stdlib.h>
#include <stdarg.h>

void my_putchar(char c);
int my_isneg(int nb);
int my_put_nbr(int nb);
void my_swap(int *a, int *b);
int my_putstr(char const *str);
int my_strlen(char const *str);
int my_getnbr(char const *str);
void my_sort_int_array(int *tab, int size);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_is_prime(int nb);
int my_find_prime_sup (int nb);
char *my_strcpy(char *dest, char const *src);
char *my_strncpy(char *dest, char const *src, int n);
char * my_revstr(char *str);
char *my_strstr(char *str, char const *to_find);
int my_strcmp(char const *s1, char const *s2);
int my_strncmp(char const *s1, char const *s2, int n);
char *my_strupcase (char *str);
char *my_strlowcase (char *str);
char *my_strcapitalize (char *str);
int my_str_isalpha(char const *str);
int my_str_isnum(char const *str);
int my_str_islower(char const *str);
int my_str_isupper(char const *str);
int my_str_isprintable(char const *str);
int my_showstr(char const * str);
int my_showmem(char const *str, int size);
char *my_strcat(char *dest, char const *src);
char *my_strncat(char *dest, char const *src, int nb);
char *my_strdup(char const *src);
int my_strlen2(char *str);
int fs_open_file(char const *filepath);
char **my_str_to_word_array(char const *str);
vector_t get_p_position(char **map);
void move_p(int ch , map_t *base, char **map, int **);
int game_loop(char **map, dimension_t start, map_t base);
void move_x(char **map, int offset, map_t *base, int **reference);
void move_y(char **map, int offset, map_t *base, int **reference);
map_t get_size(char **map);
int is_win(char **map, int **reference);
int check_error(char **map);
int check_stuck(char **map, int **reference);
void reset_all(char **map, int **reference, map_t *base, vector_t ref);
dimension_t get_start(map_t base, int *x);
void draw_map(dimension_t start, int *x, char **map, map_t base);
void move_all(int ch , map_t *base, char **map, int **maps);
void manage_collision(map_t *base, char **map, reference_t reference, char c);
void my_free(char **map, int **reference);
void disp_map(map_t base, dimension_t start, char **map, int *x);