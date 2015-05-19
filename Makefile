##
## Makefile for make in /home/perinp_r/Bitbucket/bomb
## 
## Made by ravivarman perinpanathan
## Login   <perinp_r@epitech.net>
## 
## Started on  Tue May 19 12:24:58 2015 ravivarman perinpanathan
## Last update Tue May 19 12:25:00 2015 ravivarman perinpanathan
##


NAME		= bomberman 


SRC		= main.cpp 


OBJ		= $(SRC:.cpp=.o)

CXXFLAGS	= -ILibBomberman_linux_x64/includes/

LDFLAGS		+= -Wl,-rpath=LibBomberman_linux_x64/libs/

LDFLAGS		+= -LLibBomberman_linux_x64/libs

LDFLAGS		+= -lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -lGLU -lSDL -ldl

all:		$(NAME)

$(NAME):	$(OBJ)
		g++ -o $(NAME) $(OBJ) $(LDFLAGS) 

clean:
		rm -rf $(OBJ)

fclean:		clean
		rm -rf $(NAME)

re:		fclean all
