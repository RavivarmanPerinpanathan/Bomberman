SRC		=	main.cpp \
			GameEngine.cpp \
			Cube.cpp \
			AObject.cpp \
			Model.cpp \
			Pos3f.cpp


OBJS		=	$(SRC:.cpp=.o)

NAME		=	bomberman

CXX		=	g++

CXXFLAGS	+=	-ILibBomberman_linux_x64/includes/ -W -Wall -Wextra -Werror
#CPPFLAGS	+=	-Wall -Werror -Wextra

LDFLAGS		+=	-Wl,-rpath=LibBomberman_linux_x64/libs
LDFLAGS		+=	-LLibBomberman_linux_x64/libs
LDFLAGS		+=	-lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -lGLU -lSDL -ldl

all	:		$(NAME)

$(NAME)	:		$(OBJS)
			$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)

clean	:
			rm -f $(OBJS)

fclean :		clean
			rm -f $(NAME)

re	:			fclean all

.PHONY	:		all clean fclean re
