/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:00:50 by misaev            #+#    #+#             */
/*   Updated: 2021/08/09 15:32:45 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* CONFIGURATION DES TOUCHES */
int	deal_key(int keycode, t_data *map)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == W_KEY)
		ft_haut(map);
	if (keycode == A_KEY)
		ft_gauche(map);
	if (keycode == S_KEY)
		ft_bas(map);
	if (keycode == D_KEY)
		ft_droite(map);
	return (0);
}
/* AFFICHER LE NBR DE DEPLACEMENT ET LE NBR DE COLLECTIBLE RESTANT */

void	print_info(t_data *map)
{
	write(STDOUT_FILENO, "Number of move : ", 17);
	ft_putnbr_fd(map->move, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
	write(STDOUT_FILENO, "Collectible remaining : ", 24);
	ft_putnbr_fd(map->collectible, STDOUT_FILENO);
	write(STDOUT_FILENO, "\n", 1);
}
/* CHECKER SI LE DEPLACEMENT EST POSSIBLE */

int	check_map_for_move(t_data *map, int y, int x)
{
	if (map->tab[y][x] == '0' || map->tab[y][x] == 'P')
		return (1);
	else if (map->tab[y][x] == 'E')
		return (2);
	else if (map->tab[y][x] == 'C')
		return (3);
	return (0);
}
/* AFFICHER LES MSG D ERREUR DIR ET FILE */

void	print_error(int c)
{
	if (c == 1)
	{
		ft_putendl_fd("Error directory", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	if (c == 2)
	{
		ft_putendl_fd("Error file", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
