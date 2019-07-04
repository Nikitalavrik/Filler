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

char	*skip_lines(char *line)
{
	get_next_line(0, &line);
	while (line[0] != 'P' && line[0] != ' ' && line[0] != '0')
	{
		ft_memdel((void **)&line);
		get_next_line(0, &line);
	}
	return (line);
}

t_map	*parse_size(t_map *main_map, char *line, int opt)
{
	int		i;
	char	*str;

	main_map = init_map(main_map);
	line = skip_lines(line);
	i = ft_get_index(line, ' ');
	main_map->size->y = ft_atoi(line + i);
	main_map->size->x = ft_atoi(line + i + ft_get_index(line + i, ' '));
	ft_memdel((void **)&line);
	main_map->elem = (char **)ft_memalloc(sizeof(char *) * main_map->size->y);
	i = 0;
	while (i < (main_map->size->y + 1 - opt) && get_next_line(0, &line) != -1)
	{
		if (i > 0 || opt)
		{
			str = ft_memalloc(sizeof(char) * main_map->size->x + 1);
			main_map->elem[i - 1 + opt] = ft_strcpy(str, line + (opt ? 0 : 4));
		}
		ft_memdel((void **)&line);
		i++;
	}
	return (main_map);
}

t_map	*new_size(t_map *t)
{
	int		i;
	char	*str;
	t_map	*new_tet;

	new_tet = NULL;
	new_tet = init_map(new_tet);
	new_tet->size->x = modulo(t->e_x - t->b_x) + 1;
	new_tet->size->y = modulo(t->e_y - t->b_y) + 1;
	new_tet->b_x = t->b_x;
	new_tet->b_y = t->b_y;
	new_tet->elem = ft_memalloc(sizeof(char *) * new_tet->size->y);
	i = t->b_y;
	while (i < t->e_y + 1)
	{
		str = ft_memalloc(sizeof(char) * new_tet->size->x + 1);
		new_tet->elem[i - t->b_y] = ft_strncpy(str, t->elem[i]\
											+ t->b_x, new_tet->size->x);
		i++;
	}
	return (new_tet);
}

void	put_flag(int *flag, int y, int x, t_map *tetramino)
{
	*flag = 1;
	tetramino->b_y = y;
	tetramino->b_x = x;
}

t_map	*reshape(t_map *tetramino, int flag)
{
	int		i;
	int		j;
	t_map	*new_tet;

	i = 0;
	while (i < tetramino->size->y)
	{
		j = 0;
		while (j < tetramino->size->x)
		{
			if (tetramino->elem[i][j] == '*' && !flag)
				put_flag(&flag, i, j, tetramino);
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
