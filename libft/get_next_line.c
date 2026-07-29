/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:34:34 by pshcherb          #+#    #+#             */
/*   Updated: 2024/11/28 15:45:08 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*clean_storage(char *storage)
{
	char	*new_storage;
	char	*ptr;
	int		len;

	ptr = ft_strchr_gnl(storage, '\n');
	if (!ptr)
	{
		new_storage = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (storage[len] == '\0')
		return (ft_free(&storage));
	new_storage = ft_substr_gnl(storage, len, ft_strlen_gnl(storage) - len);
	ft_free(&storage);
	if (!new_storage)
		return (NULL);
	return (new_storage);
}

char	*ft_line(char *buffer)
{
	char	*line;
	char	*ptr;
	int		i;

	ptr = ft_strchr_gnl(buffer, '\n');
	i = (ptr - buffer) + 1;
	line = ft_substr_gnl(buffer, 0, i);
	if (!line)
		return (NULL);
	return (line);
}

char	*read_file(int fd, char *save)
{
	char	*tmp;
	int		byte_read;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	byte_read = 1;
	if (!tmp)
		return (ft_free(&save));
	tmp[0] = '\0';
	while (byte_read > 0 && !ft_strchr_gnl(tmp, '\n'))
	{
		byte_read = read(fd, tmp, BUFFER_SIZE);
		if (byte_read > 0)
		{
			tmp[byte_read] = '\0';
			save = ft_strjoin_gnl(save, tmp);
		}
	}
	free(tmp);
	if (byte_read == -1)
		return (ft_free(&save));
	return (save);
}

char	*get_next_line(int fd)
{
	static char	*buffer = {0};
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((buffer && !ft_strchr_gnl(buffer, '\n')) || !buffer)
		buffer = read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	if (!line)
		return (ft_free(&buffer));
	buffer = clean_storage(buffer);
	return (line);
}
