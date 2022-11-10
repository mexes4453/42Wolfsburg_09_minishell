/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_sys_chdir.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 22:15:14 by cudoh             #+#    #+#             */
/*   Updated: 2022/10/15 09:32:35 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief   This function changes the directory to that given by the user.
 *          The function handles whitespaces that may exist within the cmd. 
 * 
 * @param cmd_str 
 * @return int 
 */
int ft_ms_sys_chdir(char *cmd_str)
{
    char    *s;
    
    s = cmd_str;
    while (*s != '\0' && ft_strchr(P_WHITESPACE, *s))
        s++;
    if (s[0] == 'c' && s[1] == 'd' && s[2] == ' ')
    {
        s = &(s[3]);
        while (*s != '\0' && ft_strchr(P_WHITESPACE, *s))
            s++;
        if (chdir(s) < 0)
        {
            perror("Error!\nchdir");
            return (-1);
        }
        else
            return (0);
    }
    return (-1);
}
