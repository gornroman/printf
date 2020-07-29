/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:59:37 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:59:39 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			len(long long int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

int			ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	else
		return (0);
}

size_t		ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int			ulen(unsigned long long int nb)
{
	int	len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

void		ft_initialiazatoin(t_settings *settings)
{
	settings->flag = 0;
	settings->flagplus = 0;
	settings->flagminus = 0;
	settings->flagspace = 0;
	settings->flagzero = 0;
	settings->flaghash = 0;
	settings->type = '0';
	settings->width = -1;
	settings->precision = -1;
	settings->size = 0;
	settings->len = 0;
	settings->negative = 0;
	settings->zerocount = 0;
	settings->cnull = 0;
	settings->firstlen = 0;
	settings->x_is_zero = 0;
	settings->str_move = 0;
}
