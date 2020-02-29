
CHECKER_NAME = checker
PS_NAME = push_swap
NAME = $(PS_NAME) $(CHECKER_NAME)
VIS_NAME = visual

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = procedure.c parse1.c parse2.c ft_atoi_backsp.c \
	act1.c act2.c funs1.c funs2.c funs3.c funs4.c \
	sort2.c set.c sort3.c sort41.c sort42.c fun_print.c check_conditions.c

OBJECTS = $(patsubst %.c, %.o, $(SRC))

HEADER = ps_header.h

LIBFT_PATH = my_libft
LIBFT = $(LIBFT_PATH)/libft.a

RED = "\033[0;31m"
GREEN = "\033[0;32m"
WHITE_B = "\033[1m"
WHITE = "\033[0m"

.PHONY: all clean fclean re FAKE

all: $(NAME)

$(NAME): $(LIBFT) $(OBJECTS) push_swap.c checker.c
		@$(CC) $(CFLAGS) -o $(PS_NAME) push_swap.c $(OBJECTS) -I $(LIBFT_PATH) -L $(LIBFT_PATH) -lft
		@echo $(WHITE_B) push_swap $(WHITE)created. 
		@$(CC) $(CFLAGS) -o $(CHECKER_NAME) checker.c $(OBJECTS) -I $(LIBFT_PATH) -L $(LIBFT_PATH) -lft
		@echo $(WHITE_B) checker $(WHITE)created. 

$(OBJECTS): %.o: %.c $(HEADER)
		@$(CC) $(CFLAGS) -o $@ -c $< -I$(HEADER) 
		@echo push_swap: $(GREEN) $< $(WHITE)

$(LIBFT): FAKE
		@$(MAKE) -C $(LIBFT_PATH)

visual:	$(OBJECTS) visual.c
		@$(CC) $(CFLAGS) -o $(VIS_NAME) visual.c $(OBJECTS) -I $(LIBFT_PATH) -L $(LIBFT_PATH) -lft
		@echo $(WHITE_B) visualization $(WHITE)created.

clean:
		@/bin/rm -f *.o
		@$(MAKE) -C $(LIBFT_PATH) clean
		@echo $(WHITE_B) push_swap and checker files deleted!$(WHITE)

fclean: clean
		@/bin/rm -f $(PS_NAME)
		@/bin/rm -f $(CHECKER_NAME)
		@$(MAKE) -C $(LIBFT_PATH) fclean


re: fclean all
