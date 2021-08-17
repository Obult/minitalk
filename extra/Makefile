SERVER	= server
SRC_S	= ./utils.c ./server.c
OBJ_S	= ${SRC_S:.c=.o}

CLIENT	= client
SRC_C	= ./client.c
OBJ_C	= ${SRC_C:.c=.o}

CC		= gcc

RM		= rm -f

HEADER	= -I

CFLAGS	= -Wall -Werror -Wextra

LIB		= ar -rsc

all:		${SERVER} ${CLIENT}

.c.o:
				${CC} -c ${CFLAGS}  $< -o ${<:.c=.o}
clean:
				${RM} ${OBJ_S} ${OBJ_C}

fclean:		clean
				${RM} ${SERVER} ${CLIENT}

re:			fclean all

${SERVER}:	${OBJ_S}
				${CC} -o $@ $^ 

${CLIENT}:	${OBJ_C}
				${CC} -o $@ $^

.PHONY: all clean fclean re