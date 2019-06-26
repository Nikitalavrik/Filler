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

void	output_map(t_map main_map)
{
	int	i;

	i = 0;
	printf("x = %i n = %i\n", main_map.x , main_map.y);
	while (i < main_map.x)
	{
		printf("%s\n", main_map.elem[i]);
		i++;
	}
}
