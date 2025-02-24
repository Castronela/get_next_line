CC		:= gcc -g
CFLAGS	:= -Wall -Wextra -Werror -MMD
RM		:= rm -rf

RED		:= \033[0;31m
GREEN	:= \033[0;32m
RESET	:= \033[0m

D_SRC	:= src
D_INC	:= include
D_OBJ	:= obj

SRC		:= get_next_line.c get_next_line_utils.c
OBJ		:= $(addprefix $(D_OBJ)/, $(SRC:.c=.o))
DEP		:= $(addprefix $(D_OBJ)/, $(SRC:.c=.d))

VPATH	:= $(D_SRC)

NAME	:= libgnl.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rc $@ $(OBJ) && echo Library file "$(GREEN)$@$(RESET)" is ready

-include $(DEP)

$(D_OBJ)/%.o: %.c | $(D_OBJ)
	@$(CC) $(CFLAGS) -I$(D_INC) -c $< -o $@

$(D_OBJ):
	@mkdir -p $@

clean:
	@$(RM) $(D_OBJ)

fclean: clean
	@$(RM) $(NAME)

re: fclean
	@$(MAKE) all -s 

run: all
	@$(CC) test.c -I$(D_INC) -L. -lgnl && ./a.out

val: all
	@$(CC) test.c -I$(D_INC) -L. -lgnl && valgrind --leak-check=full --show-leak-kinds=all ./a.out

.PHONY: all clean fclean re

