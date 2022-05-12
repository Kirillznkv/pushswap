#include "../push_swap.h"

int	ft_atoi(char *str)
{
	unsigned int	res;
	unsigned int	i;
	char			m;

	m = 0;
	i = 0;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\v' ||
		str[i] == '\r' || str[i] == '\f' || str[i] == '\n')
		i++;
	if (str[i] == '+')
		i++;
	else if (str[i] == '-')
	{
		m++;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9' && res < __INT32_MAX__)
		res = res * 10 + str[i++] - '0';
	if (res > __INT32_MAX__)
		res = __INT32_MAX__;
	return (m ? -res : res);
}

size_t			ft_strlen(const char *str)
{
	size_t		res;

	res = 0;
	while (str && str[res])
		res++;
	return (res);
}

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t		len;
	size_t		i;
	size_t		j;

	i = ft_strlen(dst);
	j = 0;
	len = i + ft_strlen(src);
	if (size <= i)
		return (ft_strlen(src) + size);
	while (i < (size - 1) && src[j])
		dst[i++] = src[j++];
	dst[i] = '\0';
	return (len);
}

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	str = (char*)calloc(ft_strlen(s1) + ft_strlen(s2) + 1, 1);
	if (str)
	{
		ft_strlcat(str, s1, ft_strlen(s1) + 1);
		ft_strlcat(str, s2, ft_strlen(s1) + ft_strlen(s2) + 1);
	}
	return (str);
}

char		*ft_strdup(const char *s)
{
	char	*str;
	int		i;

	i = -1;
	str = (char*)calloc((ft_strlen((char*)s) + 1), sizeof(char));
	while (str && s[++i])
		str[i] = s[i];
	return (str);
}
