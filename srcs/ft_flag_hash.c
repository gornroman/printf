/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 16:59:53 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:01:33 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_flag_hash_xx_zero(char *finalstr, char *str,
		t_settings *settings)
{
	int		i;
	int		j;

	j = 0;
	if (settings->zerocount == 1)
		j = 1;
	else if (settings->zerocount > 2)
		j = 2;
	i = 2;
	while (finalstr[j] != '\0')
	{
		str[i] = finalstr[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

char		*ft_flag_hash_xx(char *finalstr, t_settings *settings)
{
	char	*str;

	str = ft_strnew(ft_strlen(finalstr) + 2);
	str[0] = '0';
	if (settings->type == 'x')
		str[1] = 'x';
	else
		str[1] = 'X';
	if (settings->flagzero == 0)
		ft_flag_hash_xx_b(finalstr, str, settings);
	else
		ft_flag_hash_xx_zero(finalstr, str, settings);
	free(finalstr);
	return (str);
}

void		ft_flag_hash(char **finalstr, t_settings *settings)
{
	int		i;

	i = 0;
	if (settings->type == 'o' && (ft_strcmp(finalstr[0], "0\0") != 0))
	{
		if (finalstr[0][0] == ' ' && ft_check_space(finalstr[0]) > 0)
		{
			while (finalstr[0][i] == ' ')
				i++;
			if (finalstr[0][i] != '0')
				finalstr[0][i - 1] = '0';
		}
		else if (((settings->len <= settings->firstlen) ||
					ft_check_space(finalstr[0]) > 0)
				&& finalstr[0][0] != '0')
		{
			ft_putchar('0');
			if (ft_check_space(finalstr[0]) != 0)
				finalstr[0][ft_strlen(finalstr[0]) - 1] = '\0';
			settings->result = settings->result + 1;
		}
	}
	else if ((settings->type == 'x' || settings->type == 'X') &&
			(ft_strcmp(finalstr[0], "0\0") != 0))
		finalstr[0] = ft_flag_hash_xx(finalstr[0], settings);
}

void		ft_place_minus(char *str, int *i, int *j)
{
	(*i)--;
	str[0] = '-';
	(*j)++;
}

void		ft_place_zero2(char *str, int *i, int *j)
{
	str[(*j)++] = '0';
	(*i)++;
}
