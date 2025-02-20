# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abouclie <abouclie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/20 09:07:20 by abouclie          #+#    #+#              #
#    Updated: 2025/02/20 15:56:46 by abouclie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CC		=	cc
FLAGS	=	-Wall -Wextra -Werror
REMOVE	=	rm -f

SRCS	=	ft_bzero.c \
			ft_strccpy.c \
			ft_strdup.c \
			ft_strjoin.c \
			ft_strlen.c \
			ft_strnstr.c \
			get_next_line.c \
			printf/ft_intlen.c \
			printf/ft_itoa_base.c \
			printf/ft_itoa_ptr.c \
			printf/ft_print_ptr \
			printf/ft_printf \
			printf/ft_printnbr \
			printf/ft_printstr \
			printf/ft_ptrlen \
			printf/ft_putstr
OBJS	=	$(SRCS:.c=.o)

all:	${NAME}

${NAME}:	${OBJS}
					@echo "\n$(NAME): $(NAME) created"
					ar -rcs $(NAME) $(OBJS)

.c.o:
					@echo "\n$(NAME): object files created"
					${CC} ${FLAGS} -c $< -o ${<:.c=.o}

clean:
					@echo "\n$(NAME): object file deleted"
					${REMOVE} ${OBJS}

fclean:		clean
					@echo "\n${NAME}: ${NAME} deleted"
					${REMOVE} ${NAME}

re:			fclean all