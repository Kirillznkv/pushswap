
NAME = push_swap
NAME_B = checker

SRC = push_swap.c \
		big_sort.c \
		lil_sort.c \
		count_steps.c

SRC_B = ./checker_bonus/checker.c \
		./checker_bonus/get_next_line.c \
		./checker_bonus/get_next_line_utils.c

SRC_ADD = ./utils/init_stack.c \
		./utils/create_array.c \
        ./utils/create_list.c \
		./utils/sort_and_insert.c \
		./utils/check_arguments.c \
		./utils/search.c \
		./utils/handlers.c \
		./utils/commands1.c \
        ./utils/commands2.c

FLAGS = -Wall -Wextra -Werror
OBJ = $(SRC:%.c=%.o)
OBJ_B = $(SRC_B:%.c=%.o)
OBJ_ADD = $(SRC_ADD:%.c=%.o)
HEADER = push_swap.h
HEADER_B = ./checker_bonus/checker.h
LIB = ./lib -lft
LINK_LIB = -L $(LIB)

all : $(NAME) $(SRC)

$(NAME) : $(OBJ) $(OBJ_ADD) $(HEADER)
	make -C $(LIB)
	make bonus -C $(LIB)
	gcc $(FLAGS) $(OBJ) $(OBJ_ADD) $(LINK_LIB) -o $@

$(OBJ) : %.o : %.c
	gcc $(FLAGS) -c  $< -o $@
$(OBJ_ADD) : %.o : %.c
	gcc $(FLAGS) -c  $< -o $@

bonus : $(OBJ_B) $(OBJ_ADD) $(HEADER_B)
		make -C $(LIB)
		make bonus -C $(LIB)
		gcc $(FLAGS) $(OBJ_B) $(OBJ_ADD) $(LINK_LIB) -o $(NAME_B)

$(OBJ_B) :%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean :
	rm -f $(OBJ)  $(OBJ_B) $(OBJ_ADD)
	make clean -C $(LIB)

fclean : clean
	rm -f $(NAME)
	rm -f $(NAME_B)
	make fclean -C $(LIB)

re :  fclean all

re_bonus : fclean bonus

.PHONY : all clean fclean re bonus