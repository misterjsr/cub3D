# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/15 15:25:39 by jeserran          #+#    #+#              #
#    Updated: 2020/07/21 17:52:11 by jeserran         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 	libft.a

COMP =		gcc -Wall -Werror -Wextra $(LIBFT_H) -c -o

LIBFT_H =	-I includes/

OBJ_DIR =	objects/
SRC_DIR =	sources/

CFILE	= 	ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strlen.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_atoi.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strncmp.c \
			ft_strlcat.c \
			ft_strnstr.c \
			ft_strdup.c \
			ft_calloc.c \
			ft_strlcpy.c \
			ft_substr.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_itoa.c \
			ft_strmapi.c \
			ft_split.c \
			ft_isspace.c \
			ft_putchar.c \
			ft_strnew.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strndup.c \
			ft_putstr.c \
			ft_putnbrmax_fd.c \
			ft_itoa_base.c \
			ft_putnbrumax_fd.c \
			ft_lstnew_bonus.c \
			ft_lstadd_front_bonus.c \
			ft_lstsize_bonus.c \
			ft_lstlast_bonus.c \
			ft_lstadd_back_bonus.c \
			ft_lstdelone_bonus.c \
			ft_lstclear_bonus.c \
			ft_lstiter_bonus.c \
			ft_lstmap_bonus.c \
			ft_strcmp.c

CFIND =		$(CFILE:%=$(SRC_DIR)%)
		
OFILE =		$(CFILE:%.c=%.o)
			
OBJ =		$(addprefix $(OBJ_DIR), $(OFILE))	

all: 		$(OBJ_DIR) $(NAME)

$(OBJ_DIR):
			@mkdir -p $(OBJ_DIR)
			@echo Create: libft Object directory

all:		$(OBJ_DIR) $(NAME)
bonus:
			rc $(NAME) $(addprefix $(OBJ_DIR), $(CBONUS:%.c=%.o))

$(NAME): 	$(OBJ)
			@ar rc $(NAME) $(addprefix $(OBJ_DIR), $(OFILE))
			@ranlib $(NAME)
			@echo libft COMPLETE

$(OBJ): 	$(CFIND)
			@$(MAKE) $(OFILE)

$(OFILE):
			@echo Create: $(@:obj/%=%)
			@$(COMP) $(OBJ_DIR)$@ $(SRC_DIR)$(@:%.o=%.c)

clean:
			@/bin/rm -rf $(OBJ_DIR)
			@echo Cleaned libft object files

fclean: 	clean
			@/bin/rm -f $(NAME)
			@echo Cleaned $(NAME)

re: 		fclean all

.PHONY: 	all clean fclean re
