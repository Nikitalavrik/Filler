/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nlavrine <nlavrine@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 11:50:23 by nlavrine          #+#    #+#             */
/*   Updated: 2019/06/26 11:50:24 by nlavrine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	output_map(t_map *main_map)
{
	int	i;

	i = 0;
	printf("x = %i y = %i\n", main_map->size->x, main_map->size->y);
	while (i < main_map->size->y)
	{
		printf("%s\n", main_map->elem[i]);
		i++;
	}
}

void	output_addinfo(t_map *t)
{
	printf("---------------------------\n");
	printf("x = %i y = %i\nb_x = %i b_y = %i\ne_x = %i e_y = %i\n",
	t->size->x, t->size->y, t->b_x, t->b_y, t->e_x, t->e_y);
}

void	output_matr(int **matr, int n, int m)
{
	int i;
	int j;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < m)
		{
			printf("%6i ", matr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	output_coords(t_coords coord)
{
	printf("x = %i y = %i dist_sum = %i\n",
	coord.x, coord.y, coord.dist_sum);
}

void	foutput_map(t_map *main_map)
{
	int		i;
	FILE	*fp;

	fp = fopen("log.txt", "w");
	i = 0;
	fprintf(fp, "x = %i y = %i\n", main_map->size->x, main_map->size->y);
	while (i < main_map->size->y)
	{
		fprintf(fp, "%s\n", main_map->elem[i]);
		i++;
	}
	fclose(fp);
}
