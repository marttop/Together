##
## EPITECH PROJECT, 2021
## G-JAM-001-NCE-0-2-jam-marton.szuts
## File description:
## Makefile
##

NAME			=	Together

CXX				=	g++

DIR1			=     ./src/entity/
DIR2			=     ./src/game/
INC				=    $(DIR1) $(DIR2)
INC_PARAMS		=    $(foreach d, $(INC), -I$d)

CXXFLAGS		=	-Wall -Wextra $(INC_PARAMS)

LDFLAGS			=	-lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio -lGL

SRC				=	src/main.cpp \
					src/game/Game.cpp \
					src/game/Utils.cpp \
					src/game/Menu.cpp \
					src/game/Button.cpp \
					src/game/ChatBox.cpp \
					src/entity/Entity.cpp \
					src/entity/EntityController.cpp \
					src/entity/Enemy.cpp \
					src/entity/Asteroid.cpp \
					src/entity/Ship.cpp \
					src/entity/Player.cpp \
					src/entity/Parallax.cpp \
					src/entity/Layer.cpp \
					src/entity/Particles.cpp \

OBJ				=	$(SRC:.cpp=.o)

RM				=	rm -rf

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) -o $(NAME) $(OBJ) $(LDFLAGS)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re