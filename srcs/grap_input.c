/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   grap_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:50:02 by nlavrine          #+#    #+#             */
/*   Updated: 2019/06/25 17:50:03 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main(void)
{
	int		fd;
	char	*line;
	t_map	*main_map;
	t_map	*tetramino;

	line = NULL;
	main_map = (t_map *)ft_memalloc(sizeof(t_map));
	tetramino = (t_map *)ft_memalloc(sizeof(t_map));
	fd = open("tests/test3", O_RDONLY);
	parse_size(line, main_map, fd, 0);
	output_map(*main_map);
	parse_size(line, tetramino, fd, 1);
	reshape(tetramino);
	output_map(*tetramino);

	free_map(main_map);
	free_map(tetramino);
	system("leaks nlavrine");
	return (0);
}