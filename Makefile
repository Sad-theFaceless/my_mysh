# PARAMETERS

SRC	= ./src/arg.c \
	  ./src/env.c \
	  ./src/error_msg.c \
	  ./src/exec_abs.c \
	  ./src/exec.c \
	  ./src/exec_cd.c \
	  ./src/main.c \
	  ./src/misc.c \
	  ./src/path.c \
	  ./src/pwd.c \
	  ./src/senv.c \
	  ./src/shell.c \
	  ./src/signal.c \
	  ./src/usenv.c
NAME	= mysh
DEBUG	= 0
MOREF	= 1
LNCURSE = 1
LBLAPIN = 0
LBMATHS = 0
LIBMY	= 1
DRAW	= 1
SILENT	= 1

# COMPILATION

CFLAGS	+=
ifeq	($(MOREF), 1)
CFLAGS	+= -W -Wall -Wextra -pedantic -Wmissing-prototypes
endif
ifeq	($(DEBUG), 1)
CFLAGS	+= -g3
endif
ifeq	($(LIBMY), 1)
LIBS	+= -L./lib -lmy
endif
ifeq    ($(LBLAPIN), 1)
CFLAGS	+= -I/home/${USER}/.froot/include \
	-L/home/${USER}/.froot/lib \
	-llapin \
	-lsfml-audio \
	-lsfml-graphics \
	-lsfml-window \
	-lsfml-system \
	-lstdc++ \
	-ldl \
	-lm \
	-Werror \
	-ansi
endif
ifeq	($(LBLAPIN)$(LBMATHS), 01)
CFLAGS	+= -lm
endif
ifeq	($(LNCURSE), 1)
CFLAGS	+= -lncurses
endif

# SILENTS

ifeq	($(SILENT), 1)
.SILENT: $(OBJ)
.SILENT: $(NAME)
.SILENT: clean
.SILENT: fclean
.SILENT: re
endif

# MACROS

COMP    = cc
RM      = rm -rf

# DISPLAY

GREEN	= \033[1;32m
RED	= \033[1;31m
BLUE	= \033[1;34m
YELLOW	= \033[1;33m
WHITE	= \033[0m
RELEASE = $(BLUE)[RELEASE MODE]$(WHITE)
DEBUGAG = $(YELLOW)[DEBUGGING MODE]$(WHITE)
MOREFLA	= $(RED)[MORE FLAGS]$(WHITE)
LESSFLA = $(GREEN)[LESS FLAGS]$(WHITE)
WARN	= $(RED)/!\ $(WHITE)
SMILE_R	= $(GREEN)(>*-*)>$(WHITE)
SMILE_L	= $(GREEN)<(*-*<)$(WHITE)

# CONSTRUCTION EXECUTABLE

all:	$(NAME)

$(NAME):
ifeq	($(LIBMY), 1)
	make -C ./lib/my all
endif
	$(COMP) $(SRC) -o $(NAME) $(LIBS) $(CFLAGS)
ifeq    ($(DRAW), 1)
ifeq	($(DEBUG)$(MOREF), 11)
	@echo -e "\n     $(WARN) $(WARN) $(WARN) $(WARN)\n"
	@echo -e "$(WARN)  $(DEBUGAG)   $(WARN)\n"
	@echo -e "$(WARN)    $(MOREFLA)     $(WARN)\n"
	@echo -e "     $(WARN) $(WARN) $(WARN) $(WARN)\n"
else ifeq ($(DEBUG)$(MOREF), 10)
	@echo -e "\n     $(WARN) $(WARN) $(WARN) $(WARN)\n"
	@echo -e "$(WARN)  $(DEBUGAG)   $(WARN)\n"
	@echo -e "$(WARN)    $(LESSFLA)     $(WARN)\n"
	@echo -e "     $(WARN) $(WARN) $(WARN) $(WARN)\n"
else ifeq ($(DEBUG)$(MOREF), 01)
	@echo -e "\n        $(SMILE_R)$(SMILE_L)\n"
	@echo -e "$(SMILE_R) $(RELEASE) $(SMILE_L)\n"
	@echo -e "$(SMILE_R)  $(MOREFLA)  $(SMILE_L)\n"
	@echo -e "        $(SMILE_R)$(SMILE_L)\n"
else ifeq ($(DEBUG)$(MOREF), 00)
	@echo -e "\n        $(SMILE_R)$(SMILE_L)\n"
	@echo -e "$(SMILE_R) $(RELEASE) $(SMILE_L)\n"
	@echo -e "$(SMILE_R)  $(LESSFLA)  $(SMILE_L)\n"
	@echo -e "        $(SMILE_R)$(SMILE_L)\n"
endif
endif

clean:
ifeq	($(LIBMY), 1)
	make -C ./lib/my clean
endif

fclean: clean
	$(RM) $(NAME)
ifeq	($(LIBMY), 1)
	make -C ./lib/my fclean
endif

re:	fclean all clean
