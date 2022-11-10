/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 17:53:37 by cudoh             #+#    #+#             */
/*   Updated: 2022/09/27 17:53:37 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int main(int argc, char *argv[], char *envp[])
{
    t_parser_var v_p;
	t_term_var	v_term;

    ft_parser_init_var(&v_p, envp);
	ft_term_config_init(&v_term);

    if (v_p.flag_debug)
        ft_printf("\nMAIN_ %s\n", v_p.env_path[0]);
    if (ft_ms_sys_open_fd() < 0)
	{
        return (-1);
	}
	signal(SIGINT, ft_ms_handle_sig);

	while (1)
	{
		v_p.usr_cmd_inp = readline(PROMPT);
		if (v_p.usr_cmd_inp == NULL)
		{
			free(v_term.config_custom);
			free(v_term.config_default);
			exit(0); // handle ctrl + D on empty prompt
		}

		v_p.str_len = ft_strlen(v_p.usr_cmd_inp);
		// handle single and double quotes here...
		if (ft_ms_chk_quote(&(v_p.usr_cmd_inp)) < 0)
			continue;
		//
        ft_parser_get_max_args(&v_p);
        if (v_p.flag_debug) ft_printf("arg_cnt : %d", v_p.max_args);
        if (v_p.flag_debug) ft_printf("arg_cnt : %d", argc);
        if (v_p.flag_debug) ft_printf("arg_cnt : %s", argv[0]);
        if (ft_ms_sys_chdir(v_p.usr_cmd_inp) == 0)
            continue;
        ft_ms_sys_exit(v_p.usr_cmd_inp);
        if (v_p.str_len > 0)
        {
            add_history(v_p.usr_cmd_inp);
            if (v_p.flag_debug)
                ft_printf("\nMAIN_ %s", v_p.usr_cmd_inp);
            v_p.cmd_tree = ft_parser_parse(v_p.usr_cmd_inp, &v_p);

			ft_term_config_set(&v_term, TERM_CONFIG_DEFAULT);
            if (fork() == 0)
            {
                ft_ms_run_cmd(v_p.cmd_tree, &v_p);
            }
            wait(&v_p.status);
			v_p.status_code = WIFEXITED(v_p.status);
            if (v_p.flag_debug) ft_printf("\nstatus: %d\n", v_p.status);
            if (v_p.flag_debug) ft_printf("\nstatus_code: %x\n", v_p.status_code);
			ft_term_config_set(&v_term, TERM_CONFIG_CUSTOM);
        }
        free(v_p.usr_cmd_inp);
        free(v_p.prog_path);
        v_p.usr_cmd_inp = NULL;
        v_p.prog_path = NULL;
	}
	return (0);
}