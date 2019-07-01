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

#ifndef FT_FILLER

# include "get_next_line.h"
# include <stdio.h>
# include <sys/stat.h> 
# include <fcntl.h>

# define MOD(x) ((x > 0) ? (x) : (-x))
# define NONE 500

typedef	struct	s_coords
{
	int x;
	int y;
	int dist_sum;
}				t_coords;

typedef struct	s_map
{
	t_coords *size;
	int			b_x;
	int			b_y;
	int			e_x;
	int			e_y;
	char		**elem;
}				t_map;

void		free_map(t_map *main_map);
void		output_map(t_map main_map);
void		parse_size(char *line, t_map *main_map, int fd, int options);
void		output_addinfo(t_map t);
t_map		*reshape(t_map *tetramino);
void		init_map(t_map **main_map);
t_coords	put_tetramin(t_map *main_map, t_map *tet);
void		output_matr(int	**matr, int n, int m);
int			find_x(int y, int x, t_map main_map);
void		output_coords(t_coords coord);
size_t  	modulo(int x);

#endif
