/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 21:46:14 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/25 20:02:05 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

///*TO COMPILE c *.c *.h ft_printf/*.c ft_printf/*.h 
//get_next_line/*.c get_next_line/*.h
//-Lminilibx-linux -lmlx_Linux -lX11 -lXext */
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
	data.map = save_map(file);
	data.moves = 0;
	get_map_size(&data);
	if (error_display(&data))
	{
		free_map(data.map);
		return (0);
	}
	window_init(&data);
}
