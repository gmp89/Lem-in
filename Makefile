#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gpetrov <gpetrov@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/11 12:40:38 by gpetrov           #+#    #+#              #
#    Updated: 2014/02/23 22:13:24 by gpetrov          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME	= lem-in
FILES	= main.c ft_get_data.c ft_get_data2.c tools.c ft_play.c \
		ft_get_data_help.c ft_play2.c ft_path.c
SRCS	= $(addprefix src/, $(FILES))
OBJS	= $(SRCS:src/%.c=.obj/%.o)
INC		= -I includes -I libft/includes
FLAGS	= -Wall -Wextra -Werror -O3
LIB		= -L libft -lft

all: $(NAME)
$(NAME): $(OBJS)
	@make -C libft
	@cc $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
	@echo "\n > \033[36m$(NAME)\033[m project compilation [\033[32mDONE\033[m]\n"
	@echo "\t\033[32m     ___       ___           ___                       ___      "
	@echo "\t    /\__\     /\  \         /\__\          ___        /\__\     "
	@echo "\t   /:/  /    /::\  \       /::|  |        /\  \      /::|  |    "
	@echo "\t  /:/  /    /:/\:\  \     /:|:|  |        \:\  \    /:|:|  |    "
	@echo "\t /:/  /    /::\~\:\  \   /:/|:|__|__      /::\__\  /:/|:|  |__  "
	@echo "\t/:/__/    /:/\:\ \:\__\ /:/ |::::\__\  __/:/\/__/ /:/ |:| /\__\ "
	@echo "\t\:\  \    \:\~\:\ \/__/ \/__/~~/:/  / /\/:/  /    \/__|:|/:/  / "
	@echo "\t \:\  \    \:\ \:\__\         /:/  /  \::/__/         |:/:/  /  "
	@echo "\t  \:\  \    \:\ \/__/        /:/  /    \:\__\         |::/  /   "
	@echo "\t   \:\__\    \:\__\         /:/  /      \/__/         /:/  /    "
	@echo "\t    \/__/     \/__/         \/__/                     \/__/     \n"

.obj/%.o: src/%.c
	@mkdir -p .obj
	@cc -c $< -o $@ $(FLAGS) $(INC)
	@echo -n .
gdb:
	make -C libft
	cc -g $(FLAGS) $(SRCS) -o $(NAME) $(INC) $(LIB)
	gdb $(NAME)
clean:
	@rm -rf .obj
fclean: clean
	@make fclean -C libft
	@rm -f $(NAME)
	@echo "fclean : [\033[32mDONE\033[m]"
re: fclean all
.PHONY: all gdb clean fclean re
