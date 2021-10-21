/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfranca- <lfranca-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 04:03:47 by lfranca-          #+#    #+#             */
/*   Updated: 2021/10/18 13:02:10 by lfranca-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

static void	map_error(char *message)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(message, 2);
	exit(1);
}

int	ft_store_map(t_game *game, char **line)
{
	int	ret;
	int	i;

	i = -1;
	game->map = (char **)malloc(sizeof(char *) * game->height_map);
	if (!game->map)
	{
		close(game->fd);
		map_error("Allocation for map failed!");
	}
	ret = 1;
	while (ret != 0)
	{
		ret = get_next_line(game->fd, line);
		game->map[++i] = ft_strdup(*line);
		free(*line);
	}
	return (0);
}

int	ft_map_size(t_game *game, char **line, size_t *lg, int *mch)
{
	int	ret;

	ret = 1;
	ret = get_next_line(game->fd, line);
	if (ret == 0 && *lg == 0)
	{
		close(game->fd);
		free(*line);
		map_error("The map file is empty!");
	}
	if (*lg == 0)
		*lg = ft_strlen(*line);
	else if (*lg != ft_strlen(*line))
		*mch = 1;
	free(*line);
	game->height_map++;
	return (ret);
}

int	ft_parse_map(t_game *game, char *filename)
{
	int		ret;
	char	*line;
	size_t	length_map;
	int		sz_file;
	int		match;

	ret = 1;
	match = 0;
	length_map = 0;
	sz_file = ft_strlen(filename);
	game->fd = open(filename, O_RDONLY);
	if (game->fd < 0 || ft_strncmp(".ber", &filename[sz_file - 4], 4))
		map_error("The file didn't open or it isn't .ber!");
	while (ret != 0)
		ret = ft_map_size(game, &line, &length_map, &match);
	close(game->fd);
	if (match == 1)
		map_error("Invalid map configuration!");
	game->width_map = length_map;
	game->fd = open(filename, O_RDONLY);
	if (game->fd < 0)
		map_error("The file didn't open!");
	ft_store_map(game, &line);
	close(game->fd);
	return (0);
}
