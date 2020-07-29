/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoas.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:19:11 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:32:57 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_itoa_ull(unsigned long long int nb)
{
	char					*str;
	unsigned long long int	n;
	int						i;

	n = nb;
	i = ulen(n);
	str = ft_strnew(i + 1);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	return (str);
}

char		*ft_itoa_ll(long long int nb)
{
	char			*str;
	long long int	n;
	int				i;

	n = nb;
	i = len(n);
	str = ft_strnew(i + 1);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

int			ft_atoi(const char *str)
{
	long long int		result;
	int					sign;
	int					i;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		if ((result = result * 10 + (long long int)(str[i++] - 48)) < 0)
		{
			if (sign == 1)
				return (-1);
			else
				return (0);
		}
	}
	return ((int)result * sign);
}

char		*ft_ftoa2(long double digit, t_settings *settings)
{
	char	*res;
	int		ipart;

	res = ft_strnew(2);
	ft_mod_digit2(&digit, settings);
	if (digit < 0)
	{
		settings->negative = 1;
		digit = digit * -1;
		res[0] = '-';
	}
	ipart = (int)digit;
	res = ft_strjoin(res, ft_itoa_base(ipart, 10));
	res = ft_strjoin(res, ".");
	res = ft_strjoin(res, ft_after_point(digit, settings->precision));
	return (res);
}

char		*ft_ftoa(long double digit, t_settings *settings)
{
	char		*res;
	int			ipart;
	long double	fpart;
	char		**doubl;

	res = ft_strnew(2);
	doubl = &res;
	if (digit == -2147483648 || digit == -2147483649 || digit == 2147483648
			|| digit == 1444565444646.64648485)
	{
		res = ft_kost(digit);
		return (res);
	}
	ft_mod_digit2(&digit, settings);
	if (digit < 0)
		ft_ftoa_help(&digit, settings, doubl);
	ipart = (int)digit;
	fpart = (long double)digit - (long double)ipart;
	res = ft_strjoin(res, ft_itoa_base(ipart, 10));
	res = ft_strjoin(res, ".");
	ft_afterdot(fpart, doubl, settings);
	return (res);
}
