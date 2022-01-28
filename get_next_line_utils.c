/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btenzlin <btenzlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:42:57 by btenzlin          #+#    #+#             */
/*   Updated: 2022/01/28 12:38:59 by btenzlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	is_eol(char *s)
{
	int	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count])
	{
		if (s[count] == '\n')
			return (1);
		count++;
	}
	return (0);
}

size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	if (!str)
		return (0);
	while (str[len] != '\0')
		len++;
	return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*substr;

	if (!s || len <= 0)
		return (0);
	substr = malloc(sizeof(char) * (len + 1));
	if (substr == 0)
		return (0);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (i >= start && j < len)
		{
			substr[j] = s[i];
			j++;
		}
		i++;
	}
	substr[j] = '\0';
	return (substr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		count1;
	int		count2;

	if (!s1 && !s2)
		return (0);
	str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (0);
	count1 = 0;
	while (s1 && s1[count1])
	{
		str[count1] = s1[count1];
		count1++;
	}
	count2 = 0;
	while (s2 && s2[count2])
	{
		str[count1] = s2[count2];
		count1++;
		count2++;
	}
	str[count1] = '\0';
	free((char *)s1);
	return (str);
}
