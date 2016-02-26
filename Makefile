# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/28 08:35:37 by ftriquet          #+#    #+#              #
#    Updated: 2016/02/26 20:30:36 by ftriquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME = ft_printf/ft_printf.c \
		   ft_printf/fill_flags.c \
		   ft_printf/printf_di.c \
		   ft_printf/printf_u.c \
		   ft_printf/buffer.c \
		   ft_printf/ft_printf_c.c \
		   ft_printf/ft_printf_s.c \
		   ft_printf/printf_s_utils.c \
		   ft_printf/printf_wchar.c \
		   ft_printf/printf_color.c \
		   ft_printf/printf_divs.c \
		   ft_empty_string.c \
		   ft_tabsize.c \
		   ft_atoi.c \
		   ft_itoa.c \
		   ft_nbr_len.c \
		   init.c \
		   get_next_line.c \
		   ft_trim.c \
		   ft_strsubptr.c \
		   ft_match.c \
		   ft_realloc.c \
		   ft_bzero.c \
		   ft_get_index.c \
		   ft_isalnum.c \
		   ft_isalpha.c \
		   ft_isascii.c \
		   ft_isblank.c \
		   ft_isdigit.c \
		   ft_islower.c \
		   ft_isprint.c \
		   ft_isupper.c \
		   ft_freetab.c \
		   ft_memalloc.c \
		   ft_memccpy.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_memcpy.c \
		   ft_memdel.c \
		   ft_memmove.c \
		   ft_memset.c \
		   ft_putchar.c \
		   ft_putchar_fd.c \
		   ft_putendl.c \
		   ft_putendl_fd.c \
		   ft_putnbr.c \
		   ft_putnbr_fd.c \
		   ft_putstr.c \
		   ft_putstr_fd.c \
		   ft_strcat.c \
		   ft_strchr.c \
		   ft_strclr.c \
		   ft_strcmp.c \
		   ft_strcpy.c \
		   ft_strdel.c \
		   ft_strdup.c \
		   ft_strequ.c \
		   ft_striter.c \
		   ft_striteri.c \
		   ft_strjoin.c \
		   ft_strlcat.c \
		   ft_strlen.c \
		   ft_strmap.c \
		   ft_strmapi.c \
		   ft_strncat.c \
		   ft_strncmp.c \
		   ft_strncpy.c \
		   ft_strnequ.c \
		   ft_strnew.c \
		   ft_strnlen.c \
		   ft_strnstr.c \
		   ft_strrchr.c \
		   ft_strsplit.c \
		   ft_copy_word.c \
		   ft_strstr.c \
		   ft_strsub.c \
		   ft_strtrim.c \
		   ft_tolower.c \
		   ft_toupper.c

OBJ_NAME = $(SRC_NAME:.c=.o)

SRC_PATH = ./src

OBJ_PATH = ./obj

SRC = $(addprefix $(SRC_PATH)/, $(SRC_NAME))

OBJ = $(addprefix $(OBJ_PATH)/, $(OBJ_NAME))

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

INC_PATH = ./includes

HEADERS_NAME = libft.h ft_printf.h

HEADERS = $(addprefix $(INC_PATH)/, $(HEADERS_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(HEADERS)
	@mkdir -p ./obj/ft_printf
	gcc $(CFLAGS) -c $< -o $@ -I $(INC_PATH)

clean:
	rm -f $(OBJ)

fclean:clean
	rm -f $(NAME)

re:fclean all

test:
	echo SRC_NAME: $(SRC_NAME)
	echo SRC: $(SRC)

.PHONY: all clean fclean re
