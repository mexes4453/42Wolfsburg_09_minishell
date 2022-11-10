/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:54:05 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/27 17:54:05 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <stdio.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <signal.h>
# include <errno.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <dirent.h>
# include <termios.h>
# include <ncurses.h>
# include "libft/libft.h"
# include "parser.h"
# define PROMPT ("minishell$> ")
# define TERM_CONFIG_DEFAULT (0)
# define TERM_CONFIG_CUSTOM (1)


typedef struct s_term
{
    struct termios  *config_custom;
    struct termios  *config_default;
	int				fd_tty;
}                   t_term_var;

char	**ft_ms_get_env_path_dirs(void);
int		ft_exec_cmd(void);
int 	ft_ms_run_cmd(t_cmd *cmd, t_parser_var *v_p);	
void	ft_ms_cmd_exec(t_cmd *cmd, t_parser_var *v_p);	
void	ft_ms_cmd_list(t_cmd *cmd, t_parser_var *v_p);	
void	ft_ms_cmd_pipe(t_cmd *cmd, t_parser_var *v_p);
void    ft_ms_cmd_redir(t_cmd *cmd, t_parser_var *v_p);
void	ft_ms_find_prog(char **env_path_dirs, char **prog, t_parser_var *v_p);
int		ft_ms_sys_open_fd(void);
int		ft_ms_sys_chdir(char *cmd_str);
int		ft_ms_sys_exit(char *cmd_str);
void    ft_ms_handle_status(char **argv_s, t_parser_var *v_p);
void    ft_ms_handle_sig(int sig_val);
void	ft_ms_handle_quotes_n_dollar(char **argv_s);
int		ft_ms_chk_quote(char **usr_inp);
void    ft_term_config_init(t_term_var *p_term_var);
void    ft_term_config_set(t_term_var *p_term_var, int option);
#endif