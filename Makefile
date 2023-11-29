#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aperis <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 19:12:16 by aperis            #+#    #+#              #
#    Updated: 2022/01/27 16:33:34 by aperis           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = init.c move.c mainbis.c parsing.c get_next_line.c \
			utils.c ft_printf.c list.c 
OBJS 		= ${SRCS:.c=.o}

CC 			= clang
CFLAGS		= -Wall -Wextra -Werror 
RM			= rm -f
NAME		= so_long
FLAGS		= -Imlx -Lmlx -lmlx -lXext -lX11

all: 		${NAME}

.c.o:
			${CC} ${CFLAGS} -Imlx -c $< -o ${<:.c=.o}

$(NAME): 	$(OBJS)
				make -C "./mlx/"
			${CC} $(CFLAGS) -o $(NAME) $(OBJS) $(FLAGS)

clean:
			${RM} ${OBJS}

fclean: 	clean
			${RM} ${NAME}

re: 		fclean all
