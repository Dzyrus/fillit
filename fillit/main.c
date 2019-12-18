/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lvoyance <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 19:32:53 by lvoyance          #+#    #+#             */
/*   Updated: 2019/12/18 19:32:56 by lvoyance         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_putstr("usage: ./fillit (tetriminos_file)\n");
		return (0);
	}
	if ((check_input(open(av[1], O_RDONLY))) <= 0)
		ft_putstr("error\n");
	return (0);
}
