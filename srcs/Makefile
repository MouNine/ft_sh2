# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eboeuf <eboeuf@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/06 10:42:58 by eboeuf            #+#    #+#              #
#    Updated: 2015/03/27 13:55:01 by eboeuf           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	ft_minishell2
SRC			=	srcs/
SRCS		=	$(SRC)ft_minishell2.c \
				$(SRC)ft_env.c \
				$(SRC)ft_exec.c \
				$(SRC)ft_print.c \
				$(SRC)ft_setenv.c \
				$(SRC)ft_func.c \
				$(SRC)ft_builtins.c \
				$(SRC)ft_cd.c
OBJS		=	$(SRCS:.c=.o)
INCDIR		=	includes/
LIBDIR 		=	libft/
LIB 		=	$(LIBDIR)libft.a
LIB_COMP	=	-L ./$(LIBDIR) -lft
CC			=	clang
FLAGS		=	-I $(INCDIR) -Wall -Wextra -Werror

RED = \033[33;31m
BLUE = \033[33;34m
GREEN = \033[33;32m
RESET = \033[0m

.PHONY: all re fclean

all: $(NAME)

$(LIB):
		@$(MAKE) -C $(LIBDIR)

$(NAME): $(LIB) $(OBJS)
		@$(CC) -o $(NAME) $(FLAGS) $^ -ltermcap $(LIB_COMP)
		@rm -f $(DEP).gch
		@echo "[$(GREEN)Compilation $(BLUE)$(NAME) $(GREEN)ok$(RESET)]"

%.o: %.c
		@$(CC) -c -o $@ $(FLAGS) $^

clean:
	@cd $(LIBDIR) && $(MAKE) $@
	@rm -f $(OBJS)
	@echo "[$(RED)Supression des .o de $(BLUE)$(NAME) $(GREEN)ok$(RESET)]"

fclean: clean
		@cd $(LIBDIR) && $(MAKE) $@
		@rm -f $(NAME)
		@echo "[$(RED)Supression de $(BLUE)$(NAME) $(GREEN)ok$(RESET)]"

re: fclean all

