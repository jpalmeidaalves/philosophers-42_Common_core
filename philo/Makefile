NAME		= philo

CC      	= cc 

CFLAGS		= -Wall -Werror -Wextra

RM		= rm -rf

SRC		= $(wildcard src/*.c)

OBJ = $(addprefix $(OBJSDIR)/, $(SRC:.c=.o))

SRC_B		= $(wildcard bonus/*.c)

OBJ_B = $(addprefix $(OBJS_B_DIR)/, $(SRC_B:.c=.o))

OBJSDIR = objects

	
all: $(NAME)

bonus: $(philo_bonus)

$(NAME): $(OBJ) $(SRC)
	$(CC) -g $(CFLAGS) $(SRC) -o philo

$(PHIL0_BONUS): $(OBJ_B) $(SRC_B)
	$(CC) -g $(CFLAGS) $(SRC_B) -o philo_bonus


$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ) 
	
fclean: clean
	$(RM) $(PHILO) $(PHILO_BONUS)

re:	fclean all
