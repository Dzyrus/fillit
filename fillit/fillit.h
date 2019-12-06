//
// Created by Laquanda Voyance on 29/11/2019.
//

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
void	print_figure_array(char **array, int size);
int 	solver(char **map, char **figures, int n_figures, int curr_size, int n);

#endif //FILLIT_FILLIT_H
