#include <ft_printf.h>

static void	print_field(t_arg *arg, long long int n)
{
	int		size;
	int		len;
	int		print;

	size = 0;
	len = nbr_len(n, 10);
	if (arg->f_zero && arg->f_minus == 0 && arg->f_prec && arg->v_zero == 0)
		arg->v_field = arg->v_zero;
	if (arg->f_zero && arg->f_minus == 0 && arg->f_prec == 0)
		size = arg->v_zero;
	else if (arg->f_prec && arg->v_prec)
		size = arg->v_prec;
	print = (size > len) ? size : len;
	if (arg->f_plus && n >= 0)
		print++;
	if (arg->f_space && n >= 0)
		print++;
	if (n < 0 && arg->v_prec + 1 > len)
		print++;
	if (n == 0 && arg->f_prec && arg->v_prec == 0)
		print--;
	while (arg->v_field >= ++print)
		arg->nb_char += add_char_to_buffer(' ');
}

static void	print_flags(t_arg *arg, long long int n)
{
	int size;
	int	len;

	size = 0;
	len = nbr_len(n, 10);
	if (n < 0)
	{
		if (arg->v_prec)
			arg->v_prec++;
		arg->nb_char += add_char_to_buffer('-');
	}
	else if (arg->f_plus)
		arg->nb_char += add_char_to_buffer('+');
	if (arg->f_zero && arg->f_minus == 0 && arg->f_prec == 0)
		size = (arg->f_space) ? arg->v_zero - 1 : arg->v_zero;
	else if (arg->f_prec && arg->v_prec)
		size = arg->v_prec;
	if (arg->f_plus && n > 0 && !arg->f_prec)
		size--;
	while (size > len)
	{
		arg->nb_char += add_char_to_buffer('0');
		size--;
	}
}

static void	print_d(t_arg *arg, long long int n)
{
	int	len;

	len = 0;
	if (!arg->f_plus && arg->f_space && n >= 0)
		arg->nb_char += add_char_to_buffer(' ');
	len += nbr_len(n, 10) + arg->nb_char;
	print_field(arg, n);
	print_flags(arg, n);
	if (n < 0)
		arg->nb_char += add_uint_to_buffer(-n, 10, 0);
	else if (!(arg->f_prec && arg->v_prec == 0 && n == 0))
		arg->nb_char += add_uint_to_buffer(n, 10, 0);
	make_padding(arg, len);
}

void	handle_d(t_arg *arg, va_list ap)
{
	if (arg->mod == NULL && arg->conv != 'D')
		print_d(arg, (int)va_arg(ap, int));
	else if (arg->conv == 'D' || ft_strcmp(arg->mod, "l") == 0)
		print_d(arg, va_arg(ap, long int));
	else if (ft_strcmp(arg->mod, "ll") == 0)
		print_d(arg, va_arg(ap, long long int));
	else if (ft_strcmp(arg->mod, "h") == 0)
		print_d(arg, (short)va_arg(ap, int));
	else if (ft_strcmp(arg->mod, "hh") == 0)
		print_d(arg, (char)va_arg(ap, int));
	else if (ft_strcmp(arg->mod, "j") == 0)
		print_d(arg, va_arg(ap, long));
	else if (ft_strcmp(arg->mod, "z") == 0)
		print_d(arg, va_arg(ap, size_t));
}
