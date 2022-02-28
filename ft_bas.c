/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 17:03:25 by misaev            #+#    #+#             */
/*   Updated: 2021/08/09 10:42:16 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_bas_extension(t_data *map)
{
	if (check_map_for_move(map, map->nbr_y, map->nbr_x) == 3)
	{
		map->collectible--;
		map->tab[map->nbr_y][map->nbr_x] = 'P';
		map->tab[map->nbr_y - 1][map->nbr_x] = '0';
	}
	else if (check_map_for_move(map, map->nbr_y, map->nbr_x)
		== 2 && !map->collectible)
	{
		free_tab(map->tab);
		exit(EXIT_SUCCESS);
	}
	else
	{
		if (map->tab[map->nbr_y - 1][map->nbr_x] != 'E'
			&& map->tab[map->nbr_y][map->nbr_x] != 'E')
		{
			map->tab[map->nbr_y][map->nbr_x] = 'P';
			map->tab[map->nbr_y - 1][map->nbr_x] = '0';
		}
	}
	map->bg_player = mlx_xpm_file_to_image(map->mlx, map->player_down,
			&map->win_width, &map->win_height);
}

void	ft_bas(t_data *map)
{
	map->nbr_y++;
	if (check_map_for_move(map, map->nbr_y, map->nbr_x) == 2
		&& map->collectible)
		map->nbr_y--;
	else if (check_map_for_move(map, map->nbr_y, map->nbr_x) == 0)
		map->nbr_y--;
	else if (check_map_for_move(map, map->nbr_y, map->nbr_x))
	{
		ft_bas_extension(map);
		parsing_map(map->tab, map);
		map->move++;
		print_info(map);
	}
}
