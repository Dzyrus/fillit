#include "fillit.h"

int		solver(char **map, char **figures, int n_figures, int curr_size, int n)
{
	int y;
	int x;

	y = 0;
	if (n >= n_figures)
		return (1);
	while (y < curr_size)
	{
		x = 0;
		while (x < curr_size)
		{
			if (is_place(figures[n], map, curr_size, y, x))
			{
				n++;
				if (solver(map, figures, n_figures, curr_size, n))
					return (1);
				else
					put_figure(figures[--n], map, '.', y, x);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		solve_map(char **map, char **figures, int n_figures)
{
	int curr_size;
	int n;
	int rowindex;

	rowindex = 0;
	n = 0;
	curr_size = map_size(n_figures);
	while (!solver(map, figures, n_figures, curr_size, n))
	{
		curr_size++;
		make_map();
	}
	while (rowindex < curr_size)
	{
		map[rowindex][curr_size] = '\n';
		map[rowindex][curr_size + 1] = '\0';
		rowindex++;
	}
	print_array(map, curr_size);
	return (0);
}
