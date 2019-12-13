NAME = day01
SRCS = ./*.c
OBJS = ./*.o
LIBS = ./
CFLAGS = -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	gcc -o $(NAME) $(SRCS) -I$(LIBS) $(CFLAGS)

$(OBJS):
	gcc -c $(SRCS)

clean:
	rm -rf ./*.o

fclean: clean
	rm -rf $(NAME)

re: fclean all
