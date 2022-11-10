/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_handle_sig.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 15:27:21 by cudoh             #+#    #+#             */
/*   Updated: 2022/11/06 14:34:11 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"


void    ft_ms_handle_sig(int sig_val)
{
    if (sig_val == SIGINT)
    {
        rl_replace_line("", 0); 
        ft_putchar_fd('\n', STDOUT_FILENO);
        rl_on_new_line();
        rl_redisplay();
        return;
    }
}