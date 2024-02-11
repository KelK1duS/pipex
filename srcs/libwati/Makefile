# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bedarenn <bedarenn@student.42angouleme.fr  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 07:12:45 by bedarenn          #+#    #+#              #
#    Updated: 2024/01/21 16:16:48 by bedarenn         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = clang

DIR_SRCS = ./
DIR_OBJS = objs/
DIR_INCL = .
DIR_LIBS = ./

SRCS = \
	wati_isalpha.c wati_isdigit.c wati_isalnum.c wati_isascii.c wati_isprint.c wati_isupper.c wati_islower.c wati_isspace.c \
	wati_tolower.c wati_toupper.c wati_strupper.c wati_strlower.c \
	wati_sig.c wati_abs.c \
	wati_strlen.c wati_strlen_set.c \
	wati_memset.c wati_bzero.c \
	wati_memcpy.c wati_memmove.c wati_strlcpy.c wati_strlcat.c \
	wati_strchr.c wati_strrchr.c wati_memchr.c \
	wati_strncmp.c wati_memcmp.c wati_strnstr.c \
	wati_atoi.c wati_atoll.c wati_itoa.c wati_atoi_base.c wati_atou_base.c \
	wati_calloc.c \
	wati_strdup.c wati_substr.c \
	wati_strjoin.c wati_strtrim.c wati_split.c wati_join.c \
	wati_free_tab.c \
	wati_strmapi.c wati_striteri.c \
	wati_putchar_fd.c wati_putstr_fd.c wati_putendl_fd.c wati_putnbr_fd.c wati_putstrs_fd.c \
	wati_lstnew.c \
	wati_lstadd_front.c \
	wati_lstsize.c \
	wati_lstlast.c \
	wati_lstadd_back.c \
	wati_lstdelone.c \
	wati_lstclear.c \
	wati_lstiter.c \
	wati_lstmap.c \
	wati_lstjoin.c \
	wati_lstclean.c \
	wati_lstsplit.c \
	wati_printf.c wati_printf_arg.c wati_printf_utils_nbr.c wati_printf_utils_str.c

OBJS = $(addprefix $(DIR_OBJS), $(SRCS:%.c=%.o))

FLAGS = -Wall -Werror -Wextra

NAME = libwati.a

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(DIR_LIBS)$@ $^

$(DIR_OBJS)%.o: $(DIR_SRCS)%.c
	@mkdir -p $(DIR_OBJS)
	$(CC) $(FLAGS) -o $@ -c $^ -I$(DIR_INCL)

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) $(EXEC)

re: fclean all

.PHONY: all run clean fclean re