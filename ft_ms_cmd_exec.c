/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_cmd_exec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 09:39:56 by cudoh             #+#    #+#             */
/*   Updated: 2022/11/09 10:34:59 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief   This function is used within the ft_ms_exec_cmd function to
 *          execute any exec cmd found within the parsed tree return by the
 *          ft_parser_parse function.
 * 
 * @param cmd 
 */
void    ft_ms_cmd_exec(t_cmd *cmd, t_parser_var *v_p)
{
    t_cmd_exec  *cmd_exec;

    cmd_exec = (t_cmd_exec *)cmd;
    if (cmd_exec->argv_s[0] == 0)
        exit(1);
    ft_ms_handle_status(cmd_exec->argv_s, v_p);
    ft_ms_handle_quotes_n_dollar(cmd_exec->argv_s);
    //if (ft_ms_sys_prog(cmd_exec->argv_s) > 0)
    //    exit(0);
    ft_ms_find_prog(v_p->env_path, cmd_exec->argv_s, v_p);
    if (v_p->flag_debug) ft_printf("\n%s\n", cmd_exec->argv_s[0]);
    execve(cmd_exec->argv_s[0], cmd_exec->argv_s, v_p->env);
    // check to free the env
    ft_printf("Error! (%s) :", cmd_exec->argv_s[0]);
    perror("execve");
    exit(1);
}


