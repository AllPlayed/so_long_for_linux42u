# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/25 13:36:53 by ullorent          #+#    #+#              #
#    Updated: 2022/02/01 19:17:40 by ullorent         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Main Makefile flags and names
NAME = so_long
CSRC =	sl_main.c \
sl_window.c \
sl_readmap.c \
sl_otherfunctions.c \
sl_keyboard.c \
sl_keyboard_fct.c \
sl_error_mng.c

OSRC = $(CSRC:.c=.o)
INC = /usr/include
INCLIB = $(INC)/../lib

LFLAGS = -Lmlx_linux -lmlx -L$(INCLIB) -Imlx_linux -lXext -lX11 -lm -lz
SANITFLAG = -g3 -fsanitize=address
GCCCMD = gcc

all: $(NAME)

$.o: %.c
	make -C libft
	make -C mlx_linux
	cp libft/libft.a .
	@$(GCCCMD) -I/usr/include/ -Imlx_linux -O3 -c $< -o $@

#$(NAME): $(OSRC)
#	$(GCCCMD) libft.a -Imlx -Iso_long.h -Lmlx -lmlx -framework OpenGL -framework AppKit $^ -o $@
$(NAME): $(OSRC)
	@echo "\033[33mCompiling libft and minilibx libraries...\033[0m"
	@make -C libft
	@make -C mlx_linux
	@echo "\033[92mLibft and minilibx libraries have been successfully compiled!\033[0m"
	@echo ""
	@echo "\033[33mCompiling so_long for Ubuntu/Linux...\033[0m"
	@$(GCCCMD) $(OSRC) ./libft/libft.a -Iso_long.h $(LFLAGS) -o $(NAME)
	@echo "\033[92mso_long has been successfully compiled!\033[0m"
	@echo ""

clean:
	@echo "\033[33mThe project is being cleaned...\033[0m"
	@make -C libft/ clean
	@make -C mlx_linux/ clean
	@rm -f $(OSRC)

fclean: clean
	@make -C libft/ fclean
	@rm -f $(NAME)
	@echo "\033[92mAll has been cleaned!\033[0m"
	@echo ""

re:
	@echo "\033[33mRecompiling so_long project...\033[0m"
	@make fclean all

.PHONY: all clean fclean re
