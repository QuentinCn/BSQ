##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## root BSQ
##

SRC	=	$(shell find -name "*.c")

NAME	=	bsq

all:	$(NAME) clean

libmy:
	@make -sC lib/my/

$(NAME):	libmy
	@gcc -o $(NAME) $(SRC) -I./include -L./lib -lmy
	@echo -e "\033[05m\033[32mCompilation done => ${NAME}\033[00m"

test_run:
	make -sC tests/

clean:
	make -sC lib/my/ clean
	rm -f *~ include/*~ lib/my/*~ tests/*~

fclean:	clean
	make -sC lib/my/ fclean
	rm -f $(NAME)
	clear

re:	fclean all
