//
// Created by Laquanda Voyance on 02/12/2019.
//

#include "fillit.h"



char	*get_coords(char **str, char value)
{
	int rowindex;
	int index;
	char *coords;
	int n;

	coords = ft_strnew(9);
	n = 0;
	rowindex = 0;
	while (str[rowindex] != 0)
	{
		index = 0;
		while (str[rowindex][index] != '\0')
		{
			if (str[rowindex][index++] == '#')
			{
				coords[n++] = (char)rowindex;
				coords[n++] = (char)(index - 1);
			}
		}
		rowindex++;
	}
	coords[n] = value;
	return (coords);
}

int 	map_size(int	n_figures)
{
	int n;
	int i;

	i = 2;
	n = n_figures * 4;
	while (i * i < n)
		i++;
	return (i);
}

int		is_place(char *figure, char	**map, int map_size, int y_map, int x_map, int n)
{
	int index;
	int dy;
	int dx;

	index = 0;
	dy = y_map - figure[0];
	dx = x_map - figure[1];
	while (index < 8)
	{
		if (figure[index] + dy >= map_size || figure[index + 1] + dx >= map_size || figure[index] + dy < 0 || figure[index + 1] + dx < 0 )
			return (0);
		if (map[figure[index] + dy][figure[index + 1] + dx] >= 'A' && map[figure[index] + dy][figure[index + 1] + dx] <= 'Z')
			return (0);
		index += 2;
	}
	put_figure(figure, map, map_size, y_map, x_map);

	return (1);
}
int		put_figure(char *figure, char	**map, int map_size, int y_map, int x_map)
{
	int index;
	int dy;
	int dx;

	index = 0;
	dy = y_map - figure[0];
	dx = x_map - figure[1];
//	while (index < 8)
//	{
//		if (figure[index] + dy >= map_size || figure[index + 1] + dx >= map_size)
//			return (0);
//		if (map[figure[index] + dy][figure[index + 1] + dx] >= 'A' && map[figure[index] + dy][figure[index + 1] + dx] <= 'Z')
//			return (0);
//		index += 2;
//	}
	index = 0;
	while (index < 8)
	{
		map[figure[index] + dy][figure[index + 1] + dx] = figure[8];
		index += 2;
	}
	return (1);
}

char	**make_map()
{
	int rowindex;
	static char 	*map[13];

	rowindex = 0;

	while (rowindex < 13)
	{
		map[rowindex] = ft_strnew(13);
		rowindex++;
	}
	map[13] = '\0';
	rowindex = 0;
	while (rowindex < 13)
	{
		int index = 0;
		while (index < 12)
		{
			map[rowindex][index] = '.';
			index++;
		}
		map[rowindex][12] = '\n';
		rowindex++;
	}
	//print_array(map, 12);
	return (map);
}

int 	solver(char **map, char **figures, int n_figures, int curr_size, int n)
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
			if (is_place(figures[n], map, curr_size, y, x, n))
			{
				n++;
				if (solver(map, figures, n_figures, curr_size, n))
					return (1);
				else
				{
					make_map();
					n--;
				}


			}
			x++;
		}
		y++;
	}

	return (0);
}

int 	solve_map(char **map, char **figures, int n_figures)
{
	char *tmp;
	int curr_size;
	int n;
	int rowindex = 0;
	n = 0;
	curr_size = map_size(n_figures);
	while(!solver(map, figures, n_figures, curr_size, n))
	{
		curr_size++;
		make_map();
	}

	while (rowindex < curr_size)
	{
		int index = 0;

		map[rowindex][curr_size] = '\n';
		map[rowindex][curr_size + 1] = '\0';
		rowindex++;
	}
	print_array(map, curr_size);
	return (0);
}