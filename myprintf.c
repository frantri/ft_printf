/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/06 12:26:08 by ftriquet          #+#    #+#             */
/*   Updated: 2016/01/10 18:59:24 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myprintf.h"
#include "libft.h"

int	myprintf(char *form, int fd, ...)
{
	va_list		ap;
	int			i;

	i = 0;
	va_start(ap, fd);
	while (form[i])
	{
		if (form[i] == '%' && form[i + 1])
		{
			if (form[i + 1] && form[i + 1] == 's')
				ft_putstr_fd(va_arg(ap, char *), fd);
			else if (form[i + 1] && form[i + 1] == 'd')
				ft_putnbr_fd(va_arg(ap, long), fd);
			else if (form[i + 1] == '%')
				ft_putchar_fd(form[i], fd);
			i++;
		}
		else
			ft_putchar_fd(form[i], fd);
		i++;
	}
	return (1);
}
