/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_keyboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ullorent <ullorent@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 10:34:36 by ullorent          #+#    #+#             */
/*   Updated: 2021/12/13 10:57:10 by ullorent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_movements_c(t_mdata *cmap)
{
	cmap->moves++;
	printf("Movements: %d\n", cmap->moves);
}

int	ft_close(t_mdata *cmap)
{
	mlx_destroy_window(cmap->mlx, cmap->mlx_win);
	mlx_destroy_image(cmap->mlx, cmap->addr);
	exit(0);
	return (0);
}

int	ft_move(int keyhook, t_mdata *cmap)
{
	int		num;

	num = 50;
	if (keyhook == 65307)
		ft_close(cmap);
	if (cmap->col <= 0
		&& ((keyhook == 100 && cmap->fmap[cmap->pos_y][cmap->pos_x + 1] == 'E')
		|| (keyhook == 115 && cmap->fmap[cmap->pos_y + 1][cmap->pos_x] == 'E')
		|| (keyhook == 97 && cmap->fmap[cmap->pos_y][cmap->pos_x - 1] == 'E')
		|| (keyhook == 119 && cmap->fmap[cmap->pos_y - 1][cmap->pos_x] == 'E')))
		ft_close(cmap);
	if (keyhook == 119 && cmap->fmap[cmap->pos_y - 1][cmap->pos_x] != '1' &&
		cmap->fmap[cmap->pos_y - 1][cmap->pos_x] != 'E')
		ft_w_key(cmap);
	else if (keyhook == 97 && cmap->fmap[cmap->pos_y][cmap->pos_x - 1] != '1' &&
		cmap->fmap[cmap->pos_y][cmap->pos_x - 1] != 'E')
		ft_a_key(cmap);
	else if (keyhook == 115 && cmap->fmap[cmap->pos_y + 1][cmap->pos_x] != '1' &&
		cmap->fmap[cmap->pos_y + 1][cmap->pos_x] != 'E')
		ft_s_key(cmap);
	else if (keyhook == 100 && cmap->fmap[cmap->pos_y][cmap->pos_x + 1] != '1' &&
		cmap->fmap[cmap->pos_y][cmap->pos_x + 1] != 'E')
		ft_d_key(cmap);
	return (0);
}
