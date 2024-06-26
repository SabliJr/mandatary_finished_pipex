/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sabakar- <sabakar-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 14:09:39 by sabakar-          #+#    #+#             */
/*   Updated: 2024/05/04 12:03:52 by sabakar-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int	has_end(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

int	ft_strlen_gnl(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	initialize(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*result;

	initialize(&i, &j);
	if (!s1)
	{
		s1 = malloc(1 * sizeof(char));
		if (!s1)
			return (NULL);
		s1[0] = 0;
	}
	result = (char *)malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1)
			* sizeof(char));
	if (result == NULL)
		return (free(s1), NULL);
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	while (s2[j])
		result[i++] = s2[j++];
	result[i] = 0;
	return (free(s1), result);
}

char	*line_dealer(char *updated)
{
	int		i;
	int		j;
	int		size;
	char	*line;

	initialize(&i, &j);
	size = ft_strlen_gnl(updated);
	if (has_end(updated))
		size = has_end(updated);
	line = (char *)malloc((size + 2) * sizeof(char));
	if (!line)
		return (NULL);
	while (updated[i] != '\n' && updated[i])
	{
		line[i] = updated[i];
		i++;
	}
	if (updated[i] == '\n')
		line[i++] = '\n';
	line[i] = 0;
	while (updated[i])
		updated[j++] = updated[i++];
	while (updated[j])
		updated[j++] = 0;
	return (line);
}
