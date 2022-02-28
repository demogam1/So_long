/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:03:27 by misaev            #+#    #+#             */
/*   Updated: 2021/08/06 12:54:17 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
/* PARCOURIRE LA MATRICE POUR L'ÁFFICHAGE */
void	parsing_map(char **tab, t_data *map)
{
	int	i;
	int	j;

	i = 0;
	map-> y = 0;
	while (tab[i])
	{
		j = 0;
		map-> x = 0;
		while (tab[i][j])
		{
			display_map(tab, map, i, j);
			j++;
			map-> x += PXL;
		}
		map->y += PXL;
		i++;
	}
	map->tab = tab;
}
/* AFFICHER LA MAP */

void	display_map(char **tab, t_data *map, int y, int x)
{
	if (tab[y][x] == '1')
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->bg_wall, map->x, map->y);
	else if (tab[y][x] == '0')
		ft_display_ground(map);
	else if (tab[y][x] == 'P')
	{
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->bg_ground, map->x, map->y);
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->bg_player, map->x, map->y);
	}
	else if (tab[y][x] == 'C')
	{
		ft_display_ground(map);
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->bg_collectible, map->x, map->y);
	}
	else if (tab[y][x] == 'E')
	{
		ft_display_ground(map);
		mlx_put_image_to_window(map->mlx, map->mlx_win,
			map->bg_exit, map->x, map->y);
	}
}
/* CHECKER LE NBR DE COLLECTIBLE ET D'EXIT */

void	nbr_collectible(char **tab, t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'C')
				map->collectible++;
			else if (tab[i][j] == 'E')
				map->nbr_exit++;
			j++;
		}
		i++;
	}
	if (map->collectible <= 0 || map->nbr_exit > 1
		|| map->nbr_exit < 1)
	{
		free_tab(tab);
		ft_putendl_fd("Map incorrecte !", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
/* CHECKER LA POSITION ET LE NOMBRE DE JOUEUR */

void	find_player(char **tab, t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == 'P')
			{
				map->nbr_x += j;
				map->nbr_y += i;
				map->nbr_player++;
			}
			j++;
		}
		i++;
	}
	if (map->nbr_player == 0 || map->nbr_player > 1)
	{
		free_tab(tab);
		ft_putendl_fd("Map incorrecte !", STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
/* DISPLAY GROUND */

void	ft_display_ground(t_data *map)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win,
		map->bg_ground, map->x, map->y);
}
