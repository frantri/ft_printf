#include <ft_printf.h>
#include <unistd.h>
#include <stdio.h>

void	print_arg(t_arg *arg)
{
	if (arg->f_zero)
		printf("zero\n");
	if (arg->f_minus)
		printf("minus\n");
	if (arg->f_plus)
		printf("plus: \n");
	if (arg->f_space)
		printf("space: \n");
	if (arg->f_hashtag)
		printf("hashtag \n");
	if (arg->f_prec)
		printf("preci: %d\n", arg->v_prec);
	if (arg->f_field)
		printf("larg: %d\n", arg->v_len);
	if (arg->format)
		printf("format: %s\n", arg->format);
	if (arg->mod)
		printf("mod: %s\n", arg->mod);
	printf("conv: %c\n", arg->conv);
}

void	flush_buffer(void)
{
	if (curs)
	{
		write(1, buffer, curs);
		curs = 0;
	}
}

void	handle_conv(va_list ap, char *format, int *i)
{
	t_arg arg;

	init_arg(&arg);
	*i += fill_arg(&arg, format + *i);
	if (arg.conv == 'd' || arg.conv == 'D' || arg.conv == 'i')
		handle_d(&arg, ap);
	else if (arg.conv == 's' || arg.conv == 'S')
		handle_s(&arg, ap);
	else if (arg.conv == '%')
		print_s(&arg, "%");
	else if (arg.conv == 'x' || arg.conv == 'X' ||
			arg.conv == 'o' || arg.conv == 'u' || arg.conv == 'U')
		handle_uxo(&arg, ap);
	else if (arg.conv == 'c')
		handle_c(&arg, ap);
}

int		ft_printf(char *format, ...)
{
	setlocale(LC_ALL, "en_US.UTF-8");
	int i = 0;
	ret = 0;
	va_list	ap;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
			handle_conv(ap, format, &i);
		else
		{
			add_char_to_buffer(format[i]);
			i++;
		}
	}
	va_end(ap);
	flush_buffer();
	return (ret);
}
