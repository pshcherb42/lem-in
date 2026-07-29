/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pshcherb <pshcherb@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 10:35:15 by pshcherb          #+#    #+#             */
/*   Updated: 2024/11/28 15:26:06 by pshcherb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr_gnl(char *string, int searchedChar)
{
	int	i;

	i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == (char)searchedChar)
			return (&((char *)string)[i]);
		i++;
	}
	if ((char)searchedChar == '\0')
		return (&((char *)string)[i]);
	return (0);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char		*result;
	int			i;
	int			j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	result = (char *)malloc(sizeof(char) * ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1);
	if (!result)
		return (ft_free(&s1));
	i = -1;
	while (s1[++i])
		result[i] = s1[i];
	j = -1;
	while (s2[++j])
		result[i + j] = s2[j];
	result[i + j] = '\0';
	free(s1);
	return (result);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	i = 0;
	if (!s)
		return (0);
	if (start > ft_strlen_gnl(s))
	{
		result = malloc(sizeof(char) * (1));
		if (!result)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (ft_strlen_gnl(s) - start < len)
		len = ft_strlen_gnl(s) - start;
	result = malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	while (start < ft_strlen_gnl(s) && i < len && s[start])
		result[i++] = s[start++];
	result[i] = '\0';
	return (result);
}
