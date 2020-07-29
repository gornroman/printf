/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:52:22 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:55:50 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_p_zerostr(void)
{
	char	*res;

	res = ft_strnew(4);
	res[0] = '0';
	res[1] = '\0';
	return (res);
}

char		*ft_add_0x(char *doublestr, t_settings *settings)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_strnew(ft_strlen(doublestr + 2));
	res[0] = '0';
	res[1] = 'x';
	if (ft_strcmp(doublestr, "0\0") == 0 && settings->precision == 0)
		doublestr[0] = '\0';
	while (doublestr[i] != '\0')
	{
		res[i + 2] = doublestr[i];
		i++;
	}
	res[i + 2] = '\0';
	free(doublestr);
	return (res);
}

char		*ft_ou_to_str(va_list ap, t_settings *settings)
{
	unsigned long long int	res;
	char					*str;

	if (settings->type == 'p')
		res = ft_find_p_size(settings, ap);
	else
		res = ft_find_ou_size(settings, ap);
	if (settings->type == 'o')
		str = ft_itoa_base(res, 8);
	else if (settings->type == 'x' || settings->type == 'p')
		str = ft_itoa_base(res, 16);
	else if (settings->type == 'X')
	{
		str = ft_itoa_base(res, 16);
		ft_x_to_x(str);
	}
	else
		str = ft_itoa_base(res, 10);
	if (settings->type == 'p' && str[0] == '0')
		str = ft_p_zerostr();
	if (res == 0)
		settings->x_is_zero = 1;
	if (settings->type == 'p')
		str = ft_add_0x(str, settings);
	return (str);
}

long double	ft_find_f_size(t_settings *settings, va_list ap)
{
	long double res;

	if (settings->size == 'L')
		res = va_arg(ap, long double);
	else
		res = va_arg(ap, double);
	return (res);
}

char		*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	j = 0;
	i = 0;
	str = ft_strnew((int)ft_strlen(s2) + (int)ft_strlen(s1) + 1);
	if (!str)
		return (NULL);
	while (s1[j])
		str[j++] = s1[i++];
	i = 0;
	while (s2[i])
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}
