NAME = mini_shell

SRCS = main.c

OBJS = $(SRCS:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror 


all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(FLAGS) -o $(NAME) $(OBJS) -lreadline

%.o: %.c mini_shell.h
	$(CC) $(FLAGS) -c $< -o $@ -lreadline

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all 

git : git add .
	  git commit -m "mini_shell"
	  git push