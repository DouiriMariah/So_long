/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:11:32 by mdouiri           #+#    #+#             */
/*   Updated: 2022/02/28 16:48:17 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include <stddef.h>
#include <stdio.h>

int	ft_verification(char *str, int *count, int *round, int nbline)
{
	int	i;

	i = 0;
	if (*round == 1 || *round == nbline)
	{
		while (str[i] && str[i] == '1')
			i++;
		if (str[i] == '\n' || str[i] == '\0')
		{
			if (*round == 1)
				*count = i;
			if (*count == i)
				return (0);
		}
	}
	return (1);
}

int	ft_verif2(char *str, t_mappy *map, t_window *data, int *round)
{
	int		i;
	char	*pos;

	i = 0;
	if (*round == data->nbline)
		return (1);
	pos = ft_strchr2(str, 10);
	if (str[0] == '1' && (*pos) == '1')
	{
		while (str[i] && str[i] != '\n' && (str[i] == 'P' || str[i] == 'E'
				|| str[i] == 'C' || str[i] == '0' || str[i] == '1'))
		{
			if (str[i] == 'E')
				map->begi++;
			else if (str[i] == 'C')
				map->item++;
			else if (str[i] == 'P')
				map->player++;
			i++;
		}
	}
	if ((data->count) == i)
		return (0);
	return (1);
}

int	ft_iter(t_node *list, t_window *data)
{
	t_mappy	map;
	int		round;

	map.item = 0;
	map.begi = 0;
	map.player = 0;
	round = 1;
	while (list && list->content)
	{
		if ((ft_verification(list->content, &data->count, &round, data->nbline)
				== 0) || (ft_verif2(list->content, &map, data, &round) == 0))
		{
			if ((data->nbline) == round)
				break ;
			list = list->next;
			round++;
		}
		else
			return (ft_printf("Error \n INVALID MAP GET OUT \n"), 1);
	}
	if (((map.begi) >= 1) && ((map.item) >= 1) && ((map.player) == 1))
		return (0);
	else
		return (ft_printf("Error \n Wrong composition of the map \n"), 1);
}

void	ft_end(t_window *data)
{
	if (ft_iter((data->list), data) == 0)
		ft_begin(&data->count, data);
	else
	{
		deleteallnodes(data->list);
		exit(0);
	}
	if (data->mlx)
		ft_destroy(data);
}

int	simple(int fd)
{
	t_window	data;
	t_node		*first;
	char		*line;

	line = get_next_line(fd);
	first = ft_lstnew(line);
	data.nbline = 1;
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_lstadd_back(&first, ft_lstnew(line));
		(data.nbline)++;
	}
	ft_lstadd_back(&first, ft_lstnew(NULL));
	(data.list) = first;
	ft_end(&data);
	return (0);
}
