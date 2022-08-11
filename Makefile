# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wjuneo-f <wjuneo-f@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 22:47:58 by bankai            #+#    #+#              #
#    Updated: 2022/08/11 12:59:04 by wjuneo-f         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIBFT				=	./libft/libft.a
SOURCS				=	main.c creat_paths.c pipex.c find_cmd.c ultils.c

OBJS_DIR			=	objects
OBJS				=	$(patsubst %.c, objects/%.o, $(SOURCS))

CC					=	cc -g3
CFLAGS				=	-Wall -Wextra -Werror

RM					=	rm -rf

NAME				=	pipex

VPATH				=	. ./sourcs

$(OBJS_DIR)/%.o:	%.c
						$(CC) $(CFLAGS) -c $< -o $@

all:				$(NAME)

$(NAME):			$(LIBFT) $(OBJS_DIR) $(OBJS)
						$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $@

$(LIBFT):
						$(MAKE) -C ./libft all

$(OBJS_DIR):
						mkdir -p objects

bonus:
						make all

clean:
						$(MAKE) -C ./libft clean

fclean:				clean
						$(RM) $(NAME)
						$(RM) $(LIBFT)

re:					clean fclean all re bonus
