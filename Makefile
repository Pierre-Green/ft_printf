# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 16:32:36 by pguthaus          #+#    #+#              #
#    Updated: 2019/10/25 18:36:55 by pguthaus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			=		clang

CFLAGS		=		-g
INCS		=		-I includes -I libft/includes

NAME		=		libftprintf.a
LIBFT		=		libft/libft.a
T_NAME		=		tests_bin

SRCS		=		clear.c				\
					ft_printf.c			\
					buff/flush.c		\
					buff/write_alpha.c	\
					buff/write_num.c	\
					buff/write_hex.c	\
					fmt/fmt.c			\
					fmt/values.c		\
					fmt/convert_char.c	\
					fmt/convert_str.c	\
					fmt/convert_ptr.c	\
					fmt/convert_int.c	\
					fmt/convert_uint.c	\
					fmt/convert_hex.c	\
					fmt/convert_hex_up.c\

T_SRCS	=			assert.c		\
					main.c			\
					tests_static.c	\
					tests_char.c	\
					tests_str.c		\
					tests_ptr.c		\
					tests_int.c		\
					tests_uint.c	\
					tests_hex.c		\
					tests_poly.c	\

OBJS_DIR	=		./objs/lib/
OBJS		=		$(addprefix $(OBJS_DIR),$(SRCS:.c=.o))

T_OBJS_DIR	=		./objs/tests/
T_OBJS		=		$(addprefix $(T_OBJS_DIR),$(T_SRCS:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJS_DIR)%.o: srcs/%.c
	@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

tests: $(NAME) $(T_OBJS)
	@$(CC) $(CFLAGS) $(INCS) $(T_OBJS) $(NAME) -o $(T_NAME)
	@./$(T_NAME)

$(T_OBJS_DIR)%.o: tests/%.c
	@if [ ! -d $(dir $@) ]; then mkdir -p $(dir $@); fi
	$(CC) $(CFLAGS) $(INCS) -o $@ -c $<

$(LIBFT):
	$(MAKE) -C libft libft.a

clean:
	rm -rf $(OBJS_DIR) $(T_OBJS_DIR)

fclean: clean
	rm -f $(NAME) $(T_NAME)

re: fclean $(NAME)
