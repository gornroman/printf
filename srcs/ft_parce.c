/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parce.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:37:37 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:38:20 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_getflag(char **str, t_settings *settings)
{
	if (!**str)
		settings->flag = (settings->flag) - 1;
	while (**str)
	{
		if (**str == '-')
			settings->flagminus = 1;
		else if (**str == '+')
			settings->flagplus = 1;
		else if (**str == ' ')
			settings->flagspace = 1;
		else if (**str == '0')
			settings->flagzero = 1;
		else if (**str == '#')
			settings->flaghash = 1;
		else
		{
			settings->flag = (settings->flag) - 1;
			break ;
		}
		str[0]++;
	}
}

int			ft_getwidth(char **str, t_settings *settings)
{
	if (ft_isdigit(**str))
	{
		settings->width = ft_atoi(str[0]);
		while (ft_isdigit(**str))
			str[0]++;
		return (0);
	}
	settings->flag = (settings->flag) - 1;
	return (0);
}

void		ft_getprecision(char **str, t_settings *settings)
{
	if (**str == '.')
	{
		settings->precision = 0;
		str[0]++;
		settings->precision = ft_atoi(str[0]);
		while (ft_isdigit(**str))
			str[0]++;
	}
	else
		settings->flag = (settings->flag) - 1;
}

void		ft_getsize_help(char **str, t_settings *settings)
{
	if (str[0][0] == str[0][1])
	{
		settings->size = 'h' + 100;
		str[0]++;
	}
	else
		settings->size = 'h';
}

void		ft_getsize(char **str, t_settings *settings)
{
	if (!**str)
		settings->flag = (settings->flag) - 1;
	while (**str)
	{
		if (**str == 'L')
			settings->size = 'L';
		else if (**str == 'h')
			ft_getsize_help(str, settings);
		else if (**str == 'l')
		{
			if (str[0][0] == str[0][1])
			{
				settings->size = 'l' + 100;
				str[0]++;
			}
			else
				settings->size = 'l';
		}
		else
		{
			settings->flag = (settings->flag) - 1;
			break ;
		}
		str[0]++;
	}
}
