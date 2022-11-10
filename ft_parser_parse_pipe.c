/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_parse_pipe.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:07:02 by cudoh             #+#    #+#             */
/*   Updated: 2022/10/15 11:11:57 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief   This function parses the usr command input string into recursive
 *		  	execution tree based on the context free grammar CFG below.
 *		  	PIPE -> EXEC [|LINE].
 *			This parse is performed based on the pipe character.
 * 
 * @param str_s 
 * @param str_e 
 * @return t_cmd* 
 */
t_cmd	*ft_parser_parse_pipe(char **str_s, char *str_e, t_parser_var *v)
{
	t_cmd	*cmd;

    if (v->flag_debug) ft_printf("\n\n-->parse_exec_s\n");
	cmd = ft_parser_parse_exec(str_s, str_e, v);
    if (v->flag_debug) ft_printf("\n-->parse_exec_e\n");
	if (ft_parser_peek(str_s, str_e, "|"))
	{
		ft_parser_get_token(str_s, str_e, 0, 0);
		cmd = ft_parser_init_cmd_pipe(cmd, ft_parser_parse_pipe(str_s, str_e, v));
	}
	return (cmd);
}
