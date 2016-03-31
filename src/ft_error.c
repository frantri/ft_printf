/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:04:22 by ftriquet          #+#    #+#             */
/*   Updated: 2016/03/31 15:11:20 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_error.h>
#include <string.h>
#include <errno.h>
#include <ft_printf.h>
#include <unistd.h>

char		*ft_strerror(void)
{
	size_t	i;

	i = 0;
	while (i < 132)
	{
		if (g_errtab[i].code == errno)
			return (g_errtab[i].msg);
		++i;
	}
	return (NULL);
}

void		ft_perror(char *msg)
{
	char	*err_msg;

	if (!(err_msg = ft_strerror()))
		return ;
	ft_dprintf(STDERR_FILENO, "%s: %s\n", msg, err_msg);
}
