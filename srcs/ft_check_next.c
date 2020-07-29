/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_next.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:01:54 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:12:41 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_next_flags(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == 'c' || s[i] == 's' || s[i] == 'p' ||
				s[i] == 'f' || s[i] == 'd' || s[i] == 'i' ||
				s[i] == 'o' || s[i] == 'u' || s[i] == 'x' ||
				s[i] == 'X')
			return (i);
		i++;
	}
	return (0);
}

int		ft_check_next_pers(char *s)
{
	int		i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
			return (1);
		i++;
	}
	return (0);
}

int		ft_stop(int len, char *s)
{
	while (s[len] != ' ')
		len--;
	return (len);
}

char	*ft_cut_str3(char *string)
{
	int		i;
	int		len;
	char	*str;

	len = ft_strlen_b(string);
	i = 0;
	str = ft_strnew(len + 1);
	if (ft_strcmp(string, "   %") == 0 || ft_strcmp(string, " %}") == 0)
	{
		ft_cut_str3_h(str, string, len);
		return (str);
	}
	while (i < len)
	{
		if (ft_check_next_pers(string) == 1)
			str[ft_stop(ft_check_next_flags(string), string)] = '\0';
		str[i] = string[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	ft_gettype(char **str, t_settings *settings)
{
	if (**str == 'c')
		settings->type = 'c';
	else if (**str == 's')
		settings->type = 's';
	else if (**str == 'p')
		settings->type = 'p';
	else if (**str == 'f')
		settings->type = 'f';
	else if (**str == 'd')
		settings->type = 'd';
	else if (**str == 'i')
		settings->type = 'i';
	else if (**str == 'o')
		settings->type = 'o';
	else if (**str == 'u')
		settings->type = 'u';
	else if (**str == 'x')
		settings->type = 'x';
	else if (**str == 'X')
		settings->type = 'X';
	else
		settings->flag = (settings->flag) - 1;
}
