#include <stdio.h>
#include <stdlib.h>


# define INT_MAX 2147483647
/*
** we return anything except NULL in case of success
** a_r is address of res
*/

int			ft_cut_backspaces(const char *s)
{
	int i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' \
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r'))
		i++;
	return (i);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}



char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	size_t	n1;
	size_t	n2;

	n1 = ft_strlen(haystack);
	n2 = ft_strlen(needle);
	if (n2 == 0)
		return (char *)(haystack);
	j = 0;
	while (j < n1)
	{
		i = 0;
		while (haystack[i + j] && haystack[j + i] \
				== needle[i] && i < n2)
			i++;
		if (needle[i] == '\0')
			return (char *)(haystack + j);
		j++;
	}
	return (NULL);
}

int		*cycle_in_atoi_backsp(const char *str, int *a_r, int *n, int *a_i)
{
	while (str[*a_i] >= '0' && str[*a_i] <= '9')
	{
		if (*a_r > INT_MAX / 10 || (*a_r == INT_MAX / 10 && str[*a_i] > '7'))
		{
			*n = -1;
			return (NULL);
		}
		else
			*a_r = *a_r * 10 + (str[*a_i] - '0');
		(*a_i)++;
	}
	return (a_r);
}

/*
** we return anything except NULL in case of success
*/

int		*str_end_in_atoi_backsp(const char *str_i, int *n)
{
	if (str_i == '\0')
	{
		*n = 0;
		return (NULL);
	}
	return (n);
}

/*
** if int parsed then we put to p_numb what was parsed
** and return pointer to next char;
** if int was overflowed then return NULL;
*/

char	*ft_atoi_backsp(const char *str, int *p_numb, int *n)
{
	int	i;
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	i = ft_cut_backspaces(str);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (ft_strstr(str, "2147483648") && sign == -1)
	{
		*p_numb = -2147483648;
		return ((char *)str + i + 10);
	}
	if (!(cycle_in_atoi_backsp(str, &res, n, &i)))
		return (NULL);
	*p_numb = sign * res;
	if (!(str_end_in_atoi_backsp(str + i, n)))
		return (NULL);
	*n = 1;
	return ((char *)str + i);
}




int main(int ac, char **argv)
{
    int t, n;
    char *c;

    c = ft_atoi_backsp(argv[1], &t, &n);
    printf(" %d\n", t);
    return (0);
}