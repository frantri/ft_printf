#include <ft_printf.h>
#include <stdlib.h>

char	digit(int nb, int maj)
{
	if (nb < 10)
		return ('0' + nb);
	if (maj)
		return ('A' + nb % 10);
	return ('a' + nb % 10);
}

char	*ft_itoa_u(uintmax_t n, int base, int maj)
{
	char	*res;
	int		size;
	char	*tmp;

	size = nbr_len(n, base);
	if (!(res = malloc(sizeof(*res) * (size + 1))))
		return (NULL);
	res[size] = 0;
	while (size--)
	{
		res[size] = digit(n % base, maj);
		n /= base;
	}
	while (res[0] && res[0] == '0' && res[1])
	{
		tmp = ft_strdup(res + 1);
		free(res);
		res = tmp;
	}
	return (res);
}

char	*ft_itoa(intmax_t n, int base, int maj)
{
	char	*res;
	char	*tmp;

	if (n < 0)
	{
		tmp = ft_itoa_u(-n, base, maj);
		res = ft_strjoin("-", tmp);
		free(tmp);
	}
	else
		res = ft_itoa_u(n, base, maj);
	return (res);
}
