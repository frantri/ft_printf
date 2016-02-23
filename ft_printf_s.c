#include "ft_printf.h"

int			handle_s(t_arg *arg, va_list ap)
{
	if ((arg->v_len || arg->f_zero) && ((arg->mod && ft_strcmp(arg->mod, "l")
					== 0) || arg->conv == 'S'))
		return (-1);
	print_s(arg, va_arg(ap, void *));
	return (1);
}

static int	wcharlen(wchar_t *s)
{
	int		i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

static void	print_s_noprec(t_arg *arg)
{
	int		i;

	i = 0;
	while (i < arg->v_len)
	{
		if (!arg->f_zero)
			arg->nb_char += add_char_to_buffer(arg, ' ');
		else
			arg->nb_char += add_char_to_buffer(arg, '0');
		i++;
	}
}

void		print_s(t_arg *arg, void *s)
{
	int		size;
	int		len;
	int		print;

	if (arg->f_prec && arg->v_prec == 0)
		return (print_s_noprec(arg));
	if (s == NULL && arg->conv == 's' && arg->mod == NULL)
		s = "(null)";
	len = arg->conv == 's' && arg->mod == NULL ? ft_strlen(s) : wcharlen(s);
	if (arg->v_prec && arg->v_prec < len)
		size = arg->v_prec;
	else
		size = ft_strlen(s);
	print = size;
	while (!arg->f_minus && arg->v_len >= ++print)
	{
		arg->nb_char += arg->f_zero ? add_char_to_buffer(arg, '0') :
			add_char_to_buffer(arg, ' ');
	}
	if (arg->mod == NULL && arg->conv == 's')
		arg->nb_char += putnstr(arg, s, size);
	else
		putnwchar(arg, (wchar_t *)s, size);
	make_padding(arg, arg->nb_char);
}
