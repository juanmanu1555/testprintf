# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jcorral- <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/08 12:06:12 by jcorral-          #+#    #+#              #
#    Updated: 2020/01/20 09:39:12 by jcorral-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= ft_memchr.c ft_memset.c ft_strncmp.c ft_memcmp.c ft_bzero.c ft_memcpy.c ft_strlcpy.c ft_memccpy.c ft_memmove.c ft_strlen.c ft_strlcat.c ft_strlcpy.c ft_strchr.c ft_strrchr.c ft_strnstr.c ft_strncmp.c ft_atoi.c ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c ft_tolower.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRC_BONUS	= ft_lstnew_bonus.c ft_lstadd_front_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

OBJS		= ${SRCS:.c=.o}

OBJ_BONUS	= ${SRC_BONUS:.c=.o}

NAME		= libft.a

CC			= cc

RM			= rm -f

CFLAGS		= -Wall -Werror -Wextra

.c.o:
			@${CC} ${FLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
			ar rc  ${NAME} ${OBJS}
			ranlib ${NAME}

bonus:		${OBJS} ${OBJ_BONUS}
			ar rc ${NAME} ${OBJS} ${OBJ_BONUS}
			ranlib ${NAME}

all:		${NAME}

clean:
			${RM} ${OBJS} ${OBJ_BONUS}

fclean:		clean
			${RM} ${NAME}

re:			fclean bonus

.PHONY:		clean fclean all re bonus
