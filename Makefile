SRC		=	main.cpp \
			Coord.cpp \
			Field.cpp \
			Graphic.cpp \
			Menu.cpp \
			Object.cpp \
			Player.cpp \
			Setting.cpp \
			AObject.cpp \
			Background.cpp \
			Button.cpp \
			GameEngine.cpp \
			Exception.cpp

OBJS		=	$(SRC:.cpp=.o)

NAME		=	bomberman

CPP		=	g++

CPPFLAGS	+=	-ILibBomberman_linux_x64/includes/
#CPPFLAGS	+=	-Wall -Werror -Wextra

LDFLAGS		+=	-Wl,-rpath=LibBomberman_linux_x64/libs
LDFLAGS		+=	-LLibBomberman_linux_x64/libs
LDFLAGS		+=	-lgdl_gl -lGL -lGLEW -ldl -lrt -lfbxsdk -lSDL2 -lpthread -lGLU -lSDL


all	:		$(NAME)

$(NAME)	:		$(OBJS)
			$(CPP) -o $(NAME) $(OBJS) $(CPPFLAGS) $(LDFLAGS)

clean	:
			rm -f $(OBJS)

fclean :		clean
			rm -f $(NAME)

re	:			fclean all

.PHONY	:		all clean fclean re
