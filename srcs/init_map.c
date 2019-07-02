/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 13:57:36 by nlavrine          #+#    #+#             */
/*   Updated: 2019/06/26 13:57:37 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_map	*init_map(void)
{
	t_map *main_map;


	main_map = (t_map *)ft_memalloc(sizeof(t_map));
	main_map->size = (t_coords *)ft_memalloc(sizeof(t_coords));
	main_map->size->x = 0;
	main_map->size->y = 0;
	main_map->b_x = 0;
	main_map->b_y = 0;
	main_map->e_x = 0;
	main_map->e_y = 0;
	main_map->elem= NULL;
	return (main_map);
}