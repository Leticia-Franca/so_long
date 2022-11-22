/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/10 09:22:28 by lfranca-          #+#    #+#             */
/*   Updated: 2021/10/13 10:02:01 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	ft_close_game(t_game *game)
{
	if (game->player != 0)
		mlx_destroy_image(game->mlx, game->player);
	if (game->wall_tile != 0)
		mlx_destroy_image(game->mlx, game->wall_tile);
	if (game->collect != 0)
		mlx_destroy_image(game->mlx, game->collect);
	if (game->exit != 0)
		mlx_destroy_image(game->mlx, game->exit);
	mlx_destroy_image(game->mlx, game->img_backg.img_ptr);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	ft_free_ptrs(game);
	exit(0);
}

int	main(int argc, char *argv[])
{
	if (argc == 2)
		so_long(argv[1]);
	else
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Inappropriate number of arguments!", 2);
		exit(1);
	}
	return (0);
}
