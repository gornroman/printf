/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:15:13 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:54:06 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_cut_str3_h(char *str, char *string, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		str[i] = string[i];
		i++;
	}
	str[i] = '\0';
}

void	ft_ftoa_help(long double *digit, t_settings *settings, char **str)
{
	settings->negative = 1;
	*digit = *digit * -1;
	str[0][0] = '-';
}
