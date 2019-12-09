#ifndef FILLIT_FILLIT_H
#define FILLIT_FILLIT_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "libft/libft.h"

int		main(int ac, char **av);
int		check_input(int fd);
char	*get_coords(char **str, char value);
void	print_array(char **array, int size);
int 	solve_map(char **map, char **figures, int n_figures);
char	**make_map();
int 	solver(char **map, char **figures, int n_figures, int curr_size, int n);
int		is_place(char *figure, char **map, int map_size, int y_map, int x_map);
void	put_figure(char *figure, char **map, char c, int y_map, int x_map);
int		map_size(int n_figures);

#endif //FILLIT_FILLIT_H
