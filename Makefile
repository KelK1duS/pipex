# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedarenn <bedarenn@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/25 23:28:11 by bedarenn          #+#    #+#              #
#    Updated: 2024/02/23 13:59:00 by bedarenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

DIR_SRCS = srcs/
DIR_OBJS = objs/
DIR_INCL = headers/
DIR_LIBS = libs/
DIR_WATI = $(DIR_SRCS)libwati/
DIR_GNL = GNL/

GNL = \
	get_next_line.c \
	new_buffer.c \
	manage_buffer.c \
	read_file.c \
	get_file.c

SRC = \
	$(addprefix $(DIR_GNL), $(GNL)) \
	get_var.c \
	get_cmds.c \
	manage_cmd.c \
	manage_pid.c \
	manage_close.c \
	manage_open.c \
	wati_pip.c \
	wati_fork.c

SRCS = \
	$(SRC) \
	main.c

SRCS_BONUS = \
	$(SRC) \
	heredoc.c \
	heredoc_tools.c \
	main_bonus.c

OBJS = $(addprefix $(DIR_OBJS), $(SRCS:%.c=%.o))
OBJS_BONUS = $(addprefix $(DIR_OBJS), $(SRCS_BONUS:%.c=%.o))

CFLAGS = -Wall -Wextra -Werror
IFLAGS = -I$(DIR_INCL)
LFLAGS = -L$(DIR_LIBS) -lwati

NAME = pipex

all: libwati $(NAME)

bonus: $(OBJS_BONUS)
	$(CC) $^ $(LFLAGS) -o $(NAME)

$(NAME): $(OBJS)
	$(CC) $^ $(LFLAGS) -o $@

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
	@mkdir -p $(DIR_OBJS) $(DIR_OBJS)$(DIR_GNL)
	$(CC) $(CFLAGS) $(IFLAGS) -c $^ -o $@ 

clean:
	make -C $(DIR_WATI) clean
	rm -rf $(DIR_OBJS)

fclean: clean
	make -C $(DIR_WATI) fclean
	rm -f $(NAME)

libwati:
	make -C $(DIR_WATI) -j
	@cp $(DIR_WATI)libwati.h $(DIR_INCL)
	@cp $(DIR_WATI)libwati.a $(DIR_LIBS)


re: fclean all

run: re
	./pipex "." "ls -la" "wc -l" "a"

.PHONY: all clean fclean re
