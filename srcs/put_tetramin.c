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

int			**generate_dist(t_map *main_map)
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
			dist[i][j] = find_left(i, j, main_map);
			j++;
		}
		i++;
	}
	find_right(dist, main_map);
	find_down(dist, main_map);
	find_up(dist, main_map);
	return (dist);
}

int			calc_dist_sum(int **dist, t_coords coord, t_map *tet)
{
	int i;
	int j;

	i = 0;
	while (i < tet->size->y)
	{
		j = 0;
		while (j < tet->size->x)
		{
			coord.dist_sum = dist[coord.y + i][coord.x + j];
			j++;
		}
		i++;
	}
	return (coord.dist_sum);
}

int			can_put(t_coords coord, t_map *main_map, t_map *tet, int **dist)
{
	int i;
	int j;
	int overlay;

	i = 0;
	overlay = 0;
	if (coord.x + tet->size->x > main_map->size->x ||\
								coord.y + tet->size->y > main_map->size->y)
		return (0);
	while (i < tet->size->y && overlay <= 1)
	{
		j = 0;
		while (j < tet->size->x && overlay <= 1)
		{
			if (dist[coord.y + i][coord.x + j] == 0 && tet->elem[i][j] == '*')
				overlay += 2;
			if ((main_map->elem[coord.y + i][coord.x + j] == main_map->player1\
			|| main_map->elem[coord.y + i][coord.x + j] == main_map->player1 +\
			32) && tet->elem[i][j] == '*')
				overlay++;
			j++;
		}
		i++;
	}
	return (overlay == 1);
}

t_coords	check_tetramin(t_map *m_map, t_map *tet, int **dist, t_coords coord)
{
	int			i;
	int			j;
	t_coords	answer;

	i = 0;
	write_coords(&answer, -42, -42, BIG_VAL);
	while (i < m_map->size->y)
	{
		j = 0;
		while (j < m_map->size->x)
		{
			write_coords(&coord, j, i, BIG_VAL);
			if (can_put(coord, m_map, tet, dist))
				coord.dist_sum = calc_dist_sum(dist, coord, tet);
			if (coord.dist_sum && coord.dist_sum < answer.dist_sum)
				write_coords(&answer, j, i, coord.dist_sum);
			j++;
		}
		i++;
	}
	return (answer);
}

t_coords	put_tetramin(t_map *main_map, t_map *tet)
{
	int			**dist;
	t_coords	answer;
	t_coords	coord;

	write_coords(&coord, -42, -42, BIG_VAL);
	dist = generate_dist(main_map);
	answer = check_tetramin(main_map, tet, dist, coord);
	free_matr(dist, main_map->size->y);
	answer.x -= tet->b_x;
	answer.y -= tet->b_y;
	return (answer);
}
