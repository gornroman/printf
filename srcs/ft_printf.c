/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:44:48 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:45:55 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_analyze_2(char **doublestr, t_settings *settings)
{
	settings->flag = 0;
	ft_getflag(doublestr, settings);
	ft_getprecision(doublestr, settings);
	ft_getwidth(doublestr, settings);
	ft_getsize(doublestr, settings);
	ft_gettype(doublestr, settings);
}

int		ft_analyze(char *string, t_settings *settings, va_list ap)
{
	char		**doublestr;
	char		*str;
	int			a;
	char		*str2;

	str = ft_cut_str3(string);
	str2 = str;
	doublestr = &str2;
	a = (int)ft_strlen(doublestr[0]);
	ft_initialiazatoin(settings);
	while (settings->type == '0')
	{
		ft_analyze_2(doublestr, settings);
		if (settings->flag == -5)
		{
			ft_unflag(doublestr, settings);
			settings->i += a;
			free(str);
			return (0);
		}
	}
	settings->i += a;
	free(str);
	ft_prepare_str(settings, ap);
	return (0);
}

int		ft_printf(char *param, ...)
{
	va_list		ap;
	t_settings	settings;

	settings.result = 0;
	settings.i = 0;
	va_start(ap, param);
	while (param[settings.i] != '\0')
	{
		if (param[settings.i] != '%')
		{
			ft_putchar(param[settings.i++]);
			settings.result++;
		}
		else
			ft_analyze(param + ++settings.i, &settings, ap);
	}
	va_end(ap);
	return (settings.result);
}
