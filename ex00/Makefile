NAME =		megaphone

SRCS =		megaphone.cpp

C++ =		c++

CFLAGS =	-Wall -Wextra -Werror -std=c++98

RM =		rm -rf

all:		${NAME}

${NAME}:	
	@${C++} ${CFLAGS} ${SRCS} -o ${NAME}

clean:		
	@${RM}

fclean:		clean
	@${RM} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
