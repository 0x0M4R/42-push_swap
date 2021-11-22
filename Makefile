SRCS	= push_swap.c linked_lists.c operations.c misc_functions.c parse.c sort_bits.c sort_2bits.c sort_chunks.c

NAME = push_swap
OBJS = ${SRCS:.c=.o}

all:	${NAME}

${NAME}:
	gcc  -I. ${SRCS} -o ${NAME}
clean:
	rm -f ${OBJS} 
fclean:	clean
	rm -f ${NAME}
re:	fclean all