/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_mods.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:49:31 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:55:36 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_precision2(char **finalstr, t_settings *settings)
{
	char	*str;
	int		i;

	str = ft_strnew(ft_strlen(finalstr[0]));
	i = 0;
	if (settings->type == 's')
	{
		while (i <= settings->precision)
		{
			str[i] = finalstr[0][i];
			i++;
		}
		str[i] = '\0';
	}
	else
	{
		str = ft_prec_diouxx(finalstr[0], settings);
		if (settings->type == 'f' && settings->precision == 0
				&& settings->flaghash == 0)
			str = ft_prec_f(finalstr[0]);
	}
	return (str);
}

void		ft_dif_negative(char **finalstr, t_settings *settings)
{
	if (settings->flagplus == 1)
		ft_add_plus(finalstr, settings);
	else if (settings->flagspace == 1)
	{
		if (finalstr[0][0] != '-' && finalstr[0][0] != '+' &&
			finalstr[0][0] != ' ')
			ft_add_space(finalstr, settings);
	}
}

void		ft_str_mod2(char **finalstr, t_settings *settings)
{
	settings->firstlen = (int)ft_strlen(finalstr[0]);
	if (finalstr[0][0] == '0')
		settings->x_is_zero = 1;
	if (settings->precision > -1 && settings->type != 'c')
		finalstr[0] = ft_precision(finalstr, settings);
	settings->len = (int)ft_strlen(finalstr[0]);
	if (settings->len < settings->width)
	{
		if (settings->flagminus == 1)
			ft_flagminus_1(finalstr, settings);
		else
			ft_flagminus_0(finalstr, settings);
	}
	if (settings->flagzero == 1 && settings->type != 'c' &&
			settings->type != 's' && settings->type != 'p')
		ft_place_zero(finalstr, settings);
	if ((settings->type == 'd' || settings->type == 'i' ||
				settings->type == 'f') && settings->negative == 0)
		ft_dif_negative(finalstr, settings);
	if ((settings->type == 'o' || settings->type == 'x' ||
				settings->type == 'X' || settings->type == 'f') &&
			settings->flaghash == 1 && settings->x_is_zero != 1)
		ft_flag_hash(finalstr, settings);
}

void		ft_str_mod3(char **doublestr, t_settings *settings)
{
	if (settings->precision > -1)
		doublestr[0] = ft_precision2(doublestr, settings);
	settings->len = (int)ft_strlen(doublestr[0]);
	if (settings->len < settings->width)
	{
		if (settings->flagminus == 1)
			ft_flagminus_1(doublestr, settings);
		else
			ft_flagminus_0(doublestr, settings);
	}
	if (settings->flagzero == 1 && settings->flag == -6 &&
			settings->flagminus != 1)
		ft_place_zero(doublestr, settings);
}

char		*ft_char_to_str(va_list ap)
{
	char	*str;

	str = ft_strnew(2);
	str[0] = va_arg(ap, int);
	str[1] = '\0';
	return (str);
}
