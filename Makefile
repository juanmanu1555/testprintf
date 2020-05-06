

SRCS		= main2.c

OBJS		= ${SRCS:.c=.o}

NAME		= libftprintf.a

CC			= cc

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

.c.o:
			${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			cd libft && ${MAKE}
			cp libft/libft.a ${NAME}
			ar rc ${NAME} ${OBJS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJ_BONUS}
			${MAKE} clean -C ./libft

fclean : 	clean
			${RM} ${NAME}
			${RM} libft.a
			${MAKE} fclean -C ./libft

re:			fclean all

.PHONY:		re all clean fclean

