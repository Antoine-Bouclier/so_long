GREEN = \033[0;32m
RESET = \033[0m

CC		= cc
RM		= rm -rf
MKDIR	= mkdir -p

CFLAGS	= -Wall -Wextra -Werror -MMD -MP

NAME			= so_long
SRCS			= src/core/so_long.c\
				src/graphics/render_map.c src/graphics/set_images.c src/graphics/render_map_bonus.c src/graphics/set_image_bonus.c\
				src/map_loader/init_map.c\
				src/map_validation/add_collectible.c src/map_validation/check_map.c src/map_validation/is_valid_line.c src/map_validation/check_file.c src/map_validation/flood_fill.c\
				src/player_movement/movement_actions.c src/player_movement/player_movement.c src/player_movement/utils.c\
				src/utils/close_game.c src/utils/error.c src/utils/free_memory.c src/utils/mlx_destroy_img.c\
				src/monster/projectile.c src/monster/monster.c src/monster/update_projectile.c

OBJ_DIR			= obj
DEP_DIR			= dep

OBJS 			= $(addprefix $(OBJ_DIR)/, $(notdir $(SRCS:.c=.o)))
DEPS			= $(addprefix $(DEP_DIR)/, $(notdir $(SRCS:.c=.d)))

LIBFT			= libft
HEADER			= includes/so_long.h
LIBFLAGS		= $(LIBFT)/libft.a

MLX				= minilibx-linux
MLX_LIB			= $(MLX)/libmlx_Linux.a
MLX_FLAGS		= -L$(MLX) -lmlx_Linux -lX11 -lXext

MAKEFILE		= Makefile

all: $(NAME)

$(NAME): $(OBJS) $(LIBFLAGS) $(MLX_LIB) $(MAKEFILE)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFLAGS) $(MLX_FLAGS)
	@printf "$(NAME)	$(GREEN)[OK]$(RESET)\n"

$(OBJ_DIR)/%.o: src/**/%.c $(MAKEFILE) $(HEADER)
	@$(MKDIR) $(OBJ_DIR) $(DEP_DIR)
	@$(CC) $(CFLAGS) -I./includes -I$(LIBFT) -I$(MLX) -c $< -o $@ -MF $(DEP_DIR)/$*.d
	@printf "Compiling $<\n"

$(LIBFLAGS): force
	@$(MAKE) -C $(LIBFT)

$(MLX_LIB):
	@$(MAKE) -C $(MLX)

force:

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

.PHONY: clean fclean all re force

-include $(DEPS)
