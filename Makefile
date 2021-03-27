##
## EPITECH PROJECT, 2021
## G-JAM-001-NCE-0-2-jam-marton.szuts
## File description:
## Makefile
##

NAME	=	test

CXX	=	g++

DIR1         =     ./src/entity/
DIR2         =     ./src/game/
INC            =    $(DIR1) $(DIR2)
INC_PARAMS    =    $(foreach d, $(INC), -I$d)

CXXFLAGS	=	-Wall -Wextra $(INC_PARAMS)

LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

SRC	=	src/main.cpp \
		src/game/Game.cpp \
		src/entity/Entity.cpp \

OBJ	=	$(SRC:.cpp=.o)

RM	=	rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re