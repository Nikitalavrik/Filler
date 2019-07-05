/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:25:45 by nlavrine          #+#    #+#             */
/*   Updated: 2019/06/26 15:25:46 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_player(t_map *main_map)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) && line && line[0] != '$')
		ft_memdel((void **)&line);
	main_map->player1 = !ft_strncmp(line + ft_get_index(line, 'p'), "1", 1) &&\
	!ft_strncmp(line + ft_get_index(line, 'n'), "lavrine", 7) ? 'O' : 'X';
	main_map->player2 = main_map->player1 == 'X' ? 'O' : 'X';
	ft_memdel((void **)&line);
}

int		solve(t_map *main_map, t_map *tetramino, t_map *new_tet, char *line)
{
	t_coords	answer;
	int			flag;

	while (1)
	{
		line = NULL;
		main_map = parse_size(main_map, line, 0);
		tetramino = parse_size(tetramino, line, 1);
		flag = 0;
		new_tet = reshape(tetramino, flag);
		answer = put_tetramin(main_map, new_tet);
		if (answer.x <= -42 || answer.y <= -42)
		{
			ft_putstr("0 0\n");
			return (0);
		}
		ft_putnbr(answer.y);
		ft_putchar(' ');
		ft_putnbr(answer.x);
		ft_putchar('\n');
		free_map(main_map);
		free_map(new_tet);
		free_map(tetramino);
		ft_memdel((void **)&line);
	}
	ft_memdel((void **)&main_map);
	ft_memdel((void **)&tetramino);
	return (0);
}

int		main(void)
{
	char		*line;
	t_map		*main_map;
	t_map		*tetramino;
	t_map		*new_tet;

	line = NULL;
	new_tet = NULL;
	main_map = NULL;
	tetramino = NULL;
	main_map = init_map(main_map);
	get_player(main_map);
	solve(main_map, tetramino, new_tet, line);
	return (0);
}
