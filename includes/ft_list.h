/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lists.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftriquet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/27 04:16:47 by ftriquet          #+#    #+#             */
/*   Updated: 2016/02/27 06:56:03 by ftriquet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LISTS_H
# define FT_LISTS_H
# include <string.h>

typedef struct			s_list_cell
{
	void				*data;
	size_t				data_size;
	struct s_list_cell	*next;
	struct s_list_cell	*prev;
}						t_list_cell;

typedef struct			s_list
{
	size_t				size;
	t_list_cell			*first;
	t_list_cell			*last;
	void				(*del_func)(void *, size_t);
}						t_list;

t_list_cell		*ft_new_list_cell(
		void *data,
		size_t data_size,
		t_list_cell *next,
		t_list_cell *prev);

void			ft_list_init(
		t_list *list,
		void (*del_func)(void *, size_t));

int				ft_list_add_back(
		t_list *list,
		void *data,
		size_t data_size);

int				ft_list_add_front(
		t_list *list,
		void *data,
		size_t data_size);

int				ft_list_add_pos(
		t_list *list,
		void *data,
		size_t data_size,
		size_t pos);

int				ft_list_add_sort(
		t_list *list,
		void *data,
		size_t data_size,
		int (*cmp)(void *,size_t,  void *, size_t));

void			ft_list_iter(
		t_list *list,
		void (*func)(void *data, size_t data_size));

t_list			ft_list_map(
		t_list *list,
		t_list_cell *(*func)(t_list_cell *),
		void (*del_func)(void *, size_t));

#endif
