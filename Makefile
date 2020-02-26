# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: afoulqui <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/30 11:41:47 by afoulqui          #+#    #+#              #
#    Updated: 2020/02/04 16:15:49 by afoulqui         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	libftprintf.a

SRCS_DIR		=	srcs

SRCS_FILES		=	ft_printf.c \
						ft_printf_utils.c \
						ft_parse.c \
						ft_parse_utils.c \
						ft_get_flags.c \
						ft_print_d.c \
						ft_print_s.c \
						ft_print_c.c \
						ft_print_p.c \
						ft_print_u.c \
						ft_print_x.c \
						ft_print_prct.c
					
SRCS			=	$(addprefix $(SRCS_DIR)/, $(SRCS_FILES))

HEADER_DIR		=	./include/

HEADER			=	$(HEADER_DIR)ft_printf.h

OBJS			=	$(SRCS:.c=.o)

CC				=	gcc

CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -f

all:				$(NAME)

$(NAME):			$(OBJS)
						ar rc $(NAME) $(OBJS)
						ranlib $(NAME)

.c.o:		
						$(CC) $(FLAGS) -include $(HEADER) -c $< -o $(<:.c=.o)

clean:			
						$(RM) $(OBJS)

fclean:				clean
						$(RM) $(OBJS)

re:					fclean all

.PHONY:				all clean fclean re
