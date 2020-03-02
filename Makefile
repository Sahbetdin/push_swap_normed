
CHECKER_NAME = checker
PS_NAME = push_swap
NAME = $(PS_NAME) $(CHECKER_NAME)
VIS_NAME = visual

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC =	check_conditions.c free1.c ft_atoi_backsp.c fun_print.c funs1.c \
		parse1.c piece_op1.c set.c sort2.c sort3.c sort41.c sort42.c \
		sort5.c stack_op0.c stack_op1.c stack_op2.c stack_op3.c stack_op4.c stack_op5.c	   

OBJECTS = $(patsubst %.c, %.o, $(SRC))

HEADER = ps_header.h

LIBFT_PATH = my_libft
LIBFT = $(LIBFT_PATH)/libft.a

RED = "\033[0;31m"
GREEN = "\033[0;32m"
WHITE_B = "\033[1m"
WHITE = "\033[0m"

.PHONY: all clean fclean re FAKE

all: $(CHECKER_NAME) $(PS_NAME)

$(PS_NAME): $(LIBFT) $(OBJECTS) push_swap.c
		@$(CC) $(CFLAGS) -o $(PS_NAME) push_swap.c $(OBJECTS) -I $(LIBFT_PATH) -L $(LIBFT_PATH) -lft
		@echo $(WHITE_B) push_swap $(WHITE)created.

$(CHECKER_NAME): $(LIBFT) $(OBJECTS) checker.c
		@$(CC) $(CFLAGS) -o $(CHECKER_NAME) checker.c $(OBJECTS) -I $(LIBFT_PATH) -L $(LIBFT_PATH) -lft
		@echo $(WHITE_B) checker $(WHITE)created. 

$(OBJECTS): %.o: %.c $(HEADER)
		@$(CC) $(CFLAGS) -o $@ -c $< -I$(HEADER) 
		@echo push_swap: $(GREEN) $< $(WHITE)

$(LIBFT): FAKE
		@$(MAKE) -C $(LIBFT_PATH)

visual:	$(OBJECTS) $(LIBFT) visual.c
		@$(CC) $(CFLAGS) -o $(VIS_NAME) visual.c $(OBJECTS) -I $(LIBFT_PATH) -L $(LIBFT_PATH) -lft
		@echo $(WHITE_B) visualization $(WHITE)created.

clean:
		@/bin/rm -f *.o
		@$(MAKE) -C $(LIBFT_PATH) clean
		@echo $(WHITE_B) push_swap and checker files deleted!$(WHITE)

fclean: clean
		@/bin/rm -f $(PS_NAME)
		@/bin/rm -f $(CHECKER_NAME)
		@/bin/rm -f visual
		@$(MAKE) -C $(LIBFT_PATH) fclean

re: fclean all
