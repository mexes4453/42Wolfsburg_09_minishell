# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 15:08:09 by cudoh             #+#    #+#              #
#    Updated: 2022/11/08 21:37:48 by cudoh            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SRCS:= $(shell ls *.c | grep -v lst | xargs)

SRCS:= main.c ft_ms_get_env_path_dirs.c ft_exec_cmd.c ft_ms_sys_open_fd.c \
				ft_ms_sys_chdir.c ft_ms_sys_exit.c ft_ms_run_cmd.c  ft_ms_cmd_exec.c \
				ft_ms_cmd_pipe.c  ft_ms_cmd_list.c ft_ms_cmd_redir.c \
				ft_ms_find_prog.c ft_ms_handle_status.c ft_ms_handle_sig.c \
				ft_ms_chk_quote.c ft_ms_handle_quotes_n_dollar.c \
		parser.c ft_parser_init_var.c   ft_parser_get_max_args.c \
				 ft_parser_get_token.c  ft_parser_peek.c ft_parser_parse.c \
				 ft_parser_parse_line.c ft_parser_parse_pipe.c \
				 ft_parser_parse_exec.c ft_parser_parse_redir.c \
				 ft_parser_null_term.c \
		ft_term_config_init.c ft_term_config_set.c \

SRCS_BONUS:= main_bonus.c queue_utils_bonus.c \
		map_a_utils_bonus.c map_b_utils_bonus.c map_c_utils_bonus.c \
		map_d_utils_bonus.c \
		nav_a_utils_bonus.c nav_b_utils_bonus.c \
		app_a_utils_bonus.c app_b_utils_bonus.c app_c_utils_bonus.c \
		app_d_utils_bonus.c app_e_utils_bonus.c \
		app_f_utils_bonus.c app_g_utils_bonus.c app_h_utils_bonus.c \


OBJS_BONUS:=$(SRCS_BONUS:.c=.o)
OBJS:= $(SRCS:.c=.o)

NAME = minishell
USR_LIB = libft.a
USR_LIB_PATH = ./libft

CC = cc
#CFLAGS = -Werror -Wall -Wextra -O3 -g #-fsanitize=address
CFLAGS = -Werror -Wall -Wextra -g
LIBFLAGS_STATIC = -L$(USR_LIB_PATH) -lft  -lreadline -lncurses -L/usr/lib 
INCLUDES = -I./ -I$(USR_LIB_PATH) 

NAME : all
all : $(NAME)
$(NAME) : $(OBJS) $(USR_LIB)
	@echo "\033[1;33mCompiling Executables: $(NAME) \033[0m"
	$(CC) $^ $(LIBFLAGS_STATIC) $(CFLAGS) $(INCLUDES) -o $@
	@echo; echo "\033[1;32mCompilation Successful. \033[0m"
	@echo; echo

	
bonus: $(USR_LIB) $(OBJS_BONUS)
	@echo # line spacing
	@echo "\033[1;33mCompiling BONUS - SO_LONG \033[0m"
	rm -rf $(OBJS) > /dev/null
	$(CC) $^ $(LIBFLAGS_STATIC) $(CFLAGS) $(INCLUDES) -o $(NAME)
	@echo "\033[1;32mCompilation Successful. \033[0m"


# obj files output
%.o : %.c
	@echo
	@echo "\033[1;33mCompiling OBJ files \033[0m"
	$(CC) -c $^ $(CFLAGS) $(INCLUDES) -o $@
	@echo


$(USR_LIB) :
	@echo
#	$(AR) $(LIBFLAGS_STATIC) $@ $^						# create the library file for linking
	@echo "\033[1;33mCompiling LIBFT Library \033[0m"
	cd ./libft; make > /dev/null; cp libft.a ../; cd ..	
	@echo												# print new line on screen

	

# remove all object files
fclean:
	rm -rf *.o
	cd ./libft; make fclean; cd ..;

# remove final target files
clean: fclean
	rm -rf $(NAME)
	rm -rf *.a
	cd ./libft; make clean; cd ..;

# recompile everything
re: clean all

.PHONY : all fclean clean re 