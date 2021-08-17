CLIENT	= client
SRC	= ../extra/utils.c ./client.c
OBJ	= ${SRC:.c=.o}

CC		= gcc

RM		= rm -f

HEADER	= -I ../extra/

CFLAGS	= -Wall -Werror -Wextra

all:		${CLIENT}

.c.o:
				${CC} -c ${CFLAGS} ${HEADER}  $< -o ${<:.c=.o}
clean:
				${RM} ${OBJ}

fclean:		clean
				${RM} ${CLIENT}

re:			fclean all

${CLIENT}:	${OBJ}
				${CC} -o $@ $^ 

.PHONY: all clean fclean re