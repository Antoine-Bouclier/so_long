GREEN = \033[0;32m
RESET = \033[0m

CC		= cc
RM		= rm -rf
MKDIR	= mkdir -p

CFLAGS	= -Wall -Wextra -Werror -MMD -MP

NAME			= so_long
SRCS			= src/core/so_long.c src/core/player_movement.c src/core/movement_actions.c\
				src/error/error.c \
				src/initialization/ft_check_file.c src/initialization/ft_check_map.c\
				src/parsing/init_map.c src/parsing/set.c src/parsing/flood_fill.c

OBJ_DIR			= obj
DEP_DIR			= dep

OBJS 			= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
DEPS			= $(addprefix $(DEP_DIR)/, $(notdir $(SRCS:.c=.d)))

LIBFT			= libft
HEADER			= includes/so_long.h
LIBFLAGS		= $(LIBFT)/libft.a

MLX				= minilibx-linux
MLX_FLAGS		= -L$(MLX) -lmlx_Linux -lX11 -lXext

MAKEFILE		= Makefile

all: $(NAME)

$(NAME): $(OBJS) $(LIBFLAGS) $(MAKEFILE)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFLAGS) $(MLX_FLAGS)
	@printf "$(NAME)	$(GREEN)[OK]$(RESET)\n"

$(OBJ_DIR)/%.o: src/**/%.c $(MAKEFILE) $(HEADER)
	@$(MKDIR) $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(CFLAGS) -I./includes -c $< -o $@ -MF $(DEP_DIR)/$*.d
	@printf "Compiling $<\n"

$(LIBFLAGS):
	@$(MAKE) -C $(LIBFT)

$(MLX_FLAGS):
	@$(MAKE) -C $(MLX)

clean:
	@$(RM) $(OBJ_DIR) $(DEP_DIR)
	@$(MAKE) -C $(LIBFT) clean
	@$(MAKE) -C $(MLX) clean
	@printf "clean	$(GREEN)[OK]$(RESET)\n"

fclean: clean
	@$(RM) $(NAME)
	@$(MAKE) -C $(LIBFT) fclean
	@printf "fclean	$(GREEN)[OK]$(RESET)\n"

re:	fclean all

.PHONY: clean fclean all re

-include $(DEPS)
