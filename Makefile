CC			= cc
CFLAGS		= -Werror -Wextra -Wall
MLX			= -Lminilibx-linux -lmlx_linux -lX11 -lXext
NAME		= so_long

SRC_PATH	= src/
OBJ_PATH	= obj/

CORE_PATH	= core/
ERROR_PATH	= error/
PARS_PATH	= parsing/
PLAYER_PATH	= player/

CORE		= free_memory.c init_map.c so_long.c
ERROR		= error.c
PARSING		= map_checker.c
PLAYER		= 

SRCS		= $(addprefix $(SRC_PATH), $(SRC))
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))
INCS		= -I ./includes/

all: $(OBJ_PATH) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	$(CC) $(CFLAGS) $(MLX) -c $< -o $@ $(INCS)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(MLX) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -r $(NAME)

re: fclean all

