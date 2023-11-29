/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mainbis.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:05:01 by mdouiri           #+#    #+#             */
/*   Updated: 2022/02/28 19:02:03 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stddef.h>
#include "so_long.h"

void	ft_checkinit(t_window *data)
{
	data->mlx = mlx_init();
	if (!data->mlx || data->mlx == 0)
	{
		deleteallnodes(data->list);
		exit(0);
	}
	return ;
}

void	ft_window(int *cara, t_window *data)
{
	data->mlx_win = mlx_new_window(data->mlx, (PIX * (*cara)),
			(PIY * (data->nbline)), "so_long");
	if (data->mlx_win != NULL && data->mlx_win != 0)
		return ;
	else
	{
		free(data->mlx);
		deleteallnodes(data->tmp);
		exit(0);
	}
}

void	deleteallnodes(t_node *start)
{
	t_node	*temp;

	while (start != NULL)
	{
		temp = start;
		start = start -> next;
		free(temp->content);
		free(temp);
	}
}

int	main(int ac, char **argv)
{
	int	fd;

	if (ac != 2)
		return (ft_printf("Error \n Too many arguments\n"), 0);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_printf("Error \n File doesn't exist\n"), 0);
	if (ft_strstr(argv[1], ".ber") == 0)
		return (ft_printf("Error \n Wrong format of the map\n"), 0);
	simple(fd);
	close(fd);
	return (0);
}
