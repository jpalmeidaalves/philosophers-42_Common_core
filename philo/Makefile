# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: joaoalme <joaoalme@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/22 21:37:14 by joaoalme          #+#    #+#              #
#    Updated: 2023/07/24 14:51:03 by joaoalme         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo



CC      	= cc 

CFLAGS		= -Wall -Werror -Wextra -g

SANI		= -fsanitize=thread

RM		= rm -rf

SRC		= src/philo.c src/check_input.c src/monitor.c \
		  src/routine.c src/starting.c src/time_related.c  src/utils.c

OBJ = $(addprefix $(OBJSDIR)/, $(SRC:.c=.o))

SRC_B		= $(wildcard bonus/*.c)

OBJ_B = $(addprefix $(OBJS_B_DIR)/, $(SRC_B:.c=.o))

OBJSDIR = objects

	
all: $(NAME)

bonus: $(PHIL0_BONUS)

$(NAME): $(OBJ) $(SRC)
	$(CC) -g $(CFLAGS) $(SRC) -lpthread -o philo

$(PHIL0_BONUS): $(OBJ_B) $(SRC_B)
	$(CC) -g $(CFLAGS) $(SRC_B) -lpthread -o philo_bonus

sani: $(NAME)
	$(CC) -g $(CFLAGS) $(SANI) $(SRC) -lpthread -o philo

$(OBJSDIR)/%.o: %.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ) 
	
fclean: clean
	$(RM) $(NAME) $(PHILO_BONUS)

re:	fclean all
