NAME = push_swap
CC = gcc
RM = rm -f
FLAGS = -Wall -Wextra -Werror
LIBFTDIR = includes/libft/
GET_NEXT_LINE = includes/printf/
OBJ_DIR = obj/
BONUS = checker
SRC_DIR = srcs/

SRC_1 = srcs/push_swap.c \

SRC_2 =	srcs/algo_sorting_extract.c \
		srcs/algo_sorting_iteration.c \
		srcs/algo_sorting_pre.c \
		srcs/algo_sorting_three.c \
		srcs/algo_sorting.c \
		srcs/algo_sortingmore.c \
		srcs/algo_utils.c \
		srcs/case_errors.c \
		srcs/parsing.c \
		srcs/ranking.c \
		srcs/split.c \

SRC_3 = srcs/commands/commands.c \
		srcs/commands/commands2.c \
		
BONUS_SRC = srcs/bonus/checker.c \
			

OBJ_1 = ${SRC_1:.c=.o}
OBJ_2 = ${SRC_2:.c=.o}
OBJ_3 = ${SRC_3:.c=.o}

BONUS_OBJ =${BONUS_SRC:.c=.o}

INCLUDE = -L $(LIBFTDIR) -lft -L $(GET_NEXT_LINE) -lftprintf

.c.o:
	${CC} -c $< -o ${<:.c=.o}

${NAME}: ${OBJ_1} ${OBJ_2} ${OBJ_3}
	make -C $(LIBFTDIR)
	make -C $(GET_NEXT_LINE)
	${CC} ${FLAGS} ${OBJ_1} ${OBJ_2} ${OBJ_3} -o ${NAME} ${INCLUDE}

${BONUS}: ${OBJ_2} ${OBJ_3} ${BONUS_OBJ} 
	make -C $(LIBFTDIR)
	make -C $(GET_NEXT_LINE)
	${CC} ${FLAGS} ${BONUS_OBJ} ${OBJ_2} ${OBJ_3} -o ${BONUS} ${INCLUDE}

all: ${NAME} ${BONUS}

bonus: ${BONUS} 

clean:
	${RM} ${OBJ_1} ${OBJ_2} ${OBJ_3} ${BONUS_OBJ} ${NAME} ${BONUS}
	@cd $(LIBFTDIR) && $(MAKE) clean

fclean: clean
	${RM} ${NAME}
	@cd $(LIBFTDIR) && $(MAKE) fclean

re: clean all

.PHONY: all clean fclean re bonus