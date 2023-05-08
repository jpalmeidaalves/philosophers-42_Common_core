PHILO		= philo

CC      	= cc 

CFLAGS		= -Wall -Werror -Wextra -g

RM		= rm -rf

SRC		= $(wildcard src/*.c)

OBJ		= $(SRC:.c=.o)

SRC_B		= $(wildcard bonus/*.c)

OBJ_B		= $(SRC:.c=.o)


	
all: $(philo)

bonus: $(philo_bonus)

$(PHILO): $(OBJ) $(LIBFT) $(SRC)
	$(CC) -g $(CFLAGS) $(SRC) -o philo

$(LIBFT):
	$(MAKE) -C ./libft

$(PHIL0_BONUS): $(OBJ_B) $(SRC_B)
	$(CC) -g $(CFLAGS) $(SRC_B) -o philo_bonus
	
clean: 
	$(RM) $(OBJ) 
	
fclean: clean
	$(RM) $(PHILO) $(PHILO_BONUS)

re:	fclean all
