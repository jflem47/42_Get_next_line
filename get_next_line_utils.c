/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlemieux <jlemieux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 14:40:45 by jlemieux          #+#    #+#             */
/*   Updated: 2023/02/23 15:00:27 by jlemieux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_bzero(void *b, size_t len)
{
	while (len--)
		((char *)b)[len] = 0;
}

void	*ft_sfree(void *str)
{
	free(str);
	return (NULL);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	res = malloc(count * size);
	while (!res)
		res = malloc(count * size);
	ft_bzero(res, count * size);
	return (res);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	char	*res;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	res = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!res)
		return (res = ft_sfree(res), NULL);
	while (s1_len + s2_len-- > s1_len)
		res[s1_len + s2_len] = s2[s2_len];
	while (s1_len--)
		res[s1_len] = s1[s1_len];
	if (*res == 0)
		res = ft_sfree(res);
	return (ft_sfree(s1), res);
}
