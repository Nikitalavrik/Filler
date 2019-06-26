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

int		main(void)
{
	int		fd;
	char	*line;
	t_map	*main_map;
	t_map	*tetramino;

	line = NULL;
	main_map = NULL;
	tetramino = NULL;
	fd = open("tests/test", O_RDONLY);
	init_map(&main_map);
	init_map(&tetramino);


	/* parsing */
	parse_size(line, main_map, fd, 0);
	parse_size(line, tetramino, fd, 1);

	tetramino = reshape(tetramino);
	// printf("%i\n", MOD(20, 100));
	put_tetramin(main_map, tetramino);
	/* output */
	// output_map(*main_map, 1);
	// output_map(*tetramino, 1);
	// output_addinfo(*main_map);
	// output_addinfo(*tetramino);

	/* free */
	free_map(main_map);
	free_map(tetramino);
	
	/* leaks */
	// system("leaks nlavrine");
	return (0);
}
