/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_find_prog.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 23:00:25 by cudoh             #+#    #+#             */
/*   Updated: 2022/11/08 23:33:54 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	ft_ms_find_prog(char **env_path_dirs, char **prog, t_parser_var *v_p)
{
    int				idx;
	DIR				*dir_stream;
	struct dirent	*dir_entry_s;
	char			*path_prog;

	idx = 0;
	dir_entry_s = NULL;
	path_prog = NULL;
	if ((prog[0][0] == '.') || (prog[0][0] == '/'))
		return ;
	if (v_p->flag_debug) ft_printf("\n%s", v_p->env_path[idx]);
	while (env_path_dirs[idx] != 0)
	{
		if (v_p->flag_debug) ft_printf("\n%s", env_path_dirs[idx]);
		dir_stream = opendir(env_path_dirs[idx]);
		while (1)
		{
			dir_entry_s = readdir(dir_stream);
			if (dir_entry_s == NULL)
			{
				closedir(dir_stream);
				break ;
			}
			if ((ft_strlen(dir_entry_s->d_name) == ft_strlen(prog[0])) &&
				ft_strncmp(prog[0], dir_entry_s->d_name, \
										ft_strlen(prog[0])) == 0)
			{
				path_prog = ft_strjoin(env_path_dirs[idx], "/");
				prog[0] = ft_strjoin(path_prog, prog[0]);
				free(path_prog);
				v_p->prog_path = prog[0];
				closedir(dir_stream);
				return ;
			}
		}
		idx++;
	}
}