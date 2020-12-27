#include "mlx.h"

int main(void)
{
  void *mlx;
  void *window;
  int i;
  int x;
  int y;

  i = 0;
  x = 100;
  y = 100;  
  mlx = mlx_init();
  window = mlx_new_window(mlx, 1000, 800, "Leo");
  while (i < 50)
  {
  
    mlx_pixel_put(mlx, window, x, y, 0xff0080);
    x++;
    y++;
    i++;
  }
  mlx_loop(mlx);
  return (0);
}