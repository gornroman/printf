/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flagminus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:18:48 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:18:52 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_f_to_str(va_list ap, t_settings *settings)
{
	long double res;
	char		*str;

	res = ft_find_f_size(settings, ap);
	if (res < 0)
		settings->negative = 1;
	if (settings->precision > 19)
		str = ft_ftoa2(res, settings);
	else
		str = ft_ftoa(res, settings);
	return (str);
}

void		ft_flagminus_1(char **finalstr, t_settings *settings)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew((size_t)settings->width);
	while (finalstr[0][i] != '\0')
	{
		str[i] = finalstr[0][i];
		i++;
	}
	while ((settings->width - settings->len) > 0)
	{
		str[i] = ' ';
		i++;
		settings->len++;
	}
	if (settings->flag != -6 && settings->type != 's'
			&& settings->str_move != 1)
		free(finalstr[0]);
	finalstr[0] = str;
}

void		ft_flagminus_0(char **finalstr, t_settings *settings)
{
	char	*str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	str = ft_strnew((size_t)settings->width + 1);
	while ((settings->width - settings->len) > 0)
	{
		str[i] = ' ';
		i++;
		settings->len++;
	}
	while (finalstr[0][j] != '\0')
	{
		str[i] = finalstr[0][j];
		i++;
		j++;
	}
	str[i] = '\0';
	if (settings->flag != -6 && settings->str_move != 1 &&
			settings->type != 's')
		free(finalstr[0]);
	finalstr[0] = str;
}

int			ft_check_space(char *str)
{
	int		i;
	int		space;

	space = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ')
			space++;
		i++;
	}
	return (space);
}

void		ft_add_plus(char **finalstr, t_settings *settings)
{
	int		i;

	i = 0;
	if (settings->flagminus == 0 && (ft_check_space(finalstr[0]) > 0) &&
			settings->zerocount == 0)
	{
		while (finalstr[0][i] == ' ')
			i++;
		finalstr[0][i - 1] = '+';
	}
	else if (settings->zerocount > 0)
		finalstr[0][0] = '+';
	else
	{
		ft_putchar('+');
		if (ft_check_space(finalstr[0]) != 0)
			finalstr[0][ft_strlen(finalstr[0]) - 1] = '\0';
		settings->result = settings->result + 1;
	}
}
