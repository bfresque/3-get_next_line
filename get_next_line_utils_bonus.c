/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:46:13 by bfresque          #+#    #+#             */
/*   Updated: 2022/12/14 10:35:14 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c )
{
	char	*str;

	str = (char *)s;
	while (*str != c && *str != 0)
		str++;
	if (*str == c)
		return (str);
	else
		return (NULL);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*tab;
	size_t	i;
	size_t	total;

	if (nmemb >= SIZE_MAX || size >= SIZE_MAX)
		return (NULL);
	total = nmemb * size;
	tab = malloc(total);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < total)
	{
		tab[i] = '\0';
		i++;
	}
	return (tab);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest || !s1 || !s2)
	{
		free(s1);
		free(dest);
		return (NULL);
	}
	i = 0;
	j = 0;
	while (s1[i] != 0)
		dest[j++] = s1[i++];
	j = 0;
	while (s2[j] != 0)
		dest[i++] = s2[j++];
	dest[ft_strlen(s1) + ft_strlen(s2)] = '\0';
	return (dest);
}
