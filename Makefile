

SRCS		= main2.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= cc

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJ_BONUS}
		

fclean : 	clean
			${RM} ${NAME}
		

re:			fclean all

.PHONY:		re all clean fclean

