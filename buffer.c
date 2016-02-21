#include <ft_printf.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

char	buffer[4096];
size_t	curs = 0;
int		ret = 0;

int		add_string_to_buffer(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (curs == 4096)
		{
			write(1, buffer, 4096);
			curs = 0;
		}
		buffer[curs] = str[i];
		++i;
		++curs;
		if (curs && buffer[curs - 1] == '\n')
		{
			write(1, buffer, curs);
			curs = 0;
		}
	}
	ret += i;
	return (i);
}

int		add_char_to_buffer(char c)
{
	if (curs == 4096)
	{
		write(1, buffer, 4096);
		curs = 0;
	}
	buffer[curs] = c;
	++curs;
	if (curs && buffer[curs - 1] == '\n')
	{
		write(1, buffer, curs);
		curs = 0;
	}
	++ret;
	return (1);
}

int		add_int_to_buffer(intmax_t n, int base, int maj)
{
	char	*tmp;
	int		res;

	tmp = ft_itoa(n, base, maj);
	res = ft_strlen(tmp);
	add_string_to_buffer(tmp);
	free(tmp);
	return (res);
}

int		add_uint_to_buffer(uintmax_t n, int base, int maj)
{
	char	*tmp;
	int		res;

	tmp = ft_itoa_u(n, base, maj);
	add_string_to_buffer(tmp);
	res = ft_strlen(tmp);
	free(tmp);
	return (res);
}
