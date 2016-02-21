#include "ft_printf.h"
#include <unistd.h>

int		get_nb_octs(unsigned int c)
{
	int		i;

	i = 0;
	while (c)
	{
		i++;
		c = c >> 1;
	}
	if (i <= 7)
		return (1);
	if (i <= 11)
		return (2);
	if (i <= 16)
		return (3);
	return (4);
}

void			put_wchar(t_arg *arg, unsigned int c)
{
	int		l;

	if (c == 0)
		return ;
	flush_buffer();
	l = get_nb_octs(c);
	if (l == 1)
		print_wchar1(arg, c);
	else if (l == 2)
		print_wchar2(arg, c);
	else if (l == 3)
		print_wchar3(arg, c);
	else
		print_wchar4(arg, c);
	make_padding(arg, 0);
}

void			print_wchar1(t_arg *arg, unsigned int c)
{
	char ch;

	if (arg)
		arg->nb_char++;
	ch = (char)c;
	write(1, &ch, 1);
}

void			print_wchar2(t_arg *arg, unsigned int c)
{
	unsigned int	mask;
	int				w;

	if (arg)
		arg->nb_char += 2;
	mask = 49280;
	mask |= (((unsigned char)c << 2) >> 2);
	mask |= (((unsigned char)c >> 6) << 8);
	mask |= ((((unsigned char)(c >> 8) << 2) >> 2) << 10);
	mask |= ((unsigned char)(c >> 14) << 12);
	w = ((unsigned char *)&mask)[1];
	write(1, &w, 1);
	w = ((unsigned char *)&mask)[0];
	write(1, &w, 1);
}

void			print_wchar3(t_arg *arg, unsigned int c)
{
	unsigned int	mask;
	int				w;
	unsigned int	oct;

	if (arg)
		arg->nb_char += 3;
	mask = 0b111000001000000010000000;
	oct = (unsigned char)((c << 26) >> 26);
	mask |= oct;
	oct = (((unsigned char)((c << 24) >> 30)) << 8);
	mask |= oct;
	oct = ((unsigned int)(((c << 20) >> 26))) << 8;
	mask |= oct;
	oct =(unsigned int)(((c >> 12) << 16));
	mask |= oct;
	w = ((unsigned char *)&mask)[2];
	write(1, &w, 1);
	w = ((unsigned char *)&mask)[1];
	write(1, &w, 1);
	w = ((unsigned char *)&mask)[0];
	write(1, &w, 1);
}

void	print_wchar4(t_arg *arg, unsigned int c)
{
	unsigned int	mask;
	int				w;
	unsigned int	oct;

	if (arg)
		arg->nb_char += 4;
	mask = 0b11110000100000001000000010000000;
	oct = (c << 26) >> 26;
	mask |= oct;
	oct = ((c << 20) >> 26) << 8;
	mask |= oct;
	oct = ((c << 14) >> 26) << 16;
	mask |= oct;
	oct = ((c << 10) >> 26) << 20;
	mask |= oct;
	w = ((unsigned char *)&mask)[3];
	write(1, &w, 1);
	w = ((unsigned char *)&mask)[2];
	write(1, &w, 1);
	w = ((unsigned char *)&mask)[1];
	write(1, &w, 1);
	w = ((unsigned char *)&mask)[0];
	write(1, &w, 1);
}
