/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 19:10:26 by mdouiri           #+#    #+#             */
/*   Updated: 2022/02/28 16:59:47 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <stdlib.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_strchr2(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	i--;
	return (&s[i]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (to_find[j] == '\0')
		return (str);
	while (str[i])
	{
		j = 0;
		while (str[i + j] == to_find[j] && to_find[j] != '\0')
		{
			j++;
			if (to_find[j] == '\0' && str[i + j] == '\0')
				return (&str[i]);
		}
		i++;
	}
	return (0);
}

int	ft_strleni(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*start_buffer;
	char	*res;
	int		v;

	start_buffer = s1;
	res = malloc((ft_strleni(s1) + ft_strleni(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	v = 0;
	while (s1 && *s1)
		res[v++] = *s1++;
	while (s2 && *s2)
		res[v++] = *s2++;
	res[v] = '\0';
	if (start_buffer)
		free(start_buffer);
	return (res);
}
