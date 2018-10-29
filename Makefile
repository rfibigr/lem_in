# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rfibigr <rfibigr@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/12/01 16:20:20 by rfibigr           #+#    #+#              #
#    Updated: 2018/10/29 14:42:02 by rfibigr          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
.PHONY: all, clean, fclean, re

#/******************* DEFINE COLOR *******************/
NC = \033[0m
RED = \033[1;31m
GREEN = \033[0;32m
LOW_GREEN = \033[1;32m
BLUE = \033[1;34m
PURPLE = \033[0;35m
WHITE = \033[1;37m
YELLOW = \033[1;33m
CYAN = \033[0;36m
BLACK = \033[0;30m
DARK_GRAY = \033[1;30m


#/******************* DIRECTORIES *******************/
SRC_PATH =	src
OBJ_PATH =	obj
INC_PATH =	include
LIB_PATH =	lib

#/******************* COMPILATION *******************/
CC =			gcc
CFLAGS =		-Wall -Werror -Wextra

#/********************** BINARY *********************/
NAME = 		lem-in

#/********************** SOURCE *********************/
SRC =		lem_in.c \
			create_list.c \
			create_list_tools.c \
			create_room.c \
			create_pipe.c \
			ft_exit.c \
			initialisation.c \
			test_valid_anthill.c \
			ft_path.c \
			tool.c \


UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
LIBNAME =	libft/libft.a \
			minilibx/libmlx.a
LIB_FOLDER = minilibx
FRAMEWORK = 	-lXext -lX11
# do something Linux-y
endif
ifeq ($(UNAME), Darwin)
LIBNAME =	libft/libft.a \
			minilibx_macos/libmlx.a
LIB_FOLDER = minilibx_macos
FRAMEWORK = 	-framework OpenGL -framework AppKit
# do something Solaris-y
endif

#/********************** PATH  *********************/
INCP =		$(foreach dir, $(INC_PATH), -I$(dir))
LIBP = 		$(addprefix $(LIB_PATH)/,$(LIBNAME))
OBJ	 =		$(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))


###################################################
#/********************** RULES *********************/

all : $(NAME)

$(NAME) : $(OBJ)
	@echo "$(LOW_GREEN) --Compiling lib--\tlibft"
	@make -C $(LIB_PATH)/libft
	@echo "$(LOW_GREEN) --Compiling lib--\tminilibix"
	@make -C $(LIB_PATH)/$(LIB_FOLDER)
	@echo "$(PURPLE) --Linking--\t\tlem_in"
	$(CC) -o $@ $^ $(LIBP) $(FRAMEWORK)

$(OBJ_PATH)/%.o : $(SRC_PATH)/%.c
	@echo "$(GREEN) --Compiling--\t\tlem_in"
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -o $@ -c $^ $(INCP)

clean :
	@echo "$(RED) --Cleaning--\t\tobject folder"
	@rm -rf $(OBJ_PATH) 2> /dev/null || true
	@echo "$(RED) --Cleaning--\t\tlibrary libft"
	@make clean -C $(LIB_PATH)/libft
	@make clean -C $(LIB_PATH)/$(LIB_FOLDER)

fclean : clean
	@echo "$(RED) --Cleaning--\t\texecutable"
	@rm -rf $(NAME)
	@make fclean -C $(LIB_PATH)/libft

re: fclean all

debug : $(OBJ)
	@echo "$(LOW_GREEN) --Compiling lib--\tlibft"
	@make -C $(LIB_PATH)/libft
	@echo "$(PURPLE) --Linking--\t\tlem_in"
	$(CC) -o lem_in_debug $^ $(LIBP) -fsanitize=address -O1 -fno-omit-frame-pointer
