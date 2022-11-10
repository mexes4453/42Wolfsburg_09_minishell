/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/02 10:58:36 by cudoh             #+#    #+#             */
/*   Updated: 2022/10/15 11:02:20 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief 	This function takes in the usr command input as string and returns
 * 			a pointer to the tree structure of command (recursive depth 
 * 			parsing) for execution.
 * 
 * @param s 
 * @return t_cmd* 
 */
t_cmd   *ft_parser_parse(char *s, t_parser_var *v)
{
    char	*es;
	t_cmd	*cmd;

	es = s + ft_strlen(s);

    if (v->flag_debug)
    {
        int c = 0;
        while (*(s + c) != '\0')
        {
            ft_printf("\n%p -> %c", (s + c), *(s + c));
            c++;
        }
        ft_printf("\n");
    }

    if (v->flag_debug) ft_printf("\n->parse_line_s\n");
    cmd = ft_parser_parse_line(&s, es, v);
    if (v->flag_debug) ft_printf("\n->parse_line_e\n");
    ft_parser_peek(&s, es, "");
    if (v->flag_debug) ft_printf("\nPARSE, txt_s (%p); txt_e (%p)", s, es);
    if (s != es)
    {
        ft_printf("\nPARSE, txt_s (%p); txt_e (%p)\n", s, es);
		write(2, "Error!\nSyntax: ", 15);
		write(2, s, ft_strlen(s));
        *cmd = P_ERROR;
        return (cmd);
    }
    ft_parser_null_term(cmd);
	return (cmd);
}