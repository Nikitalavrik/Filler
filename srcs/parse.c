/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 12:12:33 by nlavrine          #+#    #+#             */
/*   Updated: 2019/06/26 12:12:34 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	parse_size(char *line, t_map *main_map, int fd, int options)
{
	int i;

	i = 0;
	get_next_line(fd, &line);
	while (line[0] == '#' || line[0] != 'P')
	{
		ft_memdel((void **)&line);
		get_next_line(fd, &line);
	}
	while (!ft_isdigit(line[i]))
		i++;
	main_map->x = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	main_map->y = ft_atoi(&line[i]);
	ft_memdel((void **)&line);
	main_map->elem = (char **)ft_memalloc(sizeof(char *) * main_map->x);
	i = 0;
	while (i < main_map->x + 1 - options && get_next_line(fd, &line))
	{
		if (i > 0 || options)
			main_map->elem[i - 1 + options] = ft_strdup(line + (options ? 0 : 4));
		ft_memdel((void **)&line);
		i++;
	}
}

void	reshape(t_map *tetramino)
{
	int	max_x;
	int max_y;
	int	i;
	int	j;
	int	count = 0;

	i = 0;
	tetramino->c_x = 0;
	tetramino->c_y = 0;
	while (i < tetramino->x)
	{
		j = 0;
		while(j < tetramino->y){
			if (tetramino->elem[i][j] == '*' && !tetramino->c_x)
			{
				tetramino->c_x = i;
				tetramino->c_y = j;
			}
		}
		
	}
}