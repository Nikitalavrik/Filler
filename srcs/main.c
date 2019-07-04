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
	// 	FILE *fp;
	// fp = fopen("log.txt", "w+");
	// fprintf(fp, "player1 = %c\nplayer2 = %c\n", main_map->player1, main_map->player2);
	// fclose(fp);
	
	ft_memdel((void **)&line);
}

int		solve(void)
{
	char	*line;
	t_map	*main_map;
	t_map	*tetramino;
	t_map	*new_tet;
	t_coords answer;
	int		i;

	main_map = NULL;
	main_map = init_map(main_map);
	tetramino = NULL;
	get_player(main_map);
	i = 0;
	while (1)
	{
		clear_coords(&answer);
		line = NULL;
		main_map = parse_size(main_map, line, 0);
		tetramino = parse_size(tetramino, line, 1);
		new_tet = reshape(tetramino);
		answer = put_tetramin(main_map, new_tet);
		// printf("%i %i\n", answer.y, answer.x);
		if (answer.x <= -42 || answer.y <= -42)
			return (0);
		ft_putnbr(answer.y);
		ft_putchar(' ');
		ft_putnbr(answer.x);
		ft_putchar('\n');

		

	/* free */
		free_map(main_map);
		free_map(new_tet);
		free_map(tetramino);
		ft_memdel((void **)&line);
		
		i++;
	}
	ft_memdel((void **)&main_map);
	ft_memdel((void **)&tetramino);
	// /* leaks */
	// system("leaks nlavrine");
	return (0);
}

int		main(void)
{

	// fd = open("tests/test2", O_RDONLY);

	solve();

	return (0);
}
