NAME				=	push_swap

DIRECTORY_SOURCE	=	srcs

FILES_SOURCE		=	srcs/PushSwap/push_swap.c \
						srcs/PushSwap/commands/command_utils.c \
						srcs/PushSwap/commands/push_and_swap.c \
						srcs/PushSwap/commands/reverse_rotate.c \
						srcs/PushSwap/commands/rotate.c \
						srcs/PushSwap/utils/base_utils.c \
						srcs/PushSwap/utils/parse_input.c

O_FILE = $(FILES_SOURCE:.c=.o)

COMPILE				=	gcc
COMPILATION_FLAG	=	-Wall -Wextra -Werror

all: $(NAME)

%.o: %.c
	@printf "\e[33m"
	@printf "Compile\t$< -> $@\n"
	mkdir -p $(dir $@)
	$(COMPILE) $(COMPILATION_FLAG) -c $< -o $@

$(NAME): $(O_FILE)
	@printf "\e[32m"
	@printf "Build\t$@\n"
	$(COMPILE) -o $@ $(FILES_SOURCE)

clean:
	@printf "\e[31m"
	@printf "Remove\n"
	rm -rf $(O_FILE)

fclean: clean
	@printf "Remove\t$(NAME)\n"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re