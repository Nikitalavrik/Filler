#include "visual.h"

int deal_key(int key, void *param)
{
    printf("Keycode = %i or %c\n", key, key);
    if (key == 65307)
    {
        mlx_destroy_window(g_mlx_ptr, g_win_ptr);
        exit(0);
    }
    return (0);
}

int fill_square(int x, int y, int height, int width)
{
    int i;
    int j;

    i = 0;
    while (i < height)
    {
        j = 0;
        while (j < width)
        {
            mlx_pixel_put(g_mlx_ptr,  g_win_ptr, x + j, y + i, 0xFFFFFF);
            j++;
        }
        i++;
    }
    return (0);
}

int display_map(int x, int y)
{
    int i;
    int j;
    int koef_x;
    int koef_y;

    i = 0;
    koef_x = (WIN_WIDTH - 40) / x;
    koef_y = (WIN_HEIGHT - 100 - 2 * y) / y;
    printf("koef_y = %i koef_x = %i\n", koef_y, koef_x);
    while (i < y)
    {
        j = 0;
        while (j < x)
        {
            fill_square(20 + j * koef_x, 20 + i * koef_y, koef_y - 1, koef_x - 1);
            j++;
        }
        i++;
    }
    return (0);
}

int main(void)
{
    // void *img_ptr;
    int *img;
    int     i;

    i = 0;
    g_mlx_ptr = mlx_init();
    g_win_ptr = mlx_new_window(g_mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Woooof");
    // display_map(SQUARE_X, SQUARE_Y);
    // mlx_key_hook(g_win_ptr, deal_key, (void *)0);
    img = malloc(100);
    while (i < 100)
    {
        img[i] = 0xFFFFF;
        i++;
    }
    mlx_put_image_to_window
    mlx_loop(g_mlx_ptr);
    return (0);
}