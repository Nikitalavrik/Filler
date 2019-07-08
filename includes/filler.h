/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 19:12:20 by nlavrine          #+#    #+#             */
/*   Updated: 2019/06/25 19:12:21 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FILLER_H
# define FT_FILLER_H

# include "get_next_line.h"
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>

# define MOD(x) ((x > 0) ? (x) : (-x))
# define NONE 500
# define BIG_VAL 7000

typedef	struct	s_coords
{
	int x;
	int y;
	int dist_sum;
}				t_coords;

typedef struct	s_map
{
	char		player1;
	char		player2;
	t_coords	*size;
	int			b_x;
	int			b_y;
	int			e_x;
	int			e_y;
	char		**elem;
}				t_map;

t_map			*parse_size(t_map *main_map, char *line, int options);
t_map			*reshape(t_map *tetramino, int flag);
t_map			*init_map(t_map *main_map);
t_coords		put_tetramin(t_map *main_map, t_map *tet);

int				find_left(int y, int x, t_map *main_map);
void			find_down(int **dist, t_map *main_map);
void			find_right(int **dist, t_map *main_map);
void			find_up(int **dist, t_map *main_map);

void			foutput_map(t_map *main_map);
void			output_addinfo(t_map *t);
void			output_map(t_map *main_map);
void			output_coords(t_coords coord);
void			output_matr(int	**matr, int n, int m);

void			free_matr(int **matr, int size);
void			write_coords(t_coords *cords, int x, int y, int dist);
void			free_map(t_map *main_map);

#endif
