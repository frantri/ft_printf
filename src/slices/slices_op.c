#include <ft_slices.h>

void	*ft_slice_reduce(t_slice *s, void *(*f)(void *, void *), void *init)
{
	void	*res;
	size_t	i;

	if (init)
	{
		i = 0;
		res = init;
	}
	else
	{
		i = 2;
		res = (*f)(ft_slice_get(s, 0), ft_slice_get(s, 1));
	}
	while (i < s->size)
	{
		res = (*f)(res, ft_slice_get(s, i));
		++i;
	}
	return (res);
}
