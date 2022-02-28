/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: misaev <misaev@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:25:34 by hkrifa            #+#    #+#             */
/*   Updated: 2021/08/09 15:21:36 by misaev           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define 	ESC 53
# define 	W_KEY 13
# define 	A_KEY 0
# define 	S_KEY 1
# define 	D_KEY 2
# define 	PXL 32

# include 	<mlx.h>
# include	<fcntl.h>
# include	<stdio.h>
# include	"libft/libft.h"

typedef struct s_data {
	void	*img;
	char	*addr;
	char	*wall;
	char	*ground;
	char	*col;
	char	*exit;
	char	*player_down;
	char	*player_up;
	char	*player_left;
	char	*player_right;
	char	**tab;
	void	*mlx;
	void	*mlx_win;
	void	*bg_ground;
	void	*bg_player;
	void	*bg_collectible;
	void	*bg_exit;
	void	*bg_wall;
	int		nbr_player;
	int		nbr_exit;
	int		move;
	int		collectible;
	int		width;
	int		height;
	int		x;
	int		y;
	int		line_length;
	int		count_line;
	int		nbr_y;
	int		nbr_x;
	int		win_width;
	int		win_height;
}	t_data;
void	free_tab(char **tab);
void	find_player(char **tab, t_data *map);
void	check_parsing_type(char	**tab, t_data *map);
void	print_info(t_data	*map);
void	ft_haut(t_data	*map);
void	ft_gauche(t_data	*map);
void	ft_bas(t_data *map);
void	ft_droite(t_data	*map);
void	nbr_collectible(char **tab, t_data *map);
void	ft_display_ground(t_data *map);
void	parsing_map(char **tab, t_data *map);
void	display_map(char **tab, t_data *map, int y, int x);
int		check_map_for_move(t_data *map, int y, int x);
int		deal_key(int keycode, t_data *map);
int		check_map_error(char **tab, t_data *map);
int		close_win(void);
void	print_error(int c);
#endif