SRC		= server.c
SRC2	= client.c aux.c
OBJS	= ${SRC:.c=.o}
OBJS2	= ${SRC2:.c=.o}
CC		= gcc
CFLAGS	= -Wall -Werror -Wextra #-g3 #-fsanitize=address
AR		= ar rc
NAME	= server
NAME2	= client
RM		= rm -f

FTPRINTF = ./printf/libftprintf.a

#.c.o:
#			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
%.o: %.c 
	${CC} ${CFLAGS} -c $< -o $@

all:  ${NAME} ${NAME2}

${FTPRINTF}: 
				${MAKE} -C ./printf

${NAME}: ${FTPRINTF} ${OBJS}
				${CC} ${CFLAGS} ${OBJS} ${FTPRINTF} -o ${NAME}

${NAME2}: ${FTPRINTF} ${OBJS2}
				${CC} ${CFLAGS} ${OBJS2} ${FTPRINTF} -o ${NAME2}

clean:
			${RM} ${OBJS} ${OBJS2}
			${MAKE} -C ./printf fclean

fclean: clean
			${RM} ${NAME} ${NAME2}

re:			fclean all

.PHONY:		all clean fclean re