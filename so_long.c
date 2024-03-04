/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:46:14 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/04 14:09:51 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

///*TO COMPILE c *.c *.h ft_printf/*.c ft_printf/*.h 
//get_next_line/*.c get_next_line/*.h
//-Lminilibx-linux -lmlx_Linux -lX11 -lXext */

int	check_ber(char *file)
{
	int	len;

	len = ft_strlen(file) - 1;
	if (len < 4)
		return (1);
	if (file[len] != 'r')
		return (1);
	if (file[len - 1] != 'e')
		return (1);
	if (file[len - 2] != 'b')
		return (1);
	if (file[len - 3] != '.')
		return (1);
	return (0);
}

int	error_map(t_mlx *data)
{
	if (!data->map || !data->map[0])
	{
		free(data->map);
		ft_printf("Error\nInvalid map.");
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	char	*file;
	t_mlx	data;

	if (argc != 2)
	{
		ft_printf("Error\nInvalid number of arguments.");
		return (0);
	}
	file = argv[1];
	if (check_ber(file))
	{
		ft_printf("Error\nMap must end in .ber");
		return (0);
	}
	data.map = save_map(file);
	if (error_map(&data))
		return (0);
	data.moves = 0;
	get_map_size(&data);
	if (error_display(&data))
	{
		free_map(data.map);
		return (0);
	}
	window_init(&data);
}
