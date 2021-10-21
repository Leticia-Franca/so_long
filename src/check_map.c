/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/07 17:31:59 by lfranca-          #+#    #+#             */
/*   Updated: 2021/10/13 09:17:31 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->height_map)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

static void	error_map(t_game *game)
{
	free_map(game);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Invalid map configuration!", 2);
	exit(1);
}

int	ft_check_char(t_game *game, int j, int i)
{
	if (game->map[i][j] != 'P' && game->map[i][j] != 'C' &&
			game->map[i][j] != '1' && game->map[i][j] != 'E')
	{
		error_map(game);
	}
	if (game->map[i][j] == 'C')
		game->qtd_collect++;
	else if (game->map[i][j] == 'E')
		game->qtd_exit++;
	else if (game->map[i][j] == 'P')
	{
		if (game->qtd_player == 1)
			error_map(game);
		else
			game->qtd_player++;
		game->x = j;
		game->y = i;
	}
	return (0);
}

int	ft_check_map(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	if (game->width_map == game->height_map)
		error_map(game);
	while (++i < game->height_map)
	{
		j = -1;
		while (++j < game->width_map)
		{
			if (((i == 0 || i == game->height_map - 1)
					|| (j == 0 || j == game->width_map - 1))
				&& (game->map[i][j] != '1'))
			{
				error_map(game);
			}
			if (game->map[i][j] != '0')
				ft_check_char(game, j, i);
		}
	}
	if (game->qtd_player == 0 || game->qtd_player > 1
		|| game->qtd_exit == 0 || game->qtd_collect == 0)
		error_map(game);
	return (0);
}
