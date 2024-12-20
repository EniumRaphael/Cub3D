
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 11:05:05 by rparodi           #+#    #+#              #
#    Updated: 2024/12/20 15:06:28 by rparodi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

# Name
NAME = Cub3D
NAME_BONUS = Cub3D_bonus

# Commands
CC ?= cc
RM = rm -rf

# Flags
CFLAGS = -Werror -Wextra -Wall
# CFLAGS += -g3 -MMD 

INCLUDES += -I /opt/X11/include
INCLUDES = -I ./includes -I ./includes/include -I ./minilibx-linux
 
# Paths
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux

# Library flags
LDFLAGS = -L./build -lft -lm

# MiniLibX flags for macOS with XQuartz
MLXFLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext
MLXFLAGS += -L/opt/X11/lib

# Add MLXFLAGS to the linker flags
LDFLAGS += $(MLXFLAGS)

SRC =\
	ft_addons/ft_inrange.c \
	ft_addons/ft_strchrs.c \
	mlx_layer/mlx_init.c \
	mlx_layer/looks.c \
	mlx_layer/mooves.c \
	mlx_layer/hooks.c \
	mlx_layer/keys_event.c \
	raycast/frame_update.c \
	raycast/frame_update2.c \
	raycast/rc_utils.c \
	raycast/utils_math.c \
	raycast/get_cl.c \
	raycast/draw_call.c \
	raycast/get_texture.c \
	sources/options_impl.c \
	sources/main.c \
	sources/error.c \
	sources/cleanups.c \
	sources/options.c \
	sources/rgb_to_color.c \
	parsing/load_textures.c \
	parsing/load_bgs.c \
	parsing/traverse_map.c \
	parsing/load_file.c \
	parsing/utils.c \
	parsing/map.c \
	parsing/arguments.c \
	parsing/load_tiles.c

# Objects
OBJDIRNAME = ./build
OBJ = $(addprefix $(OBJDIRNAME)/,$(SRC:.c=.o))

# Colors
GREEN = \033[32m
GREY = \033[0;90m
RED = \033[0;31m
GOLD = \033[38;5;220m
END = \033[0m

# Rules
#
# All (make all)
all: header $(NAME) footer

# Bonus (make bonus)
bonus: header $(OBJ) footer
	@mkdir -p $(OBJDIRNAME)
	@printf '$(GREY) Creating $(END)$(GREEN)$(OBJDIRNAME)$(END)\n'
	@$(CC) $(CFLAGS) -D BONUS=1 -o $(NAME_BONUS) $(OBJ) $(LDFLAGS)

# Clean (make clean)
clean:
	@printf '$(GREY) Removing $(END)$(RED)Objects$(END)\n'
	@printf '$(GREY) Removing $(END)$(RED)Objects Folder$(END)\n'
	@$(RM) $(OBJDIRNAME)

# Clean (make fclean)
fclean: clean
	@printf '$(GREY) Removing $(END)$(RED)Program$(END)\n'
	@$(RM) $(NAME)
	@$(RM) $(NAME_BONUS)
	@echo ""

# Restart (make re)
re: header fclean all

# Compile external libraries
build/libft.a:
	@make --no-print-directory -C $(LIBFT_DIR)
build/libmlx.a:
	@make --no-print-directory -C $(MLX_DIR)

get_mlx:
	@git clone https://github.com/42Paris/minilibx-linux

get_mlx-intra:
	@wget https://cdn.intra.42.fr/document/document/26097/minilibx-linux.tgz --no-check-certificate
	@tar -xvpf ./minilibx-linux.tgz
	@rm -rf ./minilibx-linux.tgz

# Dependences for all
$(NAME): $(OBJ) build/libft.a build/libmlx.a
	@mkdir -p $(OBJDIRNAME)
	@printf '$(GREY) Creating $(END)$(GREEN)$(OBJDIRNAME)$(END)\n'
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

# Creating the objects
$(OBJDIRNAME)/%.o: %.c
	@mkdir -p $(dir $@)
	@printf '$(GREY) Compiling $(END)$(GREEN)$<$(END)\n'
	@$(CC) $(CFLAGS) $(INCLUDES) -o $@ -c $<

# Header
header:
		@printf '\n\n'
		@printf '$(GOLD)            *******     ****** ******* $(END)\n'
		@printf '$(GOLD)          ******        ***    ******* $(END)\n'
		@printf '$(GOLD)      *******           *      ******* $(END)\n'
		@printf '$(GOLD)     ******                  ******* $(END)\n'
		@printf '$(GOLD)  *******                  ******* $(END)\n'
		@printf '$(GOLD) *******************    *******      * $(END)\n'
		@printf '$(GOLD) *******************    *******    *** $(END)\n'
		@printf '$(GOLD)              ******    ******* ****** $(END)\n'
		@printf '$(GOLD)              ******  $(END)\n'
		@printf '$(GOLD)              ******  $(END)\n'
		@printf '$(GREY)                                      Made by rparodi$(END)\n\n'

# Footer
footer:
		@printf "\n"
		@printf "$(GOLD)                   ,_     _,$(END)\n"
		@printf "$(GOLD)                   | \\___//|$(END)\n"
		@printf "$(GOLD)                   |=6   6=|$(END)\n"
		@printf "$(GOLD)                   \\=._Y_.=/$(END)\n"
		@printf "$(GOLD)                    )  \`  (    ,$(END)\n"
		@printf "$(GOLD)                   /       \\  (('$(END)\n"
		@printf "$(GOLD)                   |       |   ))$(END)\n"
		@printf "$(GOLD)                  /| |   | |\\_//$(END)\n"
		@printf "$(GOLD)                  \\| |._.| |/-\`$(END)\n"
		@printf "$(GOLD)                   '\"'   '\"'$(END)\n"
		@printf '              $(GREY)The compilation is$(END) $(GOLD)finish$(END)\n               $(GREY)Have a good $(END)$(GOLD)correction !$(END)\n'

clangd:
	@echo -en			\
	"CompileFlags:\n"	\
	"  Add:\n"			\
	"    - \"-Wall -Wextra -Werror\"\n"	\
	"    - \"-I/opt/X11/include\"\n"	\
	"    - \"-I"$(shell pwd)"/includes\"\n"	\
	"    - \"-I"$(shell pwd)"/includes/include\"\n"	\
	"    - \"-xc\"\n"	\
	> .clangd

# Phony targets
.PHONY: all bonus clean fclean re

-include ${OBJ:.o=.d}
