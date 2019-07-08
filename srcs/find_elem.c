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

t_coords	find_left(int y, int x, t_map *main_map, int r)
{
	int			i;
	t_coords	ret;

	i = 0;
	while (i < r && x - i >= 0)
	{
		if (main_map->elem[y][x - i] == main_map->player2 ||\
		main_map->elem[y][x - i] == (main_map->player2 + 32))
		{
			ret.x = x - i;
			ret.y = y;
			return (ret);
		}
		i++;
	}
	ret.x = NONE;
	ret.y = NONE;
	return (ret);
}

t_coords	find_right(int y, int x, t_map *main_map, int r)
{
	int			i;
	t_coords	ret;

	i = 0;
	while (i < r && x + i < main_map->size->x)
	{
		if (main_map->elem[y][x + i] == main_map->player2 ||\
		main_map->elem[y][x + i] == (main_map->player2 + 32))
		{
			ret.x = x + i;
			ret.y = y;
			return (ret);
		}
		i++;
	}
	ret.x = NONE;
	ret.y = NONE;
	return (ret);
}

int			go_forward(t_coords pos, int r, t_map *main_map)
{
	int			k;
	int			tmp_l;
	int			tmp_r;
	t_coords	coord;

	k = 0;
	while (k <= r && pos.y + k < main_map->size->y && pos.y + k >= 0 && -k <= r)
	{
		tmp_l = NONE;
		tmp_r = NONE;
		coord = find_left(pos.y + k, pos.x, main_map, r - k);
		if (coord.y != NONE)
			tmp_l = modulo(pos.y - coord.y) + modulo(pos.x - coord.x);
		coord = find_right(pos.y + k, pos.x, main_map, r - k);
		if (coord.y != NONE)
			tmp_r = modulo(pos.y - coord.y) + modulo(pos.x - coord.x);
		if (tmp_l != NONE || tmp_r != NONE)
			return (tmp_l > tmp_r ? tmp_r : tmp_l);
		k++;
	}
	return (NONE);
}

int			go_down(t_coords pos, int r, t_map *main_map)
{
	int			k;
	int			tmp_l;
	int			tmp_r;
	t_coords	coord;

	k = 0;
	while (k <= r && pos.y - k >= 0)
	{
		tmp_l = NONE;
		tmp_r = NONE;
		coord = find_left(pos.y - k, pos.x, main_map, r - k);
		if (coord.y != NONE)
			tmp_l = modulo(pos.y - coord.y) + modulo(pos.x - coord.x);
		coord = find_right(pos.y - k, pos.x, main_map, r - k);
		if (coord.y != NONE)
			tmp_r = modulo(pos.y - coord.y) + modulo(pos.x - coord.x);
		if (tmp_l != NONE || tmp_r != NONE)
			return (tmp_l > tmp_r ? tmp_r : tmp_l);
		k++;
	}
	return (NONE);
}

int			find_x(int y, int x, t_map *main_map)
{
	int			r;
	t_coords	cord;
	int			tmp1;
	int			tmp2;

	r = 1;
	cord.x = x;
	cord.y = y;
	while (r < main_map->size->x + main_map->size->y / 2)
	{
		tmp1 = go_forward(cord, r, main_map);
		tmp2 = go_down(cord, r, main_map);
		if (tmp1 != NONE || tmp2 != NONE)
			return (tmp1 > tmp2 ? tmp2 : tmp1);
		r++;
	}
	return (NONE);
}
