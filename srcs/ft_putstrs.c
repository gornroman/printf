/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstrs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:46:16 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:47:26 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_strcat(char *s1, char *s2)
{
	char	*res;
	size_t	i;
	size_t	j;

	res = ft_strnew((ft_strlen(s1) + ft_strlen(s2) + 1));
	i = 0;
	j = 0;
	while (s1[j] != '\0')
		res[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr_plus_help(char *s, t_settings *settings, int *i, int *len)
{
	if (settings->flagminus == 1)
	{
		*i = 1;
		while (*i < (int)ft_strlen(s) + 1)
		{
			ft_putchar(s[*len]);
			settings->result = settings->result + 1;
			(*i)++;
			(*len)--;
		}
		return ;
	}
	else
	{
		*i = 1;
		while (*i < (int)ft_strlen(s) + 1)
		{
			ft_putchar(s[*i]);
			settings->result = settings->result + 1;
			(*i)++;
		}
		return ;
	}
}

void		ft_putstr_plus(char *s, t_settings *settings)
{
	int	i;
	int len;

	len = (int)ft_strlen(s);
	i = 0;
	if (settings->cnull == 1)
	{
		ft_putstr_plus_help(s, settings, &i, &len);
		return ;
	}
	while (s[i] != '\0')
	{
		ft_putchar(s[i]);
		i++;
	}
	settings->result = settings->result + (int)ft_strlen(s);
}

size_t		ft_strlen_b(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != 'c' && s[i] != 's' && s[i] != 'p' && s[i] != 'f' &&
			s[i] != 'd' && s[i] != 'i' && s[i] != 'o' && s[i] != 'u' &&
			s[i] != 'x' && s[i] != 'X')
	{
		if (s[i + 1] == '%')
		{
			if (s[i + 2] == '%' || s[i + 2] == 'c' || s[i + 2] == 's' ||
					s[i + 2] == 'p' || s[i + 2] == 'f' || s[i + 2] == 'd' ||
					s[i + 2] == 'i' || s[i + 2] == 'o' || s[i + 2] == 'u' ||
					s[i + 2] == 'x' || s[i + 2] == 'X')
				return (++i);
		}
		i++;
	}
	return (++i);
}
