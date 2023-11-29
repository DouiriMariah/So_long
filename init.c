/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/23 16:17:19 by mdouiri           #+#    #+#             */
/*   Updated: 2022/02/28 18:43:54 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"
#include "define.h"
#include <mlx.h>
#include <mlx_int.h>

t_data	ft_generate_image(t_window *data, char *pos)
{
	t_data	image;
	int		largeur;
	int		hauteur;

	largeur = PIX;
	hauteur = PIY;
	image.image = mlx_xpm_file_to_image(data->mlx, pos,
			&image.large, &image.hauteur);
	return (image);
}

void	init_image(t_window *data)
{
	data->mur = ft_generate_image(data, "./img/palmier.XPM");
	data->passage = ft_generate_image(data, "./img/soli.XPM");
	data->exito = ft_generate_image(data, "./img/fin.XPM");
	data->player = ft_generate_image(data, "./img/sam.XPM");
	data->items = ft_generate_image(data, "./img/item.XPM");
}

void	put_to_window(t_window *data, char *str)
{
	if (str[data->x] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->mur.image,
			(data->mur.large * (data->x)), (data->mur.hauteur * (data->y)));
	else if (str[data->x] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->passage.image,
			(data->passage.large * (data->x)),
			(data->passage.hauteur * (data->y)));
	else if (str[data->x] == 'E')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->exito.image,
			(data->exito.large * (data->x)), (data->exito.hauteur * (data->y)));
	else if (str[data->x] == 'P')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player.image,
			(data->player.large * (data->x)),
			(data->player.hauteur * (data->y)));
		data->yn = data->y;
		data->xn = data->x;
	}
	else if (str[data->x] == 'C')
	{
		data->item++;
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->items.image,
			(data->items.large * (data->x)), (data->items.hauteur * (data->y)));
	}
}

void	ft_draw_scene(t_window *data)
{
	char	*str;

	data->tmp2 = data->list;
	data->item = 0;
	while (data->tmp2 && data->tmp2->content)
	{
		str = data->tmp2->content;
		data->x = -1;
		while (str[++(data->x)])
			put_to_window(data, str);
		data->tmp2 = (data->tmp2)->next;
		(data->y)++;
	}
}

void	ft_begin(int *cara, t_window *data)
{
	data->tmp = data->list;
	data->y = 0;
	data->moves = 0;
	data->xn = 0;
	data->yn = 0;
	ft_checkinit(data);
	init_image(data);
	if (data->mlx != NULL)
	{
		ft_window(cara, data);
		if (data->mlx_win != NULL)
		{
			ft_draw_scene(data);
			mlx_hook(data->mlx_win, 2, 1L << 0, move, data);
			mlx_hook(data->mlx_win, 17, 0, ft_destroy, data);
			mlx_loop(data->mlx);
		}
	}
}
