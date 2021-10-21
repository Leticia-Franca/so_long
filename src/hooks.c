/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 20:24:35 by lfranca-          #+#    #+#             */
/*   Updated: 2021/10/18 12:53:04 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	ft_print_steps(t_game *game)
{
	char	*steps;

	steps = ft_itoa(game->steps);
	write (1, steps, ft_strlen(steps));
	write(1, "\n", 1);
	free(steps);
}

void	ft_free_ptrs(t_game *game)
{
	int	i;

	i = 0;
	free(game->mlx);
	while (i < game->height_map)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

void	player_coord(t_game *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->qtd_collect == 0)
		{
			ft_putendl_fd("Game Cleared!", 1);
			ft_close_game(game);
		}
	}
	if (game->map[y][x] == 'C' || game->map[y][x] == '0')
	{
		if (game->map[y][x] == 'C')
		{
			game->qtd_collect--;
		}
		game->map[game->y][game->x] = '0';
		game->map[y][x] = 'P';
		game->x = x;
		game->steps++;
		ft_print_steps(game);
		mlx_destroy_image(game->mlx, game->img_backg.img_ptr);
		ft_draw_map(game);
	}
}

int	key_moves(int keycode, t_game *game)
{
	if (keycode == KEY_W)
		player_coord(game, game->x, game-> y - 1);
	if (keycode == KEY_S)
		player_coord(game, game->x, game-> y + 1);
	if (keycode == KEY_A)
		player_coord(game, game->x - 1, game->y);
	if (keycode == KEY_D)
		player_coord(game, game->x + 1, game->y);
	if (keycode == KEY_ESC)
		ft_close_game (game);
	return (0);
}
