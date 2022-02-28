/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 13:06:29 by misaev            #+#    #+#             */
/*   Updated: 2021/08/09 15:31:37 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*  FONCTION POUR LA SORTIE DU JEUX */

int	close_win(void)
{
	exit(0);
}
/* FREE LA MATRICE */

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		tab[i] = NULL;
		i++;
	}
	free(tab);
}

/* EXTENSION DU CHECK MAP ERROR */

static	void	check_map_error_extension(char **tab, int y, int x)
{
	if (tab[y][x] != '0' && tab[y][x] != '1' && tab[y][x] != 'C'
					&& tab[y][x] != 'P' && tab[y][x] != 'E')
	{
		ft_putendl_fd("Error : Invalid character found", STDERR_FILENO);
		free_tab(tab);
		exit (EXIT_FAILURE);
	}
}
/* ------------------------- */

static	void	check_map_error_ext_2(char **tab, t_data *map, int y, int x)
{
	if (y == 0 || x == 0 || y == map->count_line - 1
		|| x == map->line_length - 1)
	{
		if (tab[y][x] != '1')
		{
			ft_putendl_fd("Error : The map is not surrounded by walls",
				STDERR_FILENO);
			free_tab(tab);
			exit (EXIT_FAILURE);
		}
	}
}

/* CHECKER LES ERREUR DE LA MAP */

int	check_map_error(char **tab, t_data *map)
{
	int	i;
	int	j;

	i = 0;
	while (tab[i])
	{
		j = 0;
		while (j < map->line_length)
		{
			check_map_error_ext_2(tab, map, i, j);
			if ((i > 0 && i < map->count_line - 1)
				&& (j > 0 && j < map->line_length - 1))
				check_map_error_extension(tab, i, j);
			j++;
		}
		i++;
	}
	return (1);
}
