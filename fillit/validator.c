//
// Created by Laquanda Voyance on 01/12/2019.
//
#include "fillit.h"
void	print_figure_array(char **array, int size)
{
	int i = 0;

	while (i < size)
	{
		int n = 0;
		while (n < 8)
		{
			printf("%d;", array[i][n]);
			n++;
		}
		printf("%c\n", array[i][8]);
		i++;

	}
}

void	print_array(char **array, int size)
{
	int i = 0;

	while (i < size)
	{

			ft_putstr(array[i]);
			i++;

	}
}
int 	check_connection(const char *buff)
{
	int index;
	int connection;

	index = 0;
	connection = 0;
	while (index < 20)
	{
		if (buff[index] == '#')
		{
			if (index + 1 < 19 && buff[index + 1] == '#')
				connection++;
			if (index + 5 < 19 && buff[index + 5] == '#')
				connection++;
			if (index - 1 >= 0 && buff[index - 1] == '#')
				connection++;
			if (index - 5 >= 0 && buff[index - 5] == '#')
				connection++;
		}
		index++;
	}
	if (!(connection == 6 || connection == 8))
		return (1);
	return (0);
}
int		check_file(int result, const char *buff)
{
	int index;
	int count;

	index = 0;
	count = 0;
	while (index < 20)
	{
		if (index % 5 < 4 && !(buff[index] == '.' || buff[index] == '#'))
			return (1);
		if (index % 5 < 4 && buff[index] == '#' && ++count > 4)
			return (1);
		if (index % 5 == 4 && buff[index] != '\n')
			return (1);
		index++;
	}
	if (result == 21 && buff[index] != '\n')
		return (1);
	if (check_connection(buff))
		return (1);
	return (0);
}

int		check_input(fd)
{
	int		result;
	char	*buff;
	char	cur_char;
	char	**figures;
	int		n_figures;

	n_figures = 0;
	cur_char = 'A';
	buff = ft_strnew(21);
	while ((result = read(fd, buff, 21)) >= 20)
	{
		if (check_file(result, buff))
			return (-1);
		figures[n_figures] = get_coords(ft_strsplit(buff, '\n'), cur_char++);
		n_figures++;
	}
	printf("%d figures\n", n_figures);
	if (n_figures > 26 || result != 0)
		return (-1);
	print_figure_array(figures, n_figures);
	solve_map(make_map(), figures, n_figures);
	return (n_figures);
}