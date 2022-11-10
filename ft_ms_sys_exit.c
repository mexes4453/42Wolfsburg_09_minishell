/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_sys_exit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/20 10:55:50 by cudoh             #+#    #+#             */
/*   Updated: 2022/10/20 11:07:30 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

/**
 * @brief   This func checks if the exit command is given by the user
 *          The function handles whitespaces that may exist before the cmd. 
 * 
 * @param cmd_str 
 * @return int  -1 is returned if the user have given the exit command
 *               0 is returned if no exit command is the first word in str.
 */
int ft_ms_sys_exit(char *cmd_str)
{
    char    *s;

    s = cmd_str;
    while (*s != '\0' && ft_strchr(P_WHITESPACE, *s))
        s++;
    if (strncmp(s, "exit", ft_strlen("exit")) == 0)
    {
        free(cmd_str);
        // free(v_p.env_path);
        // ft_printf("\n%s", v_p.env_path[0]);
        exit (0);
    }
    return (0);
}
