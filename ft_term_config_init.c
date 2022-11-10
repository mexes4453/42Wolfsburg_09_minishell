/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_term_config_default.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 22:10:03 by cudoh             #+#    #+#             */
/*   Updated: 2022/10/27 22:44:51by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief 	This function is deactivate the SIG_QUIT signal for the console
 * 			by modifying the default console (terminal) settings. The default
 * 			settings is preserved for use within child processes as they may  
 * 			require the signal during their execution.
 * 
 * @param p_term_var 
 */
void    ft_term_config_init(t_term_var *p_term_var)
{
	char	*dev_tty;

	p_term_var->config_custom = ft_calloc(1, sizeof(struct termios));
	p_term_var->config_default = ft_calloc(1, sizeof(struct termios));

	dev_tty = ttyname(STDIN_FILENO);
	p_term_var->fd_tty = open(dev_tty, O_NONBLOCK);
	if (isatty(p_term_var->fd_tty))
	{
		printf("Terminal name: %s\n", dev_tty);
		tcgetattr(p_term_var->fd_tty, p_term_var->config_default);
		ft_memcpy(p_term_var->config_custom, p_term_var->config_default, \
					sizeof(struct termios));
		p_term_var->config_custom->c_lflag &= ~ISIG;
		p_term_var->config_custom->c_cc[VQUIT] = 0;
		tcsetattr(p_term_var->fd_tty, TCSANOW, p_term_var->config_custom);
	}
}