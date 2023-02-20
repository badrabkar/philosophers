CC = cc

NAME = philo

FLAGS = -Wall -Wextra -Werror -fsanitize=thread -g

HEADER = ./philo.h

SRC = eat_sleep_think_repeat.c\
	parsing.c\
	philo_init.c\
	philo_utils.c\
	philo.c\

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME) 

%.o : %.c
	$(CC) -c $< -o $@ $(FLAGS)

all : $(NAME)

clean : 
	rm  -rf *.o
fclean : clean
	rm -rf $(NAME)
re : fclean all 