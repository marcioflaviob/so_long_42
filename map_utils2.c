/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 20:41:03 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/04 12:21:03 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	get_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error\nInvalid file.");
		exit(1);
	}
	return (fd);
}

int	error_display(t_mlx *data)
{
	if (map_checker(data) == 1)
	{
		ft_printf("Error\n");
		ft_printf("Invalid character or map is not surrounded by walls.\n");
		return (1);
	}
	if (map_checker(data) == 2)
	{
		ft_printf("Error\nMap invalid size.\n");
		return (1);
	}
	if (map_checker(data) == 3)
	{
		ft_printf("Error\nMap must have only 1 player and 1 exit,");
		ft_printf(" and at least 1 collectible.\n");
		return (1);
	}
	if (map_checker(data) == 4)
	{
		ft_printf("Error\nMap not solvable.\n");
		return (1);
	}
	if (map_checker(data) == 0)
		ft_printf("All good with the map.\n");
	return (0);
}

void	get_map_size(t_mlx *data)
{
	int	height;

	height = 0;
	while (data->map[height])
		height++;
	data->map_height = height;
	data->map_width = ft_strlen(data->map[0]);
}
