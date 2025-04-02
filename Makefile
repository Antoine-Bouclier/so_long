NAME            = so_long
NAME_BONUS      = so_long_bonus

GREEN           = \033[0;32m
RED             = \033[0;31m
RESET           = \033[0m

LIBFT           = ./libft/libft.a

CC              = cc

STANDARD_FLAGS  = -Wall -Werror -Wextra -MMD -MP
MINILIBX_FLAGS  = -lmlx -lXext -lX11 -Lminilibx-linux

REMOVE          = rm -f

SRCS_DIR        = ./src/
BONUS_SRCS_DIR  = ./src_bonus/

OBJ_DIR         = obj
OBJ_DIR_BONUS	= obj_bonus

SRCS            = $(addprefix $(SRCS_DIR),\
                core/so_long.c\
                graphics/render_map.c graphics/set_images.c\
                map_loader/init_map.c\
                map_validation/check_map.c map_validation/is_valid_line.c map_validation/check_file.c map_validation/flood_fill.c\
                player_movement/movement_actions.c player_movement/player_movement.c\
                utils/close_game.c utils/error.c utils/free_memory.c)

SRCS_BONUS      = $(addprefix $(BONUS_SRCS_DIR),\
                core/so_long.c\
                graphics/render_map.c graphics/set_images.c graphics/render_map_bonus.c graphics/set_image_bonus.c\
                map_loader/init_map.c\
                map_validation/add_collectible.c map_validation/check_map.c map_validation/is_valid_line.c map_validation/check_file.c map_validation/flood_fill.c\
                player_movement/movement_actions.c player_movement/player_movement.c player_movement/utils.c\
                utils/close_game.c utils/error.c utils/free_memory.c utils/mlx_destroy_img.c\
                monster/projectile.c monster/monster.c monster/update_projectile.c)

OBJS            = $(patsubst $(SRCS_DIR)%.c, $(OBJ_DIR)/%.o, $(SRCS))
OBJS_BONUS      = $(patsubst $(BONUS_SRCS_DIR)%.c, $(OBJ_DIR_BONUS)/%.o, $(SRCS_BONUS))

INCLUDES        = -Iincludes -Iminilibx-linux -Ilibft

VPATH           = $(SRCS_DIR):$(BONUS_SRCS_DIR)

.PHONY: all clean fclean re bonus run run_bonus

# Règle principale
all: $(LIBFT) $(NAME)

bonus: $(LIBFT) $(NAME_BONUS)

# Compilation du programme principal
$(NAME): $(OBJS) $(LIBFT) Makefile $(wildcard includes/*.h)
	@$(CC) $(OBJS) $(LIBFT) $(STANDARD_FLAGS) $(MINILIBX_FLAGS) $(INCLUDES) -o $@
	@echo "$(NAME): $(GREEN)$(NAME) was compiled.$(RESET)"

# Compilation du programme bonus
$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) Makefile $(wildcard includes/*.h)
	@$(CC) $(OBJS_BONUS) $(LIBFT) $(STANDARD_FLAGS) $(MINILIBX_FLAGS) $(INCLUDES) -o $@
	@echo "$(NAME): $(GREEN)$(NAME_BONUS) was compiled with Bonus.$(RESET)"

# Compilation des fichiers objets principaux
$(OBJ_DIR)/%.o: $(SRCS_DIR)%.c
	@mkdir -p $(@D)
	@echo "Compiling $<..."
	@$(CC) -c $< -o $@ $(STANDARD_FLAGS) $(INCLUDES)

$(OBJ_DIR_BONUS)/%.o: $(BONUS_SRCS_DIR)%.c
	@mkdir -p $(@D)
	@echo "Compiling $< for bonus..."
	@$(CC) -c $< -o $@ $(STANDARD_FLAGS) $(INCLUDES)

# Inclusion des dépendances générées
$(NAME): $(OBJS) $(LIBFT) Makefile $(wildcard includes/*.h)
$(NAME_BONUS): $(OBJS_BONUS) $(LIBFT) Makefile $(wildcard includes/*.h)


# Compilation de la libft
$(LIBFT): force
	@make -s -C libft/

force:

# Nettoyage des fichiers objets et dépendances
clean:
	make clean -C libft
	@rm -rf $(OBJ_DIR)
	@rm -rf $(OBJ_DIR_BONUS)
	@echo "Cleaned object files and dependencies."

# Nettoyage complet (exécutables + objets + dépendances)
fclean: clean
	@$(REMOVE) $(NAME) $(NAME_BONUS)
	@echo "$(NAME): ${RED}${NAME} and ${NAME_BONUS} were deleted${RESET}"

# Rebuild complet
re: fclean all

rebonus: fclean bonus

# Exécution sans Valgrind (modifiez selon vos besoins)
run: all
	./$(NAME) assets/maps/valid/map5.ber

run_bonus: bonus
	./$(NAME_BONUS) assets/maps/bonus/map5.ber
