/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 07:43:34 by lfranca-          #+#    #+#             */
/*   Updated: 2021/10/18 12:55:50 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "./get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ESC 65307

typedef struct s_img {
	void	*img_ptr;
	int		width;
	int		height;
	int		*addr;
	int		bpp;
	int		size_l;
	int		endian;
}				t_img;

typedef struct s_game {
	t_img	img_backg;
	void	*wall_tile;
	void	*player;
	void	*collect;
	void	*exit;
	void	*win;
	void	*mlx;
	int		x;
	int		y;
	int		height_map;
	int		width_map;
	int		fd;
	char	**map;
	int		steps;
	int		qtd_collect;
	int		qtd_player;
	int		qtd_exit;
}				t_game;

int		ft_check_map(t_game *game);
int		ft_check_char(t_game *game, int j, int i);
int		ft_parse_map(t_game *game, char *filename);
void	ft_draw_map(t_game *game);
void	ft_color_back(t_game *game);
void	ft_put_tile(t_game *game, int x, int y, char ch);
int		key_moves(int keycode, t_game *game);
void	player_coord(t_game *game, int x, int y);
int		ft_close_game(t_game *game);
void	ft_print_steps(t_game *game);
int		so_long(char *filename);
void	ft_init_imgptrs(t_game *game);
void	ft_free_ptrs(t_game *game);
void	free_map(t_game *game);

#endif