#include <ft_printf.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*substring;
	size_t	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	substring = malloc(sizeof(char) * (len + 1));
	if (substring)
	{
		while (i < len)
		{
			substring[i] = s[start + i];
			++i;
		}
		substring[i] = 0;
	}
	return (substring);
}
