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

// void	check_player(int fd, char *line, t_map *main_map)
// {
// 	if (line[0] != '$')
// 		return ;
	
// }

t_map	*parse_size(t_map *main_map, char *line, int options)
{
	int i;
	char *str;

	i = 0;
	main_map = init_map(main_map);
	get_next_line(0, &line);
	while (line[0] != 'P' && line[0] != ' ' && line[0] != '0')
	{
		ft_memdel((void **)&line);
		get_next_line(0, &line);
	}
	while (!ft_isdigit(line[i]))
		i++;
	main_map->size->y = ft_atoi(&line[i]);
	while (ft_isdigit(line[i]))
		i++;
	main_map->size->x = ft_atoi(&line[i]);
	ft_memdel((void **)&line);
	main_map->elem = (char **)ft_memalloc(sizeof(char *) * main_map->size->y);
	i = 0;
	while (i < (main_map->size->y + 1 - options) && get_next_line(0, &line) != -1)
	{
		if (i > 0 || options)
		{
			str = ft_memalloc(sizeof(char) * main_map->size->x + 1);
			main_map->elem[i - 1 + options] = ft_strcpy(str, line + (options ? 0 : 4));
		}
		ft_memdel((void **)&line);
		i++;
	}
	return (main_map);
}

t_map	*new_size(t_map *t)
{
	int	i;
	char *str;
	t_map *new_tet;

	new_tet = NULL;
	new_tet = init_map(new_tet);
	new_tet->size->x = modulo(t->e_x - t->b_x) + 1;
	new_tet->size->y = modulo(t->e_y - t->b_y) + 1;
	new_tet->b_x = t->b_x;
	new_tet->b_y= t->b_y;
	new_tet->elem = ft_memalloc(sizeof(char *) * new_tet->size->y);
	i = t->b_y;
	while (i < t->e_y + 1)
	{
		str = ft_memalloc(sizeof(char) * new_tet->size->x + 1);
		new_tet->elem[i -  t->b_y] = ft_strncpy(str, t->elem[i] + t->b_x, new_tet->size->x);
		i++;
	}
	return (new_tet);
}

t_map	*reshape(t_map *tetramino)
{
	int	i;
	int	j;
	int	flag;
	t_map *new_tet;

	i = 0;
	flag = 0;
	while (i < tetramino->size->y)
	{
		j = 0;
		while(j < tetramino->size->x){
			if (tetramino->elem[i][j] == '*' && !flag)
			{
				flag = 1;
				tetramino->b_y = i;
				tetramino->b_x = j;
			}
			if (tetramino->elem[i][j] == '*' && tetramino->b_x > j)
				tetramino->b_x = j;
			if (tetramino->elem[i][j] == '*' && tetramino->e_x < j)
				tetramino->e_x = j;
			if (tetramino->elem[i][j] == '*')
				tetramino->e_y = i;
			j++;

		}
		i++;
	}
	new_tet = new_size(tetramino);
	return (new_tet);
}