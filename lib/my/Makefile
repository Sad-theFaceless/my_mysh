# PARAMETERS

SRC	= my_getnbr.c \
          my_printf.c \
          my_revstr.c \
          my_strcmp.c \
          my_strlen.c \
	  my_epur_str.c \
          ./error/my_putchar_e.c \
          ./error/my_putstr_e.c \
          ./fct_printf/my_putchar.c \
          ./fct_printf/my_put_nbr.c \
          ./fct_printf/my_put_nbr_base.c \
          ./fct_printf/my_putstr.c \
          ./fct_printf/my_strascii.c
NAME	= libmy.a
MOREF	= 1
DRAW	= 0
SILENT	= 1

# COMPILATION

CFLAGS	+=
ifeq	($(MOREF), 1)
CFLAGS	+= -W -Wall -Wextra -pedantic -Wmissing-prototypes
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
OBJ     = $(SRC:.c=.o)

# DISPLAY

GREEN	= \033[1;32m
RED	= \033[1;31m
BLUE	= \033[1;34m
YELLOW	= \033[1;33m
WHITE	= \033[0m
RELEASE = $(BLUE)[RELEASE MODE]$(WHITE)
MOREFLA	= $(RED)[MORE FLAGS]$(WHITE)
LESSFLA = $(GREEN)[LESS FLAGS]$(WHITE)
SMILE_R	= $(GREEN)(>*-*)>$(WHITE)
SMILE_L	= $(GREEN)<(*-*<)$(WHITE)

# CONSTRUCTION EXECUTABLE

all:	$(NAME)

$(NAME):
ifeq	($(LIBMY), 1)
	make -C ./lib/my all
endif
	$(COMP) $(CFLAGS) -c $(SRC)
	mv my_putchar_e.o ./error/
	mv my_putstr_e.o ./error/
	mv my_putchar.o ./fct_printf/
	mv my_put_nbr.o ./fct_printf/
	mv my_put_nbr_base.o ./fct_printf/
	mv my_putstr.o ./fct_printf/
	mv my_strascii.o ./fct_printf/
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	mv ./$(NAME) ../
	cp ./my.h ../../include/
ifeq    ($(DRAW), 1)
ifeq	($(MOREF), 1)
	@echo "\n        $(SMILE_R)$(SMILE_L)\n"
	@echo "$(SMILE_R) $(RELEASE) $(SMILE_L)\n"
	@echo "$(SMILE_R)  $(MOREFLA)  $(SMILE_L)\n"
	@echo "        $(SMILE_R)$(SMILE_L)\n"
else ifeq ($(MOREF), 0)
	@echo "\n        $(SMILE_R)$(SMILE_L)\n"
	@echo "$(SMILE_R) $(RELEASE) $(SMILE_L)\n"
	@echo "$(SMILE_R)  $(LESSFLA)  $(SMILE_L)\n"
	@echo "        $(SMILE_R)$(SMILE_L)\n"
endif
endif

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) ../$(NAME)

re:	fclean all clean
