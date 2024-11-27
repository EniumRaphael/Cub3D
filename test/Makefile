# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rparodi <rparodi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 11:05:05 by rparodi           #+#    #+#              #
#    Updated: 2024/11/26 14:41:12 by rparodi          ###   ########.fr        #
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

# INCLUDES += -I /opt/X11/include
INCLUDES = -I /usr/include -I ./includes -I ./includes/include -I ./minilibx-linux
 
# Paths
MLX_DIR = ./minilibx-linux

# Library flags
LDFLAGS = -L./build -lm

# MiniLibX flags for macOS with XQuartz
MLXFLAGS = -L$(MLX_DIR) -lmlx -lX11 -lXext
#MLXFLAGS += -L/opt/X11/lib

# Add MLXFLAGS to the linker flags
LDFLAGS += $(MLXFLAGS)

SRC = test2.c

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
build/libmlx.a:
	@make --no-print-directory -C $(MLX_DIR)

# Dependences for all
$(NAME): $(OBJ) build/libmlx.a
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
