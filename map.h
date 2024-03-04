/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h		                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrandao <mbrandao@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:07:05 by mbrandao          #+#    #+#             */
/*   Updated: 2024/02/22 19:57:59 by mbrandao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stddef.h>
# include <sys/time.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include "minilibx-linux/mlx.h"
# include "get_next_line/get_next_line.h"
# include "ft_printf/ft_printf.h"
//# include "get_next_line.h"

typedef struct s_algo
{
	int		c;
	int		e;
}	t_algo;

typedef struct s_mlx
{
	void	*con;
	void	*win;
	char	**map;
	int		moves;
	int		c;
	int		map_width;
	int		map_height;
	int		x;
	int		y;
	int		*img_floor;
	int		*img_mask;
	int		*img_chair;
	int		*img_box;
	int		*img_virus;
	int		*img_cleft;
	int		*img_cright;
}	t_mlx;

int		call_algo(t_mlx *data, int c_counter);
char	*ft_strdup(const char *s1);
void	counter(int	*p, int *e, int *c, char *line);
void	print_map(char **map);
char	**ft_split(char const *s, char const c);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
void	free_map(char **map);
int		get_fd(char *file);
void	get_map_size(t_mlx *data);
void	find_player(t_mlx *data);
char	*ft_itoa(int n);
int		error_display(t_mlx *data);
int		handle_input(int key, t_mlx *data);
void	window_init(t_mlx *data);
int		map_checker(t_mlx *data);
char	**save_map(char *file);
void	get_map_size(t_mlx *data);
int		close_window(t_mlx *data, int a);
int		close_x(t_mlx *data);
void	moves_counter(t_mlx *data);

#endif