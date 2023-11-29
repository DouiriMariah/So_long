/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   define.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 18:34:10 by mdouiri           #+#    #+#             */
/*   Updated: 2022/02/28 18:41:19 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINE_H
# define DEFINE_H

# include "so_long.h"
# define PIX 60
# define PIY 60

//Path
# define SAM_FACE "./img/sam60bon.XPM"
# define ARBRE "./img/arbrenoir.XPM"
# define SOL "./img/solnoir.XPM"
# define EXIT "./img/doorbon.XPM"
# define ITEM "./img/pseudoitem.XPM"
# define UP 119
# define DOWN 115
# define RIGHT 100
# define LEFT 97
# define ESC 65307

typedef struct s_data
{
	void	*image;
	int		large;
	int		hauteur;
}	t_data;

typedef struct s_node
{
	char			*content;
	struct s_node	*next;
}	t_node;

typedef struct s_mappy
{
	int	begi;
	int	item;
	int	player;
}	t_mappy;

typedef struct s_window
{
	int		count;
	void	*mlx;
	void	*mlx_win;
	int		x;
	int		y;
	int		yn;
	int		xn;
	int		moves;
	int		nbline;
	int		item;
	t_node	*tmp;
	t_node	*tmp2;
	t_node	*list;
	t_data	mur;
	t_data	passage;
	t_data	items;
	t_data	player;
	t_data	exito;
}	t_window;

#endif 
