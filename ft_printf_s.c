#include "ft_printf.h"

static void		print_wchart(t_arg *arg, wchar_t *ch)
{
	int		i;

	i = 0;
	if (ch == NULL)
	{
		arg->conv = 's';
		print_s(arg, NULL);
	}
	while (ch[i])
	{
		put_wchar(arg, (unsigned int)(ch[i]));
		i++;
	}
}

void		handle_s(t_arg *arg, va_list ap)
{
	if (arg->mod == NULL &&  arg->conv == 's')
		print_s(arg, (char *)va_arg(ap, char *));
	else if ((ft_strcmp("l", arg->mod) && arg->conv == 's') ||
			arg->conv == 'S')
		print_wchart(arg, (wchar_t *)va_arg(ap, wchar_t *));
}

static int	putnstr(char *s, int n)
{
	int		i;

	i = 0;
	while (s[i] && i < n)
	{
		add_char_to_buffer(s[i]);
		++i;
	}
	return (i);
}

void		print_s(t_arg *arg, char *s)
{
	int		size;
	int		len;
	int		print;

	if (s == NULL)
		s = "(null)";
	len = ft_strlen(s);
	if (arg->v_prec && arg->v_prec > len)
		size = arg->v_prec;
	else
		size = ft_strlen(s);
	print = (size > len ? size : len);
	while (!arg->f_minus && arg->v_len >= ++print)
		arg->nb_char += add_char_to_buffer(' ');
	if (arg->v_prec)
		arg->nb_char += putnstr(s, arg->v_prec);
	else
		arg->nb_char += putnstr(s, size);
	make_padding(arg, arg->nb_char);
}
