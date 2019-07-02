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

int		solve(int fd)
{
	char	*line;
	t_map	*main_map;
	t_map	*tetramino;
	t_map	*new_tet;
	t_coords answer;
	/* parsing */

	while (1)
	{
		
		clear_coords(&answer);
		line = NULL;
		main_map = init_map();
		parse_size(line, main_map, fd, 0);

		tetramino = init_map();
		parse_size(line, tetramino, fd, 1);

		// printf("%i %i\n", tetramino->size->x, tetramino->elem[0][1]);
		new_tet = reshape(tetramino);
		answer = put_tetramin(main_map, new_tet);
	

	/* free */
		free_map(main_map);
		free_map(new_tet);
		free_map(tetramino);
		ft_memdel((void **)&line);
		printf("%i %i\n", answer.y, answer.x);
	}
	/* leaks */
	// system("leaks nlavrine");
	return (0);
}

int		main(void)
{
	// FILE *fp;
	// fp = fopen("log.txt", "a");
	// fprintf(fp, "o = %i\n", 5);
	int fd;

	// fd = open("tests/test2", O_RDONLY);
	fd = 0;

	solve(fd);

	return (0);
}
