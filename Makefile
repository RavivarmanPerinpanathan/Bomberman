CXX		=	g++

RM		=	rm -f

SRCS_DIR	=	srcs

NAME		=	bomberman

SRCS		=	$(SRCS_DIR)/AObject.cpp		\
			$(SRCS_DIR)/GameEngine.cpp	\
			$(SRCS_DIR)/BlockFactory.cpp	\
			$(SRCS_DIR)/Menu.cpp		\
			$(SRCS_DIR)/main.cpp		\
			$(SRCS_DIR)/Bomb.cpp		\
			$(SRCS_DIR)/Solid.cpp		\
			$(SRCS_DIR)/Bot.cpp		\
			$(SRCS_DIR)/Player.cpp		\
			$(SRCS_DIR)/Map.cpp

OBJS		=	$(SRCS:.cpp=.o)

CXXFLAGS	+=	-I include -ILibBomberman_linux_x64/includes/ -W -Wall -Wextra -Werror

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
