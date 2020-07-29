/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lib_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:59:29 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:59:31 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*a;
	unsigned char	*b;
	int				i;

	i = 0;
	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	while (a[i] == b[i] && a[i] != '\0' && b[i] != '\0')
		i++;
	return (a[i] - b[i]);
}

int			len_base(unsigned long long int nbr, int base)
{
	int		len;

	len = 1;
	while (nbr /= (unsigned long long int)base)
		len++;
	return (len);
}

char		*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

char		*ft_strnew(size_t size)
{
	char	*str;

	if (size + 1 == 0)
		return (NULL);
	str = (char*)malloc(size * sizeof(char) + 1);
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size--)
		str[size] = '\0';
	return (str);
}

char		*ft_itoa_base(unsigned long long int nbr, int base)
{
	char	*str;
	char	arr_num[17];
	int		nbr_base;
	int		len;
	size_t	i;

	ft_strcpy(arr_num, "0123456789abcdef\0");
	len = len_base(nbr, base);
	str = ft_strnew(len + 1);
	i = len - 1;
	str[0] = '0';
	while (nbr)
	{
		nbr_base = (int)(nbr % (unsigned long long int)base);
		str[i] = arr_num[nbr_base];
		nbr /= base;
		i--;
	}
	return (str);
}
