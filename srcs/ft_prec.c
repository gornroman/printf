/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:38:37 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:55:24 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_place_zero3(char *str, int *i, int *j)
{
	str[(*j)++] = '0';
	(*i)++;
}

char		*ft_prec_diouxx(char *string, t_settings *settings)
{
	char	*str;
	int		i;
	int		j;

	if (settings->precision == 0 && (ft_strcmp(string, "0\0")) == 0)
		return ("\0");
	j = 0;
	i = ft_strlen(string);
	str = ft_strnew(settings->precision + 1);
	if (settings->negative == 1)
		ft_place_minus(str, &i, &j);
	while (i < settings->precision)
		ft_place_zero2(str, &i, &j);
	i = 0;
	while (i < ft_check_space(string))
		ft_place_zero3(str, &i, &j);
	i = 0;
	if (settings->negative == 1)
		i++;
	while (string[i] != '\0')
		str[j++] = string[i++];
	str[j - ft_check_space(string)] = '\0';
	if ((ft_strcmp(str, "0\0")) == 0)
		str[0] = ' ';
	return (str);
}

char		*ft_prec_f(char *string)
{
	char	*str;
	int		i;

	i = 0;
	str = ft_strnew(ft_strlen(string));
	while (string[i] != '\0')
	{
		if (string[i] == '.')
			str[i] = '\0';
		else
			str[i] = string[i];
		i++;
	}
	return (str);
}

void		ft_prec_s(char *str, char **finalstr, t_settings *settings)
{
	int		i;

	i = 0;
	while (i < settings->precision)
	{
		str[i] = finalstr[0][i];
		i++;
	}
	str[i] = '\0';
}

char		*ft_precision(char **finalstr, t_settings *settings)
{
	char	*str;

	str = ft_strnew(ft_strlen(finalstr[0]));
	if (settings->flaghash == 1)
		str = ft_strcat("", finalstr[0]);
	else
		str[0] = '\0';
	if (settings->type == 's')
		ft_prec_s(str, finalstr, settings);
	else
	{
		if (settings->precision == 0 &&
				(ft_strcmp(finalstr[0], "0\0")) == 0 && settings->type == 'o')
			return (str);
		str = ft_prec_diouxx(finalstr[0], settings);
		if (settings->type == 'f' && settings->precision == 0 &&
				settings->flaghash == 0)
			str = ft_prec_f(finalstr[0]);
	}
	if (settings->type != 's' && settings->str_move != 1)
		free(finalstr[0]);
	return (str);
}
