#include "ft_printf.h"

void	handle_c(t_arg *arg, va_list ap)
{
	int		i;

	i = arg->v_len;
	while (i-- > 1 && !arg->f_minus)
		add_char_to_buffer(' ');
	if (arg->mod == NULL && arg->conv == 'c')
		arg->nb_char += add_char_to_buffer((char)va_arg(ap, int));
	else if (strcmp(arg->mod, "l") == 0 || arg->conv == 'C')
		put_wchar(arg, (unsigned int)va_arg(ap, wchar_t *));
	make_padding(arg, 1);
}

void        make_padding(t_arg *arg, int length)
{
	int size;

	(void)length;
	size = 0;
	if (arg->f_minus)
		size = arg->v_len;
	while (size > arg->nb_char)
	{
		add_char_to_buffer(' ');
		size--;
	}
}
