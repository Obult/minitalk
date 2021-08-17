SERVER	= server
SRC_S	= ../extra/utils.c ./server.c
OBJ	= ${SRC_S:.c=.o}

CC		= gcc

RM		= rm -f

HEADER	= -I ../extra/

CFLAGS	= -Wall -Werror -Wextra

all:		${SERVER}

.c.o:
				${CC} -c ${CFLAGS} ${HEADER}  $< -o ${<:.c=.o}
clean:
				${RM} ${OBJ}

fclean:		clean
				${RM} ${SERVER}

re:			fclean all

${SERVER}:	${OBJ}
				${CC} -o $@ $^ 

.PHONY: all clean fclean re