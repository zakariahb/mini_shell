# NAME = mini_shell

# SRCS = main.c ft_split.c

# OBJS = $(SRCS:.c=.o)

# CC = cc
# FLAGS = -Wall -Wextra -Werror 


# all : $(NAME)

# $(NAME) : $(OBJS)
# 	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -lreadline

# %.o: %.c mini_shell.h
# 	$(CC) $(FLAGS) -c $< -o $@

# make : make -C libft

# clean :
# 	rm -rf $(OBJS)

# fclean : clean
# 	rm -rf $(NAME)

# re : fclean all 

# git : git add .
# 	  git commit -m "mini_shell"
# 	  git push



NAME = mini_shell

SRCS = main.c ft_split.c
OBJS = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

READLINE_FLAGS = -lreadline

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -L$(LIBFT_DIR) -lft $(READLINE_FLAGS)

%.o: %.c mini_shell.h
	$(CC) $(FLAGS) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -rf $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

git:
	git add .
	git commit -m "mini_shell"
	git push