/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 10:41:13 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/27 10:52:31 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			*ft_list_get_back(t_list *list)
{
	if (list->size == 0)
		return (NULL);
	return (list->last->data);
}

void			*ft_list_get_front(t_list *list)
{
	if (list->size == 0)
		return (NULL);
	return (list->first->data);
}

void			*ft_list_get(
		t_list *list,
		void *data,
		size_t data_size,
		int (*cmp)(void *, size_t, void *, size_t))
{
	t_list_cell	*it;

	it = list->first;
	if ((*cmp)(data, data_size, it->data, it->data_size) == 0)
		return (ft_list_get_front(list));
	if ((*cmp)(data, data_size, list->last->data, list->last->data_size) == 0)
		return (ft_list_get_back(list));
	while (it->next)
	{
		if ((*cmp)(data, data_size, it->data, it->data_size) == 0)
			return (it->data);
		it = it->next;
	}
	return (NULL);
}
