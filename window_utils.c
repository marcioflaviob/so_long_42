/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 17:21:46 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/25 19:46:16 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	free_imgs(t_mlx *data)
{
	mlx_destroy_image(data->con, data->img_box);
	mlx_destroy_image(data->con, data->img_chair);
	mlx_destroy_image(data->con, data->img_cleft);
	mlx_destroy_image(data->con, data->img_cright);
	mlx_destroy_image(data->con, data->img_floor);
	mlx_destroy_image(data->con, data->img_mask);
	mlx_destroy_image(data->con, data->img_virus);
}

int	close_window(t_mlx *data, int a)
{
	if (a == 1)
		ft_printf("You lost the game.");
	if (a == 2)
		ft_printf("You won the game.");
	free_imgs(data);
	mlx_destroy_window(data->con, data->win);
	mlx_destroy_display(data->con);
	free(data->con);
	free_map(data->map);
	exit(1);
	return (0);
}

int	close_x(t_mlx *data)
{
	ft_printf("You closed the game.");
	free_imgs(data);
	mlx_destroy_window(data->con, data->win);
	mlx_destroy_display(data->con);
	free(data->con);
	free_map(data->map);
	exit(1);
	return (0);
}

void	moves_counter(t_mlx *data)
{
	char	*counter;

	data->moves++;
	counter = ft_strjoin(ft_itoa(data->moves), " moves.");
	mlx_put_image_to_window(data->con, data->win, data->img_box, 0, 0);
	mlx_string_put(data->con, data->win, 13, 40, 0, counter);
	free(counter);
}
