/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:50:16 by nlavrine          #+#    #+#             */
/*   Updated: 2019/06/26 11:50:17 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_map(t_map *main_map)
{
	int	i;

	i = 0;
	while (i < main_map->size->y)
	{
		ft_memdel((void **)&main_map->elem[i]);
		i++;
	}
	ft_memdel((void **)&main_map->size);
	ft_memdel((void **)&main_map->elem);
}

void	free_matr(int **matr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_memdel((void **)&matr[i]);
		i++;
	}
	ft_memdel((void **)&matr);
}

void	write_coords(t_coords *cords, int x, int y, int dist)
{
	cords->x = x;
	cords->y = y;
	cords->dist_sum = dist;
}
