# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dlavaury <dlavaury@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/13 17:27:58 by dlavaury          #+#    #+#              #
#    Updated: 2018/04/12 11:18:15 by dlavaury         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB			= libft
LEM-IN		= lem-in

CC			= gcc
FLAGS		= -Weverything -Wall -Wextra -Werror
HEADER		= -I includes -I $(LIB)/includes/

SOURCES		= main.c \
			  parse_arg.c \
			  node_parser.c \
			  arg.c

OBJ			= $(addprefix sources/,$(SOURCES:.c=.o))

#Color
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m

all: $(LEM-IN)

$(LEM-IN): lib $(OBJ)
	@$(CC) $(FLAGS) $(HEADER) -o $(LEM-IN) $(OBJ) $(LIB)/$(LIB).a
	@echo "$(_CYAN)$(LEM-IN)$(_END)			: $(_GREEN)compiled$(_END)"

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@ $(HEADER)

clean:
	@make -C $(LIB) clean
	@rm -f $(OBJ)
	@echo "$(_RED)clean $(_END)			: $(_GREEN)done$(_END)"

fclean: clean
	@make -C $(LIB) fclean
	@rm -f $(LEM-IN)
	@echo "$(_RED)fclean$(_END)			: $(_GREEN)done$(_END)"

re: fclean
	@make all

lib:
	@make -j3 -C $(LIB)

li:
	@clear
	@make all
	@valgrind ./lem-in < test1.map
	@./lem-in < test1.map

.PHONY: all re fclean clean
