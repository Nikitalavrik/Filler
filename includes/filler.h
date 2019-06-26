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

typedef struct	s_map
{
	int		x;
	int		y;
	int		c_x;
	int		c_y;
	char	**elem;
}				t_map;

void	free_map(t_map *main_map);
void	output_map(t_map main_map);
void	parse_size(char *line, t_map *main_map, int fd, int options);

#endif
