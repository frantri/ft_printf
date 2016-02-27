/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 10:41:13 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/27 11:24:00 by ftriquet         ###   ########.fr       */
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

void		*ft_list_get_at(
		t_list *list,
		size_t pos)
{
	static size_t		previous_pos = 0;
	static t_list_cell	*cursor = NULL;

	if (pos >= list->size)
		return (NULL);
	if (cursor == NULL)
	{
		previous_pos = 0;
		cursor = list->first;
	}
	while (pos != previous_pos)
	{
		cursor = pos > previous_pos ? cursor->prev : cursor->next;
		previous_pos += pos > previous_pos ? 1 : -1;
	}
	return (cursor->data);
}
