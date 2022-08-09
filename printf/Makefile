SRC		= writefunc.c ft_printf.c
OBJS	= ${SRC:.c=.o}
GCC		= gcc
FLAGS	= -Wall -Werror -Wextra
AR		= ar rc
NAME	= libftprintf.a
RM		= rm -f

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			${AR} ${NAME} ${OBJS}

clean:
			${RM} ${OBJS}

fclean:		clean
			${RM} ${NAME}

all:		${NAME}

re:			fclean all

.PHONY:		all clean fclean re