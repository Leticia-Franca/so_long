/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 04:06:00 by lfranca-          #+#    #+#             */
/*   Updated: 2021/10/18 13:04:13 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	*ft_init_imgs(t_game *game, char *pathname)
{
	int		height;
	int		width;
	void	*img_element;

	img_element = mlx_xpm_file_to_image(game->mlx, pathname, &width, &height);
	if (width == 0 || height == 0)
	{
		free_map(game);
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Image file didn't open!", 2);
		exit(1);
	}
	return (img_element);
}

void	ft_init_imgptrs(t_game *game)
{
	game->player = ft_init_imgs(game,
			"./img_files/xpm_arquivos/minotaur_back.xpm");
	game->collect = ft_init_imgs(game,
			"./img_files/xpm_arquivos/red_heart.xpm");
	game->exit = ft_init_imgs(game,
			"./img_files/xpm_arquivos/exit_transparent.xpm");
	game->wall_tile = ft_init_imgs(game,
			"./img_files/xpm_arquivos/wall_01.xpm");
}

static void	ft_init_values_game(t_game *game)
{
	game->qtd_player = 0;
	game->qtd_exit = 0;
	game->qtd_collect = 0;
	game->height_map = 0;
	game->width_map = 0;
	game->steps = 0;
	game->player = 0;
	game->collect = 0;
	game->exit = 0;
	game->wall_tile = 0;
}

static int	minimixe_win(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img_backg.img_ptr);
	ft_draw_map(game);
	return (0);
}

int	so_long(char *filename)
{
	t_game	game;

	ft_init_values_game(&game);
	ft_parse_map(&game, filename);
	ft_check_map(&game);
	game.mlx = mlx_init();
	ft_init_imgptrs(&game);
	game.win = mlx_new_window(game.mlx, game.width_map * 32,
			game.height_map * 32, "So_Long");
	ft_draw_map(&game);
	mlx_hook(game.win, 2, 1L << 0, key_moves, &game);
	mlx_hook(game.win, 17, 1L << 0, ft_close_game, &game);
	mlx_expose_hook(game.win, minimixe_win, &game);
	mlx_loop(game.mlx);
	return (0);
}
