NAME	=	libftprintf.a

CFLAGS	=	-Wall -Wextra -Werror

FILES	=	ft_printf.c ft_putstr.c ft_putnbr.c ft_putchar.c \
			ft_conv_primary.c ft_conv_suit.c ../libft/ft_strlen.c\

OBJ			=	$(FILES:.c=.o)
RM			=	rm -f

all:		$(NAME)

$(NAME):	$(OBJ)
	@ar rcs $@ $(OBJ)
	@echo "$(NAME) created"
	@ranlib $@
	@echo "$(NAME) indexed"

$(OBJ):		$(FILES)
	@gcc -c $(FLAG) $(FILES)

clean:
	@$(RM) $(OBJ)
	@echo "OBJ deleted"

fclean:		clean
	@$(RM) $(NAME)
	@echo "$(NAME) deleted"

re:			fclean all

normi:		$(FILES)
	norminette $(FILES)

.PHONY: all, clean, fclean, re