#include "push_swap.h"

static int	my_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v'
		|| c == '\f' || c == '\r' || c == ' ')
		return (1);
	else
		return (0);
}

int	int_error(void)
{
	write(2, "Error\n", 6);
	exit(1);
}

int	ft_atoi(const char *str, int *flag)
{
	int			i;
	int			sign;
	long int	num;

	i = 0;
	while (str[i] && my_isspace(str[i]))
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	num = 0;
	if (!(str[i] >= '0' && str[i] <= '9'))
		*flag = 1;
	while (str[i] && (str[i] >= '0' && str[i] <= '9'))
		num = num * 10 + str[i++] - '0';
	if (str[i] != '\0')
		int_error();
	if (num * sign > 2147483647 || num * sign < -2147483648)
		int_error();
	return (num * sign);
}

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = malloc(ft_strlen((char *)src) + 1);
	if (dest == NULL)
		return (NULL);
	ft_strcpy(dest, (char *)src);
	return (dest);
}
