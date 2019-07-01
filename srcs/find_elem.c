
#include "filler.h"

size_t  modulo(int x)
{
    return (x > 0 ? x : -x);
}

t_coords	find_left(int y, int x, t_map main_map, int r)
{
	int	i;
    t_coords ret;

	i = 0;
	while (i < r && x - i >= 0)
	{
		if (main_map.elem[y][x - i] == 'X' || main_map.elem[y][x - i] == 'x')
        {
            ret.x = x - i;
            ret.y = y;
            return (ret);
        }
			
        i++;
	}
    ret.x = NONE;
    ret.y = NONE;
	return (ret);
}

t_coords     find_right(int y, int x, t_map main_map, int r)
{
    int	i;
    t_coords ret;

	i = 0;
	while (i < r && x + i < main_map.size->x)
	{
		if (main_map.elem[y][x + i] == 'X' || main_map.elem[y][x + i] == 'x')
        {
            ret.x = x + i;
            ret.y = y;
            return (ret);
        }
        i++;
	}
    ret.x = NONE;
    ret.y = NONE;
	return (ret);
}

int     go_forward(t_coords pos, int r, t_map main_map)
{
    int k;
    int tmp_l;
    int tmp_r;
    t_coords coord;

    k = 0;
    while (k <= r && pos.y + k < main_map.size->y && pos.y + k >= 0)
    {
        tmp_l = NONE;
        tmp_r = NONE;
        // printf("x = %i y = %i\n", )
        coord = find_left(pos.y + k, pos.x, main_map, r);
        if (coord.y != NONE)
            tmp_l = modulo(pos.y - coord.y) + modulo(pos.x - coord.x);
        coord = find_right(pos.y + k, pos.x, main_map, r);
        if (coord.y != NONE)
            tmp_r = modulo(pos.y - coord.y) + modulo(pos.x - coord.x);
        if (tmp_l != NONE || tmp_r != NONE)
            return (tmp_l > tmp_r ? tmp_r : tmp_l);        
        // k = -k;
        // if (k > 0)
        k++;
    }
    return (NONE);
}

int		find_x(int y, int x, t_map main_map)
{
	int	r;
    t_coords cord;
    int tmp;

	r = 1;
    cord.x = x;
    cord.y = y;
	while (r < main_map.size->y + 1)
	{
        tmp = go_forward(cord, r, main_map);
        if (tmp != NONE)
            return (tmp);
        r++;
	}
	return (NONE);
}
