/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_sys_echo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 12:39:35 by cudoh             #+#    #+#             */
/*   Updated: 2022/10/30 12:45:49 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "parser.h"

int	ft_ms_sys_echo(char **argv)
{
	// just print only text
	int	idx;

	idx = 0;
	while (argv[idx] != NULL)
	{
		ft_printf("%s", argv[idx]);
		idx++;
	}
	
}