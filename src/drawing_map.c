/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 14:08:03 by lfranca-          #+#    #+#             */
/*   Updated: 2021/10/18 12:54:15 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_put_tile(t_game *game, int x, int y, char ch)
{
	if (ch == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->collect, x, y);
	else if (ch == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->wall_tile, x, y);
	else if (ch == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->exit, x, y);
	else if (ch == 'P')
		mlx_put_image_to_window(game->mlx, game->win, game->player, x, y);
}

void	ft_color_back(t_game *game)
{
	int	count_w;
	int	count_h;

	count_h = -1;
	game->img_backg.img_ptr = mlx_new_image(game->mlx, game->width_map * 32,
			game->height_map * 32);
	game->img_backg.addr = (int *)mlx_get_data_addr(game->img_backg.img_ptr,
			&game->img_backg.bpp, &game->img_backg.size_l,
			&game->img_backg.endian);
	while (++count_h < (game->height_map * 32))
	{
		count_w = -1;
		while (++count_w < (game->width_map * 32))
		{
			game->img_backg.addr[count_h * (game->width_map * 32)
				+ count_w] = 0x000000;
		}
	}
	mlx_put_image_to_window(game->mlx, game->win,
		game->img_backg.img_ptr, 0, 0);
}

void	ft_draw_map(t_game *game)
{
	int	x;
	int	y;

	ft_color_back(game);
	y = -1;
	while (++y < game->height_map)
	{
		x = -1;
		while (++x < game->width_map)
		{
			if (game->map[y][x] == '1')
				ft_put_tile(game, x * 32, y * 32, '1');
			else if (game->map[y][x] == 'E')
				ft_put_tile(game, x * 32, y * 32, 'E');
			else if (game->map[y][x] == 'C')
				ft_put_tile(game, x * 32, y * 32, 'C');
			else if (game->map[y][x] == 'P')
			{
				game->x = x;
				game->y = y;
				ft_put_tile(game, x * 32, y * 32, 'P');
			}
		}
	}
}
