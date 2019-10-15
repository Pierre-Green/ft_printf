# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 16:32:36 by pguthaus          #+#    #+#              #
#    Updated: 2019/10/15 20:14:45 by pguthaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		clang

CFLAGS		=		-g
INCDIR		=		includes

NAME		=		libftprintf.a
T_NAME		=		tests_bin

SRCS		=		clear.c				\
					ft_printf.c			\
					buff/flush.c		\
					buff/write.c		\
					fmt/fmt.c			\
					fmt/convert_char.c	\
					fmt/convert_str.c	\
					fmt/convert_int.c	\
					fmt/convert_uint.c	\
					fmt/convert_hex.c	\

T_SRCS	=			assert.c		\
					main.c			\
					test_static.c	\
					test_fmt.c		\

OBJS_DIR	=		./objs/lib/
OBJS		=		$(addprefix $(OBJS_DIR),$(SRCS:.c=.o))

T_OBJS_DIR	=		./objs/tests/
T_OBJS		=		$(addprefix $(T_OBJS_DIR),$(T_SRCS:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)%.o: lib/%.c
	@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

tests: $(NAME) $(T_OBJS)
	@$(CC) $(CFLAGS) -I $(INCDIR) $(T_OBJS) $(NAME) -o $(T_NAME)
	@./$(T_NAME)

$(T_OBJS_DIR)%.o: tests/%.c
	@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) -I $(INCDIR) -o $@ -c $<

clean:
	rm -rf $(OBJS_DIR)

fclean: clean
	rm -f $(NAME) $(T_NAME)

re: fclean $(NAME)
