/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 10:10:42 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/27 10:24:52 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_list.h>
#include <stdlib.h>

int			ft_list_remove_back(t_list *list)
{
	t_list_cell	*tmp;

	if (list->size == 0)
		return (-1);
	tmp = list->last;
	list->last = list->last->prev;
	list->del_func(tmp->data, tmp->data_size);
	free(tmp);
	if (list->last == NULL)
		list->first = NULL;
	--list->size;
	return ((int)list->size);
}

int			ft_list_remove_front(t_list *list)
{
	t_list_cell	*tmp;

	if (list->size == 0)
		return (-1);
	tmp = list->first;
	list->first = list->first->next;
	list->del_func(tmp->data, tmp->data_size);
	free(tmp);
	if (list->first == NULL)
		list->last = NULL;
	--list->size;
	return ((int)list->size);
}

int			ft_list_remove(
		t_list *list,
		void *data,
		size_t data_size,
		int (*cmp)(void *, size_t, void *, size_t))
{
	t_list_cell	*it;
	t_list_cell	*tmp;

	it = list->first;
	if ((*cmp)(data, data_size, it->data, it->data_size) == 0)
		return (ft_list_remove_front(list));
	if ((*cmp)(data, data_size, list->last->data, list->last->data_size) == 0)
		return (ft_list_remove_back(list));
	while ((tmp = it->next))
	{
		if ((*cmp)(data, data_size, it->data, it->data_size) == 0)
		{
			tmp->next->prev = it;
			it->next = tmp->next;
			--list->size;
			list->del_func(tmp->data, tmp->data_size);
			free(tmp);
			break ;
		}
		it = it->next;
	}
	return ((int)list->size);
}
