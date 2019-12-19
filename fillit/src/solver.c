/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvoyance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 15:09:22 by lvoyance          #+#    #+#             */
/*   Updated: 2019/12/18 15:09:24 by lvoyance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		solver(char **map, char **figures, int n_figures, int n)
{
	int y;
	int x;

	y = 0;
	if (n >= n_figures)
		return (1);
	while (y < ft_word_len(map[0], '!'))
	{
		x = 0;
		while (x < ft_word_len(map[0], '!'))
		{
			if (is_place(figures[n], map, y, x))
			{
				n++;
				if (solver(map, figures, n_figures, n))
					return (1);
				else
					delete_figure(figures[--n], map, y, x);
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
	while (!solver(make_map(curr_size), figures, n_figures, n))
		make_map(curr_size++);
	while (rowindex < curr_size)
	{
		map[rowindex][curr_size] = '\n';
		map[rowindex][curr_size + 1] = '\0';
		rowindex++;
	}
	print_array(map, curr_size);
	return (0);
}

int		map_size(int n_figures)
{
	int n;
	int i;

	i = 2;
	n = n_figures * 4;
	while (i * i < n)
		i++;
	return (i);
}
