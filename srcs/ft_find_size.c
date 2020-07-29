/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:13:16 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:14:43 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long int			ft_find_di_size(t_settings *settings, va_list ap)
{
	long long int res;

	if (settings->size == 'h')
		res = (short int)va_arg(ap, int);
	else if (settings->size == 'h' + 100)
		res = (signed char)va_arg(ap, int);
	else if (settings->size == 'l')
		res = va_arg(ap, long int);
	else if (settings->size == 'l' + 100)
		res = va_arg(ap, long long int);
	else
		res = va_arg(ap, int);
	return (res);
}

char					*ft_int_to_str(va_list ap, t_settings *settings)
{
	long long int			res;
	unsigned long long int	ures;
	char					*str;

	res = ft_find_di_size(settings, ap);
	if (res < 0)
	{
		settings->negative = 1;
		ures = res * -1;
		str = ft_strcat("-", ft_itoa_ull(ures));
	}
	else
		str = ft_itoa_ll(res);
	if (ft_strcmp(str, "0\0") == 0 && settings->type != 'd')
		settings->str_move = 1;
	if (ft_strcmp(str, "0\0") == 0 && settings->type == 'd'
			&& settings->precision == 0)
		settings->str_move = 1;
	return (str);
}

unsigned long long int	ft_find_p_size(t_settings *settings, va_list ap)
{
	unsigned long long int res;

	if (settings->size == 'h')
		res = (unsigned short)va_arg(ap, int);
	else if (settings->size == 'h' + 100)
		res = (unsigned char)va_arg(ap, int);
	else if (settings->size == 'l')
		res = va_arg(ap, unsigned long);
	else if (settings->size == 'l' + 100)
		res = va_arg(ap, unsigned long long);
	else
		res = (unsigned long long int)va_arg(ap, void*);
	return (res);
}

unsigned long long int	ft_find_ou_size(t_settings *settings, va_list ap)
{
	unsigned long long int res;

	if (settings->size == 'h')
		res = (unsigned short)va_arg(ap, int);
	else if (settings->size == 'h' + 100)
		res = (unsigned char)va_arg(ap, int);
	else if (settings->size == 'l')
		res = va_arg(ap, unsigned long);
	else if (settings->size == 'l' + 100)
		res = va_arg(ap, unsigned long long);
	else
		res = (unsigned int)va_arg(ap, int);
	if (res == 0)
		settings->str_move = 1;
	return (res);
}

void					ft_x_to_x(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 102)
			str[i] = str[i] - 32;
		i++;
	}
}
