/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdouiri <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/22 20:02:45 by mdouiri           #+#    #+#             */
/*   Updated: 2022/01/22 20:06:45 by mdouiri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx.h"

int main(void)
{
	void	*mlx_ptr;

	mlx_ptr = mlx_init();
	mlx_destroy_display(mlx_ptr);
	free(mlx_ptr);
}
