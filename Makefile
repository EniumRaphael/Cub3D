# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 11:05:05 by rparodi           #+#    #+#              #
#    Updated: 2024/11/12 06:12:02 by bgoulard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

# Name
NAME = Cub3D
NAME_BONUS = Cub3D_bonus

# Commands
CC = cc
RM = rm -rf

# Flags
CFLAGS = -Werror -Wextra -Wall
CFLAGS += -g3 -MMD 
# CFLAGS += -fsanitize=address
# CFLAGS += -fsanitize=thread

INCLUDES = -I /opt/X11/include -I ./includes -I ./includes/include -I ./minilibx-linux

# Paths
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx-linux

# Library flags
LDFLAGS = -L./build -lft -lm

# MiniLibX flags for macOS with XQuartz
MLXFLAGS = -L$(MLX_DIR) -lmlx -L/opt/X11/lib -lX11 -lXext -lXrender -lXrandr -lXi

# Add MLXFLAGS to the linker flags
LDFLAGS += $(MLXFLAGS)

SRC =\
	raycast/frame_update.c	\
	mlx_layer/mlx_init.c	\
	parsing/arguments.c		\
	sources/main.c			\
	sources/cleanups.c		\
	sources/options.c		\
	sources/rgb_to_color.c	\
	sources/error.c			\
	sources/options_impl.c
	 

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
		@clear
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

# Phony targets
.PHONY: all bonus clean fclean re

-include ${OBJ:.o=.d}
