##
## EPITECH PROJECT, 2021
## Spaceinv
## File description:
## Makefile
##

CC 	       	 			=		gcc

RESOURCE 				= 		assets

SOURCE	=	src/

GAME	=	$(SOURCE)game/

LEVEL	=	$(SOURCE)level/

PLAYER	=	$(SOURCE)player/

MENU	=	$(SOURCE)menu/

EVENT	=	$(SOURCE)event/

HUD	=	$(SOURCE)hud/

NAME       				 =   	spaceinv

##					source_files				##

SRC	=   $(SOURCE)main.c
SRC	+=	$(SOURCE)sprite.c
SRC	+=	$(SOURCE)text.c
SRC	+=	$(SOURCE)collision.c
SRC	+=	$(GAME)spaceinv.c
SRC	+=	$(GAME)free_all.c
SRC	+=	$(GAME)window.c
SRC	+=	$(GAME)game.c
SRC	+=	$(LEVEL)level.c
SRC	+=	$(PLAYER)player.c
SRC	+=	$(MENU)menu.c
SRC	+=	$(MENU)button.c
SRC	+=	$(EVENT)event.c
SRC	+=	$(HUD)bar.c
SRC	+=	$(HUD)hud.c

OBJ         =   $(SRC:.c=.o)

CFLAGS      +=  -Wall -Wextra

CPPFLAGS    +=  -I ./includes/

CSFML_FLAGS = -lcsfml-graphics -lcsfml-system -lcsfml-audio -lcsfml-window -g3

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS) $(CSFML_FLAGS) $(CFLAGS)

clean:
	(cd $(SOURCE) && rm -f *.o)
	(cd $(GAME) && rm -f *.o)
	(cd $(PLAYER) && rm -rf *.o)
	(cd $(LEVEL) && rm -rf *.o)
	(cd $(MENU) && rm -rf *.o)
	(cd $(EVENT) && rm -rf *.o)
	(cd $(HUD) && rm -rf *.o)

debug:	CPPFLAGS += -g3

fclean: clean
	$(RM) $(NAME)

re: clean  fclean all

.PHONY: clean fclean re all
