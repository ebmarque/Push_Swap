/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebmarque < ebmarque@student.42porto.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 14:28:11 by ebmarque          #+#    #+#             */
/*   Updated: 2023/06/14 21:15:35 by ebmarque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_read_to_aux(int fd, char *str)
{
	char	*buff;
	int		bytes;

	buff = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buff)
		return (NULL);
	bytes = 1;
	while (!ft_strchr(str, '\n') && bytes != 0)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(buff);
			free(str);
			return (NULL);
		}
		buff[bytes] = '\0';
		if (!buff)
			return (NULL);
		str = ft_strjoin(str, buff);
	}
	free(buff);
	return (str);
}

char	*ft_get_line(char *aux)
{
	int		i;
	char	*str;

	i = 0;
	if (!aux[i])
		return (NULL);
	while (aux[i] && aux[i] != '\n')
		i++;
	if (aux[i] == '\0')
		str = (char *)malloc(sizeof(char) * (i + 1));
	else
		str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (aux[i] && aux[i] != '\n')
	{
		str[i] = aux[i];
		i++;
	}
	if (aux[i] == '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

char	*ft_new_aux(char *aux)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	while (aux[i] && aux[i] != '\n')
		i++;
	if (!aux[i])
	{
		free(aux);
		return (NULL);
	}
	str = (char *)malloc(sizeof(char) * (ft_strlen(aux) - i + 1));
	if (!str)
		return (NULL);
	i++;
	while (aux[i])
		str[j++] = aux[i++];
	str[j] = '\0';
	free(aux);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*aux[10000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	aux[fd] = ft_read_to_aux(fd, aux[fd]);
	if (!aux[fd])
		return (NULL);
	line = ft_get_line(aux[fd]);
	aux[fd] = ft_new_aux(aux[fd]);
	return (line);
}
