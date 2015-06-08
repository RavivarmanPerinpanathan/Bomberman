SRCS_DIR	=	srcs

SRCS		=	main.cpp			\
			GameEngine.cpp			\
			Cube.cpp			\
			AObject.cpp			\
			Marvin.cpp			\
			$(SRCS_DIR)/Bomb.cpp		\
			$(SRCS_DIR)/Map.cpp		\
			$(SRCS_DIR)/Play.cpp		\
			$(SRCS_DIR)/Player.cpp		\
			$(SRCS_DIR)/Bot.cpp		\
			$(SRCS_DIR)/Game.cpp


OBJS		=	$(SRCS:.cpp=.o)

NAME		=	bomberman

CXX		=	g++

RM		=	rm -f

CXXFLAGS	+=	-ILibBomberman_linux_x64/includes/ -W -Wall -Wextra -Werror

LDFLAGS		+=	-Wl,-rpath=LibBomberman_linux_x64/libs
LDFLAGS		+=	-LLibBomberman_linux_x64/libs
LDFLAGS		+=	-lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -lGLU -lSDL -ldl

all	:		$(NAME)

$(NAME)	:		$(OBJS)
			$(CXX) -o $(NAME) $(OBJS) $(LDFLAGS)

clean	:
			$(RM) $(OBJS)

fclean :		clean
			$(RM) $(NAME)

re	:		fclean all

.PHONY	:		all clean fclean re
