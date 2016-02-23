#include <ft_printf.h>
#include <stdlib.h>
#include <unistd.h>

void	flush_buffer(t_arg *arg)
{
	if (arg->curs)
	{
		write(1, arg->buffer, arg->curs);
		arg->curs = 0;
	}
}

static void	handle_other(t_arg *arg)
{
	char	*res;

	res = ft_strnew(2);
	res[0] = arg->conv;
	print_s(arg, res);
	free(res);
}

int		handle_conv(t_arg *arg, va_list ap, char *format, int *i)
{
	init_arg(arg);
	*i += fill_arg(arg, format + *i);
	if (arg->conv == 'd' || arg->conv == 'D' || arg->conv == 'i')
		handle_d(arg, ap);
	else if (arg->conv == 's' || arg->conv == 'S')
	{
		if (handle_s(arg, ap) == -1)
			return (-1);
	}
	else if (arg->conv == 'x' || arg->conv == 'X' || arg->conv == 'p' ||
			arg->conv == 'o' || arg->conv == 'u' || arg->conv == 'U' ||
			arg->conv == 'O')
		handle_uxo(arg, ap);
	else if (arg->conv == 'c' || arg->conv == 'C')
		handle_c(arg, ap);
	else
		handle_other(arg);
	free(arg->format);
	return (1);
}

int		ft_printf(char *format, ...)
{
	int i = 0;
	t_arg	arg;
	va_list	ap;
	arg.ret = 0;
	arg.curs = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] && format[i + 1] == '%' && (i += 2))
				add_char_to_buffer(&arg, '%');
			else if (handle_conv(&arg, ap, format, &i) == -1)
				return (-1);
		}
		else
		{
			add_char_to_buffer(&arg, format[i]);
			i++;
		}
	}
	va_end(ap);
	flush_buffer(&arg);
	return (arg.ret);
}
