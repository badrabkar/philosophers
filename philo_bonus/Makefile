CC = cc

NAME = philo_bonus

FLAGS = -Wall -Wextra -Werror

HEADER = ./philo_bonus.h

SRC = parsing_bonus.c\
	  philo_bonus.c\
	  philo_init_bonus.c\
	  philo_utils_bonus.c\
	  eat_sleep_think_repeat_bonus.c\

OBJ = $(SRC:.c=.o)

$(NAME) : $(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $(NAME) 

%.o : %.c
	$(CC) -c $< -o $@

all : $(NAME)

clean : 
	rm  -rf *.o
fclean : clean
	rm -rf $(NAME)
re : fclean all 