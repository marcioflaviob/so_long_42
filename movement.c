/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:12:31 by mbrandao          #+#    #+#             */
/*   Updated: 2024/03/04 12:13:53 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	move_up(t_mlx *data)
{
	int	y;
	int	x;

	y = data->y;
	x = data->x;
	if (data->map[y - 1][x] == 'X')
		close_window(data, 1);
	if (data->map[y - 1][x] == 'E' && data->c == 0)
		close_window(data, 2);
	else if (data->map[y - 1][x] != '1' && data->map[y - 1][x] != 'E')
	{
		if (data->map[y - 1][x] == 'C')
			data->c--;
		mlx_put_image_to_window(data->con, data->win,
			data->img_cright, x * 80, (y - 1) * 80);
		mlx_put_image_to_window(data->con, data->win,
			data->img_floor, x * 80, y * 80);
		data->map[y][x] = '0';
		data->map[y - 1][x] = 'P';
		data->y--;
		moves_counter(data);
	}
}

void	move_down(t_mlx *data)
{
	int	y;
	int	x;

	y = data->y;
	x = data->x;
	if (data->map[y + 1][x] == 'X')
		close_window(data, 1);
	if (data->map[y + 1][x] == 'E' && data->c == 0)
		close_window(data, 2);
	else if (data->map[y + 1][x] != '1' && data->map[y + 1][x] != 'E')
	{
		if (data->map[y + 1][x] == 'C')
			data->c--;
		mlx_put_image_to_window(data->con, data->win,
			data->img_cright, x * 80, (y + 1) * 80);
		mlx_put_image_to_window(data->con, data->win,
			data->img_floor, x * 80, y * 80);
		data->map[y][x] = '0';
		data->map[y + 1][x] = 'P';
		data->y++;
		moves_counter(data);
	}
}

void	move_left(t_mlx *data)
{
	int	y;
	int	x;

	y = data->y;
	x = data->x;
	if (data->map[y][x - 1] == 'X')
		close_window(data, 1);
	if (data->map[y][x - 1] == 'E' && data->c == 0)
		close_window(data, 2);
	else if (data->map[y][x - 1] != '1' && data->map[y][x - 1] != 'E')
	{
		if (data->map[y][x - 1] == 'C')
			data->c--;
		mlx_put_image_to_window(data->con, data->win,
			data->img_cleft, (x - 1) * 80, y * 80);
		mlx_put_image_to_window(data->con, data->win,
			data->img_floor, x * 80, y * 80);
		data->map[y][x] = '0';
		data->map[y][x - 1] = 'P';
		data->x--;
		moves_counter(data);
	}
}

void	move_right(t_mlx *data)
{
	int	y;
	int	x;

	y = data->y;
	x = data->x;
	if (data->map[y][x + 1] == 'X')
		close_window(data, 1);
	if (data->map[y][x + 1] == 'E' && data->c == 0)
		close_window(data, 2);
	else if (data->map[y][x + 1] != '1' && data->map[y][x + 1] != 'E')
	{
		if (data->map[y][x + 1] == 'C')
			data->c--;
		mlx_put_image_to_window(data->con, data->win,
			data->img_cright, (x + 1) * 80, y * 80);
		mlx_put_image_to_window(data->con, data->win,
			data->img_floor, x * 80, y * 80);
		data->map[y][x] = '0';
		data->map[y][x + 1] = 'P';
		data->x++;
		moves_counter(data);
	}
}

int	handle_input(int key, t_mlx *data)
{
	if (key == XK_Escape)
	{
		ft_printf("You pressed ESC and closed the game\n");
		close_window(data, 0);
		exit(1);
	}
	else if (key == 119)
		move_up(data);
	else if (key == 115)
		move_down(data);
	else if (key == 97)
		move_left(data);
	else if (key == 100)
		move_right(data);
	return (0);
}
