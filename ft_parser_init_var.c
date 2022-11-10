/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parser_init_var.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/01 07:14:26 by cudoh             #+#    #+#             */
/*   Updated: 2022/11/09 18:13:18 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parser_init_var(t_parser_var *v_p, char **envp)
{
	ft_memset((void *)v_p, 0, sizeof(t_parser_var));
	v_p->str_s = NULL;
	v_p->str_e = NULL;
	v_p->usr_cmd_inp = NULL;
	v_p->f_read = O_RDONLY | S_IRWXU;
	v_p->f_awrite = O_WRONLY | O_CREAT | O_APPEND;
	v_p->f_owrite = O_WRONLY | O_TRUNC;
    v_p->flag_debug = 0;
    v_p->env = envp;
    v_p->env_path = ft_ms_get_env_path_dirs();
    if (v_p->flag_debug) ft_printf("\nFT_PARSER_INIT_VAR_ %s", v_p->env_path[0]);
    if (v_p->flag_debug) ft_printf("\nFT_PARSER_INIT_VAR_ %p", v_p->env_path);
    v_p->prog_path = NULL;
}
