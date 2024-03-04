SRCS += ft_printf/ft_printf.c
SRCS += ft_printf/ft_putchar.c
SRCS += ft_printf/ft_putnbr_base.c
SRCS += ft_printf/ft_putnbr.c
SRCS += ft_printf/ft_putstr.c
SRCS += ft_printf/ft_putunsnbr.c
SRCS += ft_printf/ft_putnbr_p.c

SRCS += get_next_line/get_next_line.c
SRCS += get_next_line/get_next_line_utils.c

SRCS += ft_itoa.c
SRCS += ft_split.c
SRCS += map_utils.c
SRCS += map_utils2.c
SRCS += movement.c
SRCS += window.c
SRCS += so_long.c
SRCS += window_utils.c

SRCS += map_reader.c
SRCS += algorithm.c

SRCS_BONUS += ft_printf/ft_printf.c
SRCS_BONUS += ft_printf/ft_putchar.c
SRCS_BONUS += ft_printf/ft_putnbr_base.c
SRCS_BONUS += ft_printf/ft_putnbr.c
SRCS_BONUS += ft_printf/ft_putstr.c
SRCS_BONUS += ft_printf/ft_putunsnbr.c
SRCS_BONUS += ft_printf/ft_putnbr_p.c

SRCS_BONUS += get_next_line/get_next_line.c
SRCS_BONUS += get_next_line/get_next_line_utils.c

SRCS_BONUS += ft_itoa.c
SRCS_BONUS += ft_split.c
SRCS_BONUS += map_utils.c
SRCS_BONUS += map_utils2.c
SRCS_BONUS += movement.c
SRCS_BONUS += window.c
SRCS_BONUS += window_utils.c
SRCS_BONUS += so_long.c

SRCS_BONUS += bonus/map_reader_bonus.c
SRCS_BONUS += bonus/algorithm_bonus.c

OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.c=.o))
OBJS_BONUS	= $(addprefix $(OBJDIR)/, $(SRCS_BONUS:.c=.o))

OBJDIR		= objects

NAME		= so_long

INCLUDES	= ./

HEADER		+= $(INCLUDES)ft_printf/ft_printf.h
HEADER		+= $(INCLUDES)get_next_line/get_next_line.h
HEADER		+= $(INCLUDES)minilibx-linux/mlx.h
HEADER		+= $(INCLUDES)map.h

MINILIBX	= minilibx-linux
LIBMLX		= $(MINILIBX)/libmlx_Linux.a

CC			= cc

CFLAGS		+= -Wall
CFLAGS		+= -Wextra
CFLAGS		+= -Werror

LDFLAGS		+= -Lminilibx-linux
LDFLAGS		+= -lmlx_Linux
LDFLAGS		+= -lX11
LDFLAGS		+= -lXext

$(NAME): $(LIBMLX) $(OBJS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS) $(LIBMLX)

$(OBJDIR)/%.o: %.c $(HEADER)
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(INCLUDES) -c $< -o $@

$(LIBMLX):
	$(MAKE) -C $(MINILIBX)

bonus: $(LIBMLX) $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $(NAME) $(OBJS_BONUS) $(LIBMLX)

clean:
	$(MAKE) -C $(MINILIBX) clean
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(MAKE) -C $(MINILIBX) clean
	rm -f $(NAME) $(BONUS)
	rm -rf $(OBJDIR)

re:				fclean all

.PHONY:			all clean fclean re custom