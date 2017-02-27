# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: barnout <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/09 20:20:32 by barnout           #+#    #+#              #
#    Updated: 2017/02/27 17:11:59 by barnout          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a

SRC_BASE=	libft/ft_atoi.c		\
			libft/ft_bzero.c	\
			libft/ft_isalnum.c	\
			libft/ft_isalpha.c	\
			libft/ft_isascii.c	\
			libft/ft_isdigit.c	\
			libft/ft_isprint.c	\
			libft/ft_memccpy.c	\
			libft/ft_memchr.c	\
			libft/ft_memcmp.c	\
			libft/ft_memcpy.c	\
			libft/ft_memccpy.c	\
			libft/ft_memmove.c	\
			libft/ft_memset.c	\
			libft/ft_putchar.c	\
			libft/ft_putnbr.c	\
			libft/ft_putstr.c	\
			libft/ft_strcat.c	\
			libft/ft_strchr.c	\
			libft/ft_strcpy.c	\
			libft/ft_strdup.c	\
			libft/ft_strlcat.c	\
			libft/ft_strlen.c	\
			libft/ft_strncat.c	\
			libft/ft_strcmp.c	\
			libft/ft_strncmp.c	\
			libft/ft_strncpy.c	\
			libft/ft_strnstr.c	\
			libft/ft_strrchr.c	\
			libft/ft_strstr.c	\
			libft/ft_tolower.c	\
			libft/ft_toupper.c	\
			libft/ft_memalloc.c	\
			libft/ft_memdel.c	\
			libft/ft_strnew.c	\
			libft/ft_strdel.c	\
			libft/ft_strclr.c	\
			libft/ft_striter.c	\
			libft/ft_striteri.c	\
			libft/ft_strmap.c	\
			libft/ft_strmapi.c	\
			libft/ft_strequ.c	\
			libft/ft_strnequ.c	\
			libft/ft_strsub.c	\
			libft/ft_strjoin.c	\
			libft/ft_strtrim.c	\
			libft/ft_strsplit.c	\
			libft/ft_itoa.c		\
			libft/ft_putendl.c	\
			libft/ft_putchar_fd.c	\
			libft/ft_putstr_fd.c	\
			libft/ft_putendl_fd.c	\
			libft/ft_putnbr_fd.c	\
			srcs/ft_printf.c \
			srcs/conversion_functions.c \
			srcs/conversion_functions2.c \
			srcs/conversion_utils.c \
			srcs/conversion_wstr.c \
			srcs/conversion_wstr2.c \
			srcs/flags.c \
			srcs/ft_ltoa.c \
			srcs/ft_imaxtoa.c \
			srcs/ft_printf.c \
			srcs/get_functions.c \
			srcs/get_functions2.c \
			srcs/get_functions3.c \
			srcs/precision.c \
			srcs/padding.c \
			srcs/print_functions.c \
			srcs/print_functions2.c \
			srcs/print_functions3.c \
			srcs/put_functions.c \
			srcs/read_args.c \
			srcs/utils.c \
			srcs/utils2.c \
			srcs/wstr_utils.c \
			srcs/swap_minus.c

				

OBJS	=	$(SRC_BASE:.c=.o)

GCC		=	gcc

CFLAGS	+=	-Wall -Wextra -Werror

RM		=	rm -f

all		:	$(NAME)

%.o: %.c includes/libftprintf.h
		@gcc -I includes -c $< -o $@

$(NAME)	:	$(OBJS)
			@ar rc $(NAME) $(OBJS)
			@ranlib $@

clean	:	
			$(RM) $(OBJS)

fclean	:	clean
			$(RM) $(NAME)

re		:	fclean all

.PHONY: clean all re fclean
