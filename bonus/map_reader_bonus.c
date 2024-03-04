/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:41:47 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/04 12:20:27 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../map.h"
// #include "get_next_line.c" //to delete
// #include "map_utils.c" //to delete
// #include "algorithm.c" //to delete
// #include "ft_split.c" //to delete

// If there's a problem it returns 1.
int	char_checker(char *line)
{
	int		i;
	int		j;
	char	*chars;

	i = 0;
	chars = "10PECX";
	while (line[i])
	{
		j = 0;
		while (chars[j])
		{
			if (line[i] == chars[j])
				break ;
			j++;
		}
		if (!chars[j])
			return (1);
		i++;
	}
	if (line[i - 1] != '1' || line[0] != '1')
		return (1);
	return (0);
}

// If there's a problem it returns 1.
int	first_and_last_checker(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[0][j])
	{
		if (map[0][j++] != '1')
			return (1);
	}
	while (map[i])
		i++;
	i--;
	j = 0;
	while (map[i][j])
	{
		if (map[i][j++] != '1')
			return (1);
	}
	return (0);
}

void	initializer(int *i, int *p, int *e, int *c)
{
	*i = 0;
	*p = 0;
	*e = 0;
	*c = 0;
}

// If there's a char problem it returns 1, if it's not a rectangle it returns 2.
// Returns 3 for problems with player counter, exits or collectibles.
int	map_checker(t_mlx *data)
{
	int	i;
	int	size;
	int	p_counter;
	int	e_counter;
	int	c_counter;

	initializer(&i, &p_counter, &e_counter, &c_counter);
	size = ft_strlen(data->map[i]);
	if (first_and_last_checker(data->map))
		return (1);
	while (data->map[i])
	{
		if (char_checker(data->map[i]) == 1)
			return (1);
		if (ft_strlen(data->map[i]) != size)
			return (2);
		counter(&p_counter, &e_counter, &c_counter, data->map[i]);
		i++;
	}
	data->c = c_counter;
	if (p_counter != 1 || e_counter != 1 || c_counter == 0)
		return (3);
	if (!call_algo(data, c_counter))
		return (4);
	return (0);
}

char	**save_map(char *file)
{
	int		fd;
	int		i;
	char	*temp;
	char	*line;
	char	**map;

	fd = get_fd(file);
	i = 0;
	line = malloc(1 * sizeof(char));
	line[0] = 0;
	while (1)
	{
		temp = get_next_line(fd);
		if (!temp)
			break ;
		line = ft_strjoin(line, temp);
		free(temp);
	}
	free(temp);
	map = ft_split(line, '\n');
	free(line);
	close(fd);
	return (map);
}
