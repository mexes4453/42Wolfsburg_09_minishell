/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_get_env_path_dirs.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 21:26:57 by cudoh             #+#    #+#             */
/*   Updated: 2022/10/15 11:05:54 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	**ft_split_path_dirs(char *str)
{
	size_t	str_len;
	char	*str_cpy;
    char    **str_cpy_split;

	str_len = ft_strlen(str);
	str_cpy = (char *)malloc(sizeof(char) * (str_len +  1));
	if (str_cpy == NULL)
		return ((void *)0);
	ft_memcpy(str_cpy, str, (str_len + 1));
    str_cpy_split = ft_split(str_cpy, ':');
    //free(str_cpy);
	return (str_cpy_split);
}

char    **ft_ms_get_env_path_dirs(void)
{
    char    **env_path_dirs;
    char    *env_path;
    int     flag_debug;
    int		idx;

    idx = 0;
    flag_debug = 0;
    env_path_dirs = NULL;
    env_path = getenv("PATH");
    if (env_path == NULL)
        return ((void *)0);
    if (flag_debug)
        ft_printf("\n%s\n", env_path);
    env_path_dirs = ft_split_path_dirs(env_path);
    if (env_path_dirs == 0)
        return ((void *)0);
    if (flag_debug)
    {
        while (env_path_dirs[idx] != 0)
        {
            ft_printf("\n%s", env_path_dirs[idx]);
            // free(&(env_path_dirs[idx]));
            idx++;
        }
    }
    return(env_path_dirs);
}