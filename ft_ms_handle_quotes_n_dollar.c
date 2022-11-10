/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ms_handle_quotes_n_dollar.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cudoh <cudoh@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 21:33:08 by cudoh             #+#    #+#             */
/*   Updated: 2022/11/08 21:41:06 by cudoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_preserve_arg(char **argv_n, char **txt_s, char *s)
{
	int		len_str;
	char	*txt;
	char 	*tmp_argv_n;

	len_str = s - *txt_s;
	if (len_str == 0)
		return;
	txt = ft_calloc((len_str + 1), sizeof(char));
	ft_memcpy(txt, *txt_s, len_str);
	if (*argv_n == NULL)
	{
		*argv_n = txt;
	}
	else
	{
		tmp_argv_n = *argv_n;
		*argv_n = ft_strjoin(tmp_argv_n, txt);
		free(tmp_argv_n);
		free(txt);
	}
	
}

static void ft_append_txt_to_arg(char **str, char **txt_s, char **txt_e)
{
	size_t	len_str;
	char	*txt;
	char	*str_tmp;
	
	len_str = *txt_e - *txt_s;
	if (len_str == 1)
		return ;
	txt = ft_calloc((len_str + 1), sizeof(char));
	ft_memcpy(txt, *txt_s, len_str);
	if (*str == NULL)
	{
		*str = txt;
	}
	else
	{
		str_tmp = *str;
		*str = ft_strjoin(str_tmp, txt);
		free(str_tmp);
		free(txt);
	}
}

/**
 * @brief 		This function checks to see if the quote with the usr command
 * 				is even numbered ('->34, "->39).
 * 				The quote char is updated as the string chars are examined
 * 				while transversing the string.
 *
 * @param usr_inp
 * @param flag
 * @param quote
 */
static void ft_handle_dollar_n_quote(char **argv, int *flag, char *q, int *f_d)
{
	char 	*s;
	char	*str_s;
	char 	*str_e;
	char	*txt_s;
	char	*txt_e;
	char	*argv_n;

	s = *argv;
	str_s = *argv;
	str_e = s + ft_strlen(s);
	argv_n = NULL;
	while (s < str_e)
	{
		if (*s == '$' && *flag == 0)
		{
			// Do something to recreate the string here.
		}
		else if (*flag == 1 && *s == *q)
		{
			*flag = 0;
			txt_e = s;
			str_s = s + 1;
			ft_append_txt_to_arg(&argv_n, &txt_s, &txt_e);
			if (*f_d)
				ft_printf("quote_state: %d\n", *flag);
		}
		else if (*flag == 0 && (*s == 39 || *s == 34))
		{
			*q = *s;
			*flag = 1;
			ft_preserve_arg(&argv_n, &str_s, s);
			txt_s = s + 1;
			if (*f_d)
				ft_printf("quote_state: %d\n", *flag);
		}
		s++;
	}
	if (argv_n != NULL)
		*argv = argv_n;
}




void ft_ms_handle_quotes_n_dollar(char **argv_s)
{
    int		idx;
	int		flag;
	char	quote;
	int		flag_debug;
	
	idx = 0;
	flag = 0;
	quote = 0;
	flag_debug = 1;
	while (argv_s[idx] != 0)
	{
		ft_handle_dollar_n_quote(&argv_s[idx], &flag, &quote, &flag_debug);
		idx++;
	}
    
}

