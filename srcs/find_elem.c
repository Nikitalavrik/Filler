/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_elem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/04 16:14:27 by nlavrine          #+#    #+#             */
/*   Updated: 2019/07/04 16:14:29 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			minim(int x, int y)
{
	return (x > y ? y : x);
}

int			find_left(int y, int x, t_map *main_map)
{
	int	i;

	i = 0;
	while (x - i >= 0)
	{
		if (main_map->elem[y][x - i] == main_map->player2 ||\
		main_map->elem[y][x - i] == (main_map->player2 + 32))
			return (i);
		i++;
	}
	return (BIG_VAL);
}

void		find_down(int **dist, t_map *main_map)
{
	int		i;
	int		j;

	i = 1;
	while (i < main_map->size->y)
	{
		j = 0;
		while (j < main_map->size->x)
		{
			dist[i][j] = minim(dist[i - 1][j] + 1, dist[i][j]);
			j++;
		}
		i++;
	}
}

void		find_right(int **dist, t_map *main_map)
{
	int		i;
	int		j;

	i = 0;
	while (i < main_map->size->y)
	{
		j = main_map->size->x - 2;
		while (j >= 0)
		{
			dist[i][j] = minim(dist[i][j + 1] + 1, dist[i][j]);
			j--;
		}
		i++;
	}
}

void		find_up(int **dist, t_map *main_map)
{
	int		i;
	int		j;

	i = main_map->size->y - 2;
	while (i >= 0)
	{
		j = 0;
		while (j < main_map->size->x)
		{
			dist[i][j] = minim(dist[i + 1][j] + 1, dist[i][j]);
			j++;
		}
		i--;
	}
}
