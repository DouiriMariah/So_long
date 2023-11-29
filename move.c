/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 15:54:55 by mdouiri           #+#    #+#             */
/*   Updated: 2022/02/28 18:42:37 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "define.h"

int	ft_destroy(t_window *data)
{
	mlx_destroy_image(data->mlx, data->passage.image);
	mlx_destroy_image(data->mlx, data->items.image);
	mlx_destroy_image(data->mlx, data->exito.image);
	mlx_destroy_image(data->mlx, data->player.image);
	mlx_destroy_image(data->mlx, data->mur.image);
	mlx_destroy_window(data->mlx, data->mlx_win);
	mlx_destroy_display (data->mlx);
	free(data->mlx);
	deleteallnodes(data->list);
	ft_printf("To be continued \n");
	exit(0);
}

int	checkerss(t_window *data, int x, int y)
{
	int		i;
	int		j;
	char	c;

	i = data->xn + x;
	j = data->yn + y;
	data->y = 0;
	data->tmp2 = data->list;
	while (++data->y <= j)
		data->tmp2 = data->tmp2->next;
	c = data->tmp2->content[i];
	data->y = 0;
	if ((c == 'E' && data->item > 0) || c == '1')
		return (0);
	else if (c == 'C')
		data->item--;
	else if (c == 'E' && data->item <= 0)
	{
		data->moves++;
		ft_printf("%d \n", data->moves);
		ft_destroy(data);
	}
	return (1);
}

void	move3(t_window *data, int y, int j)
{
	t_node	*temp;

	data->tmp2 = data->list;
	while (++j < data->yn)
		data->tmp2 = data->tmp2->next;
	if (y == -1)
		temp = data->tmp2;
	data->tmp2 = data->tmp2->next;
	data->tmp2->content[data->xn] = '0';
	if (y == 1)
		temp = data->tmp2->next;
	temp->content[data->xn] = 'P';
}

void	move2(t_window *data, int x, int y)
{
	int	j;

	j = 0;
	if (!checkerss(data, x, y))
		return ;
	data->moves++;
	ft_printf("%d \n", data->moves);
	if (x != 0)
	{
		data->tmp2 = data->list;
		while (++j <= data->yn)
			data->tmp2 = data->tmp2->next;
		data->tmp2->content[data->xn] = '0';
		data->tmp2->content[data->xn + x] = 'P';
	}
	else if (y != 0)
		move3(data, y, j);
}

int	move(int keysum, t_window *data)
{
	data->list = data->tmp;
	data->y = 0;
	if (keysum == ESC)
		ft_destroy(data);
	else if (keysum == UP)
		move2(data, 0, -1);
	else if (keysum == DOWN)
		move2(data, 0, 1);
	else if (keysum == LEFT)
		move2(data, -1, 0);
	else if (keysum == RIGHT)
		move2(data, 1, 0);
	ft_draw_scene(data);
	return (1);
}
