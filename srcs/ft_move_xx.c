/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_xx.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jgroleo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:36:00 by jgroleo           #+#    #+#             */
/*   Updated: 2020/01/14 17:37:15 by jgroleo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_add_space(char **finalstr, t_settings *settings)
{
	ft_putchar(' ');
	if (ft_check_space(finalstr[0]) != 0)
		finalstr[0][ft_strlen(finalstr[0]) - 1] = '\0';
	settings->result = settings->result + 1;
}

void		ft_place_zero(char **finalstr, t_settings *settings)
{
	int		i;

	i = 0;
	if (settings->flagspace == 1)
		i++;
	while (finalstr[0][i] != '\0')
	{
		if (finalstr[0][i] == ' ')
		{
			settings->zerocount = settings->zerocount + 1;
			finalstr[0][i] = '0';
		}
		i++;
	}
	i = 1;
	if (settings->negative == 1)
	{
		finalstr[0][0] = '-';
		while (finalstr[0][i] != '\0')
		{
			if (finalstr[0][i] == '-')
				finalstr[0][i] = '0';
			i++;
		}
	}
}

void		ft_move_has_xx2(char *str)
{
	str[2] = str[1];
	str[1] = str[0];
	str[0] = ' ';
}

void		ft_move_has_xx(char *str, t_settings *settings)
{
	int		i;

	i = ft_check_space(str);
	if (i && str[2] == ' ' && str[3] == ' ')
	{
		if (i > 1)
		{
			str[i + 1] = str[1];
			str[i] = str[0];
			str[0] = ' ';
			str[1] = ' ';
		}
		else
			ft_move_has_xx2(str);
	}
	if (i == 1 && (str[0] == ' ' || str[2] == ' '))
	{
		str[0] = ' ';
		str[1] = '0';
		if (settings->type == 'x')
			str[2] = 'x';
		else
			str[2] = 'X';
	}
}

void		ft_flag_hash_xx_b(char *finalstr, char *str, t_settings *settings)
{
	int		i;
	int		flag;
	int		j;

	j = 0;
	flag = 0;
	i = 2;
	while (finalstr[j] != '\0')
	{
		if (flag < 2 && finalstr[j] == ' ')
		{
			flag++;
			j++;
		}
		else
		{
			str[i] = finalstr[j];
			i++;
			j++;
		}
	}
	str[i] = '\0';
	ft_move_has_xx(str, settings);
}
