/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_s_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/23 08:34:34 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/23 08:34:47 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_nb_octs(unsigned int c)
{
	int		i;

	i = 0;
	while (c)
	{
		i++;
		c = c >> 1;
	}
	if (i <= 7)
		return (1);
	if (i <= 11)
		return (2);
	if (i <= 16)
		return (3);
	return (4);
}

int		putnstr(t_arg *arg, char *s, int n)
{
	int		i;

	i = 0;
	while (s[i] && i < n)
	{
		add_char_to_buffer(arg, s[i]);
		++i;
	}
	return (i);
}

int		putnwchar(t_arg *arg, wchar_t *ch, int n)
{
	int		i;

	i = 0;
	while (ch[i] && i < n)
	{
		put_wchar(arg, (unsigned int)ch[i]);
		++i;
	}
	return (i);
}
