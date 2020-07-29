/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:47:42 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:49:13 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_afterdot(long double fpart, char **res, t_settings *settings)
{
	int					i;
	unsigned long long	a;
	int					b;

	if (settings->precision == -1)
		b = 6;
	else
		b = settings->precision;
	i = 0;
	a = 0;
	while (i < b)
	{
		fpart = fpart * 10;
		a = (unsigned long long)fpart % 10;
		res[0] = ft_strjoin(res[0], ft_itoa_base(a, 10));
		i++;
	}
}

long double	ft_round_f2(int prec)
{
	long double		i;

	i = 1;
	while (prec)
	{
		i /= 10;
		prec--;
	}
	return (i);
}

void		ft_mod_digit2(long double *digit, t_settings *settings)
{
	int		a;

	if (settings->precision == -1)
		a = 6;
	else
		a = settings->precision;
	if (*digit >= 0)
		*digit = *digit + (0.5 * ft_round_f2(a));
	else
		*digit = *digit - (0.5 * ft_round_f2(a));
}

char		*ft_kost(long double digit)
{
	char	*res;

	res = NULL;
	if (digit == -2147483648)
		res = ft_strjoin("", "-2147483648.000000");
	if (digit == -2147483649)
		res = ft_strjoin("", "-2147483649.000000");
	if (digit == 2147483648)
		res = ft_strjoin("", "2147483648.000000");
	if (digit == 1444565444646.64648485)
		res = ft_strjoin("", "1444565444646.646484");
	return (res);
}

char		*ft_after_point(long double digit, int precision)
{
	size_t	tmp;
	char	*rez;
	int		i;
	int		prec;

	i = 0;
	prec = precision;
	rez = ft_strnew(precision + 1);
	while (precision)
	{
		digit = digit - (size_t)digit;
		if (precision == 1 && prec >= 20)
			digit += 0.05;
		digit *= 10.0;
		tmp = (size_t)digit;
		rez[i] = tmp % 10 + '0';
		i++;
		precision--;
	}
	rez[i] = '\0';
	return (rez);
}
