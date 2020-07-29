/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prepare_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:42:12 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:44:18 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_void_to_str(va_list ap, t_settings *settings)
{
	if (settings->type == 'c')
		return (ft_char_to_str(ap));
	else if (settings->type == 's')
		return (va_arg(ap, char*));
	else if (settings->type == 'd' || settings->type == 'i')
		return (ft_int_to_str(ap, settings));
	else if (settings->type == 'o' || settings->type == 'u' ||
			settings->type == 'x' || settings->type == 'X' ||
			settings->type == 'p')
		return (ft_ou_to_str(ap, settings));
	else if (settings->type == 'f')
		return (ft_f_to_str(ap, settings));
	return (NULL);
}

void		ft_change_flags(t_settings *settings)
{
	if (settings->precision > 0 && settings->type != 'f')
		settings->flagzero = 0;
	if (settings->flagplus == 1)
		settings->flagspace = 0;
	if (settings->flagminus == 1)
		settings->flagzero = 0;
}

void		ft_type_c(t_settings *settings, char **doublestr)
{
	if (settings->type == 'c' && doublestr[0][0] == '\0')
	{
		if (settings->width == -1)
		{
			write(1, &doublestr[0][0], 1);
			settings->result = settings->result + 1;
		}
		else
		{
			settings->cnull = 1;
			ft_str_mod2(doublestr, settings);
			ft_putstr_plus(doublestr[0], settings);
		}
	}
	else
	{
		ft_str_mod2(doublestr, settings);
		ft_putstr_plus(doublestr[0], settings);
	}
}

void		ft_prepare_str(t_settings *settings, va_list ap)
{
	char	*str;
	char	**doublestr;

	str = ft_void_to_str(ap, settings);
	doublestr = &str;
	ft_change_flags(settings);
	if (settings->type == 'x' && (ft_strcmp(str, "0") == 0) &&
			settings->precision == 0 && settings->width < 0)
		return ;
	if (settings->type == 'o' && (ft_strcmp(str, "0") == 0)
			&& settings->precision == 0
			&& settings->width < 0 && settings->flaghash == 0)
		return ;
	if (str == NULL)
		str = "(null)";
	ft_type_c(settings, doublestr);
	if (settings->type != 's' && settings->str_move != 1)
		free(str);
}

void		ft_unflag(char **doublestr, t_settings *settings)
{
	settings->type = 's';
	settings->flag = -6;
	ft_str_mod3(doublestr, settings);
	ft_putstr_plus(doublestr[0], settings);
}
