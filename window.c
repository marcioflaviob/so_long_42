/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 21:24:55 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/25 19:29:27 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	fill_background(t_mlx *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_height)
	{
		j = 0;
		while (j < data->map_width)
		{
			mlx_put_image_to_window(data->con, data->win,
				data->img_floor, j * 80, i * 80);
			j++;
		}
		i++;
	}
}

void	fill_others(t_mlx *data, int *i, int *j)
{
	while (data->map[*i])
	{
		*j = 0;
		while (data->map[*i][*j])
		{
			if (data->map[*i][*j] == 'C')
				mlx_put_image_to_window(data->con, data->win,
					data->img_mask, *j * 80, *i * 80);
			if (data->map[*i][*j] == 'E')
				mlx_put_image_to_window(data->con, data->win,
					data->img_chair, *j * 80, *i * 80);
			if (data->map[*i][*j] == '1')
				mlx_put_image_to_window(data->con, data->win,
					data->img_box, *j * 80, *i * 80);
			if (data->map[*i][*j] == 'X')
				mlx_put_image_to_window(data->con, data->win,
					data->img_virus, *j * 80, *i * 80);
			if (data->map[*i][*j] == 'P')
				mlx_put_image_to_window(data->con, data->win,
					data->img_cright, *j * 80, *i * 80);
			*j += 1;
		}
		*i += 1;
	}
}

void	get_img(t_mlx *data)
{
	int	a;
	int	b;

	a = 80;
	b = 80;
	data->img_floor = mlx_xpm_file_to_image(data->con,
			"textures/floor.xpm", &a, &b);
	data->img_mask = mlx_xpm_file_to_image(data->con,
			"textures/mask.xpm", &a, &b);
	data->img_chair = mlx_xpm_file_to_image(data->con,
			"textures/chair.xpm", &a, &b);
	data->img_box = mlx_xpm_file_to_image(data->con,
			"textures/box.xpm", &a, &b);
	data->img_virus = mlx_xpm_file_to_image(data->con,
			"textures/virus.xpm", &a, &b);
	data->img_cright = mlx_xpm_file_to_image(data->con,
			"textures/char_right.xpm", &a, &b);
	data->img_cleft = mlx_xpm_file_to_image(data->con,
			"textures/char_left.xpm", &a, &b);
}

void	error_con(t_mlx *data)
{
	free_map(data->map);
	ft_printf("Error\nCouldn't start minilibx.");
	exit(1);
}

void	window_init(t_mlx *data)
{
	int	i;
	int	j;

	data->con = mlx_init();
	if (data->con == NULL)
		error_con(data);
	data->win = mlx_new_window(data->con, (data->map_width * 80),
			(data->map_height * 80), "so_long");
	if (data->win == NULL)
	{
		mlx_destroy_display(data->con);
		free(data->con);
		ft_printf("Error\nCouldn't open the window.");
		free_map(data->map);
		exit(1);
	}
	get_img(data);
	fill_background(data);
	i = 0;
	j = 0;
	fill_others(data, &i, &j);
	mlx_key_hook(data->win, handle_input, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask,
		close_x, data);
	mlx_loop(data->con);
}
