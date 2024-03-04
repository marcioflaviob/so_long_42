/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:41:53 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/25 19:51:21 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.h"

char	**copy_map(char **map)
{
	int		i;
	char	**new_map;

	i = 0;
	while (map[i])
		i++;
	new_map = malloc((i + 1) * sizeof(char *));
	if (!new_map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		new_map[i] = ft_strdup(map[i]);
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

// Algorithm to check if the game is solvable based on the map given
int	path_checker(char **map, int y, int x, t_algo *algo)
{
	if (algo-> c == 0 && algo->e == 1)
		return (1);
	if (map[y - 1][x] == 'E' || map[y + 1][x] == 'E')
		algo->e = 1;
	else if (map[y][x - 1] == 'E' || map[y][x + 1] == 'E')
		algo->e = 1;
	if (map[y][x] == 'C')
		algo->c -= 1;
	map[y][x] = '1';
	if (map[y - 1][x] != '1' && map[y - 1][x] != 'E' && map[y - 1][x] != 'X')
		path_checker(map, (y - 1), x, algo);
	if (map[y + 1][x] != '1' && map[y + 1][x] != 'E' && map[y + 1][x] != 'X')
		path_checker(map, (y + 1), x, algo);
	if (map[y][x - 1] != '1' && map[y][x - 1] != 'E' && map[y][x - 1] != 'X')
		path_checker(map, y, (x - 1), algo);
	if (map[y][x + 1] != '1' && map[y][x + 1] != 'E' && map[y][x + 1] != 'X')
		path_checker(map, y, (x + 1), algo);
	if (algo-> c == 0 && algo->e == 1)
		return (1);
	else
		return (0);
}

t_algo	*algo_init(int c_counter)
{
	t_algo	*algo;

	algo = malloc(sizeof(t_algo));
	if (!algo)
		return (NULL);
	algo->c = c_counter;
	algo->e = 0;
	return (algo);
}

void	find_player(t_mlx *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (data->map[y])
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->x = x;
				data->y = y;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	call_algo(t_mlx *data, int c_counter)
{
	int		result;
	char	**copy;
	t_algo	*algo;

	algo = algo_init(c_counter);
	copy = copy_map(data->map);
	find_player(data);
	result = path_checker(copy, data->y, data->x, algo);
	free_map(copy);
	free(algo);
	return (result);
}
