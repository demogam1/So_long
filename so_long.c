/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:17:30 by misaev            #+#    #+#             */
/*   Updated: 2021/08/09 15:46:21 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	get_tab(t_data *map, char *line, char **tmp, char *tab)
{
	int	i;
	int	fd;

	i = 0;
	map->line_length = ft_strlen(line);
	free(line);
	fd = open(tab, O_RDONLY);
	while (i < map->count_line)
	{
		get_next_line(fd, &line);
		tmp[i] = ft_strdup(line);
		if ((int)ft_strlen(tmp[i]) != map->line_length)
		{
			free_tab(tmp);
			ft_putendl_fd("Error : The map is not rectangular", STDERR_FILENO);
			exit(EXIT_FAILURE);
		}
		i++;
		free(line);
	}
}
/* RECUPERATION DE LA MAP */

char	**get_map(char *tab, t_data *map)
{
	char	*line;
	int		fd;
	char	**tmp;

	line = NULL;
	map->count_line = 1;
	fd = open(tab, O_DIRECTORY);
	if (fd != -1)
		print_error(1);
	else
	{
		fd = open(tab, O_RDONLY);
		if (fd == -1)
			print_error(2);
	}
	while (get_next_line(fd, &line) == 1)
	{
		map->count_line++;
		free(line);
	}
	tmp = ft_calloc(sizeof(tmp), map->count_line + 1);
	if (!tmp)
		return (0);
	get_tab(map, line, tmp, tab);
	return (tmp);
}
/* INITIALISATION DE LA STRUCTURE */

void	map_init(t_data *map)
{
	map->wall = "img/wall.xpm";
	map->ground = "img/ground.xpm";
	map->player_down = "img/player_down.xpm";
	map->player_up = "img/player_up.xpm";
	map->player_left = "img/player_left.xpm";
	map->player_right = "img/player_right.xpm";
	map->col = "img/collectible.xpm";
	map->exit = "img/exit.xpm";
	map->mlx = mlx_init();
	map->width = map->line_length * 32;
	map->height = map->count_line * 32;
	map->nbr_y = 0;
	map->nbr_x = 0;
	map->move = 0;
	map->collectible = 0;
	map->nbr_player = 0;
	map->nbr_exit = 0;
}

static void	texture_init(t_data *map)
{
	map->mlx_win = mlx_new_window(map->mlx, map->width,
			map->height, "so_long");
	map->bg_ground = mlx_xpm_file_to_image(map->mlx, map->ground,
			&map->win_width, &map->win_height);
	map->bg_player = mlx_xpm_file_to_image(map->mlx, map->player_down,
			&map->win_width, &map->win_height);
	map->bg_collectible = mlx_xpm_file_to_image(map->mlx, map->col,
			&map->win_width, &map->win_height);
	map->bg_exit = mlx_xpm_file_to_image(map->mlx, map->exit,
			&map->win_width, &map->win_height);
	map->bg_wall = mlx_xpm_file_to_image(map->mlx, map->wall,
			&map->win_width, &map->win_height);
}

/* MAIN */
int	main(int ac, char **av)
{
	t_data	map;
	char	**tab;

	tab = NULL;
	if (ac == 2)
	{
		tab = get_map(av[1], &map);
		check_map_error(tab, &map);
		map_init(&map);
		texture_init(&map);
		nbr_collectible(tab, &map);
		find_player(tab, &map);
		parsing_map(tab, &map);
		mlx_hook(map.mlx_win, 2, 0, deal_key, &map);
		mlx_hook(map.mlx_win, 17, 0, close_win, &map);
		mlx_loop(map.mlx);
		free_tab(tab);
	}
	return (0);
}
