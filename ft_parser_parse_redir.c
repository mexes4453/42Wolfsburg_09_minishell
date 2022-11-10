/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_parse_redir.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 13:43:18 by cudoh             #+#    #+#             */
/*   Updated: 2022/10/02 14:52:13by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief 	This function parses the usr command input string into recursive
 * 			execution tree based on the context free grammar below.
 * 			< aaa or << aaa or > aaa or >> aaa
 * 
 * @param cmd 
 * @param str_s 
 * @param str_e 
 * @param v 
 * @return t_cmd* 
 */
t_cmd	*ft_parser_parse_redir(t_cmd *cmd, char **str_s, char *str_e, \
								t_parser_var *v)
{
	char	*tk_s;
	char	*tk_e;

	while (ft_parser_peek(str_s, str_e, "<>"))
	{
		v->tok = ft_parser_get_token(str_s, str_e, 0, 0);
		if (ft_parser_get_token(str_s, str_e, &tk_s, &tk_e) != 'a')
			write(2, "Error! missing file - redir", 27);
		if (v->tok == '<')
			cmd = ft_parser_init_cmd_redir(cmd, tk_s, tk_e, v->f_read, 0);
		else if (v->tok == '>')
			cmd = ft_parser_init_cmd_redir(cmd, tk_s, tk_e, v->f_owrite, 1);
		else if (v->tok == '+')
			cmd = ft_parser_init_cmd_redir(cmd, tk_s, tk_e, v->f_awrite, 1);
		else if (v->tok == '-')
			cmd = ft_parser_init_cmd_redir(cmd, tk_s, tk_e, v->f_awrite, 1);
	}
	return (cmd);	
}
