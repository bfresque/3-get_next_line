/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bfresque <bfresque@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 11:45:45 by bfresque          #+#    #+#             */
/*   Updated: 2022/12/14 12:47:03 by bfresque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_free(char *str, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(str, buffer);
	free(str);
	return (temp);
}

char	*ft_line(char *str)
{
	char	*dest;
	int		i;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	dest = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		dest[i] = str[i];
		i++;
	}
	if (str[i] && str[i] == '\n')
		dest[i++] = '\n';
	return (dest);
}

char	*ft_buf(char *str)
{
	int		i;
	int		j;
	char	*dest;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	dest = ft_calloc((ft_strlen(str) - i + 1), sizeof(char));
	j = 0;
	while (str[i])
		dest[j++] = str[++i];
	free(str);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*str[4096];
	char		*buffer;
	char		*line;
	int			i;

	i = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (str[fd] == 0)
		str[fd] = ft_calloc(1, 1);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	while (i > 0 && !(ft_strchr(buffer, '\n')))
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[i] = '\0';
		str[fd] = ft_free(str[fd], buffer);
	}
	free(buffer);
	return (line = ft_line(str[fd]), str[fd] = ft_buf(str[fd]), line);
}

// int main()
// {
// 	int		i;
// 	int		fd1;
// 	int		fd2;
// 	char	*str1;
// 	char	*str2;
// 	fd1 = open("test.txt", O_RDONLY);
// 	fd2 = open("Celine.txt", O_RDONLY);
// 	i = 0;
// 	 while(i < 50)
// 	{
// 		str1 =get_next_line(fd1);
// 		printf("%s", str1);
// 		str2 = (get_next_line(fd2));
// 		printf("%s", str2);
// 		free(str1);
// 		free(str2);
// 		i++;
// 	}
// }
