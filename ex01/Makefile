NAME =			phonebook

SRCS =			Contact.cpp \
				PhoneBook.cpp \
				main.cpp

OBJS =			${SRCS:.cpp=.o}

C++ =			c++

CFLAGS =		-Wall -Wextra -Werror -std=c++98

RM =			rm -rf

all:			${NAME}

.c.o:
	@${C++} ${CFLAGS} -c $< -o

${NAME}:	${OBJS}
	@${C++} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	@${RM} ${OBJS}

fclean:			clean
	@${RM} ${NAME}

re:				fclean all

.PHONY:			all clean fclean re
