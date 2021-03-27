##
## EPITECH PROJECT, 2021
## G-JAM-001-NCE-0-2-jam-marton.szuts
## File description:
## Makefile
##

NAME	=	test

CXX	=	g++

CXXFLAGS	=	-Wall -Wextra -I./

LDFLAGS	=	-lsfml-graphics -lsfml-window -lsfml-system

SRC	=	main.cpp \
		Game.cpp \

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