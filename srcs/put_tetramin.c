/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tetramin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:25:54 by nlavrine          #+#    #+#             */
/*   Updated: 2019/06/26 15:25:55 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		find_x(int p1, int p2, t_map main_map)
{
	int i;
	int j;
	int	n;

	i = p1;
	n = 1;
	j = 0;
	while (n < main_map.size->x + main_map.size->y)
	{
		while (i + j < n)
		{
			i = p1;
			while (i < n && i < main_map.size->y)
			{
				j = 0;
				while (j < n && j < main_map.size->x)
				{
					if (main_map.elem[i][j] == 'X')
						return(MOD_SUM(MOD_DIV(p1, i), MOD_DIV(p2, j)));			
					j++;
				}
				i++;
			}
		}
		n++;
	}
	return (0);
}

int		**generate_dist(t_map *main_map)
{
	int		i;
	int		j;
	int		**dist;

	i = 0;
	dist = ft_memalloc(sizeof(int *) * main_map->size->y);
	while (i < main_map->size->y)
	{
		j = 0;
		dist[i] = ft_memalloc(sizeof(int) * main_map->size->x);
		while (j < main_map->size->x)
		{
			dist[i][j] = find_x(i, j, *main_map);
			j++;
		}
		i++;
	}
	return (dist);
}		

void	put_tetramin(t_map *main_map, t_map *tet)
{
	int		**dist;

	tet = (void *)tet;
	dist = generate_dist(main_map);
	output_matr(dist, main_map->size->y, main_map->size->x);
}
