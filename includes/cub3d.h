/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeserran <jeserran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/08 11:23:47 by jdiaz-co          #+#    #+#             */
/*   Updated: 2020/08/13 18:15:08 by jeserran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CUB3D_H
# define _CUB3D_H

# ifdef __linux__
# define KEY_A 97
# define KEY_W 119
# define KEY_S 115
# define KEY_D 100
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_ESQ 65307
# define KEY_SHIFT 65507
# include <X11/Xlib.h>
# include "../mlx/minilibx_linux/mlx.h"
# endif


# include "../libft/includes/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# ifdef __APPLE__
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESQ 53
# define KEY_SHIFT 257
# include "../mlx/minilibx/mlx.h"
#endif

# define BUFFER_SIZE 1
# define MAXX 1920 
# define MAXY 1080

# define TEXTURE_1 "./textures/stone.xpm"
# define TEXTURE_2 "./textures/wood.xpm"
# define TEXTURE_3 "./textures/mossy.xpm"
# define TEXTURE_4 "./textures/redbrick.xpm"
# define TEXTURE_5 "./textures/coronavirus.xpm"

typedef struct		s_sprite
{
	double			spritex;
	double			spritey;
	double			transformx;
	double			transformy;
	int				scx;
	int				sph;
	int				spw;
	int				spstarty;
	int				spendy;
	int				spstartx;
	int				spendx;
	int				texx;
	int				texy;
	double			spriteposx;
	double			spriteposy;
}					t_sprite;

typedef struct		s_map
{
	char			*mapchar;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	unsigned int	f;
	unsigned int	c;
	int				nocont;
	int				socont;
	int				wecont;
	int				eacont;
	int				scont;
	int				fcont;
	int				ccont;
	int				rcont;
	int				winy;
	int				winx;
	int				width;
	int				height;
	int				**maparray;
	int				y;
	int				x;
	int				n;
	char			dir;
	int				initialdir;
	double			posx;
	double			posy;
	int				screenshot;
	void			*mlx_ptr;
	void			*win_ptr;
	char			*wlone[8];
	char			*wdata[8];
	int				wbpp[8];
	int				wendian[8];
	int				wsl[8];
	int				h[8];
	int				w[8];
	int				col;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			time;
	double			oldtime;
	double			camera;
	double			raydirx;
	double			raydiry;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	double			sidedistx;
	double			sidedisty;
	double			deltadistx;
	double			deltadisty;
	int				hit;
	int				side;
	double			perpwalldist;
	int				lineheight;
	int				drawstart;
	int				drawend;
	double			movespeed;
	double			rotspeed;
	int				color;
	int				badrgb;
	int				j;
	char			*img_ptr;
	int				id;
	double			x_wall;
	int				x_text;
	char			*img;
	int				bpp;
	int				sl;
	int				endian;
	int				fpposx;
	int				fpposy;
	int				alturalinea;
	int				preseda;
	int				presedw;
	int				presedl;
	int				presedr;
	int				preseds;
	int				presedd;
	int				presedesq;
	int				presshift;
	double			oldplanex;
	double			olddirx;
	double			zbuffer[4000];
	int				numsprite;
	t_sprite		*sprite;
	int				obj;
	int				*spriteorder;
	double			*spritedistance;
	int				stripe;
	int				count;
	int				countb;
	int				pos;
	int				r;
	int				g;
	int				b;
}					t_map;

int					parsename(char **argv);
void				read_file(int argc, char **file_name, t_map *tab);
int					get_next_line(int fd, char **line);
void				get_info(t_map *tab, char *line);
void				read_map(t_map *tab);
void				matrix(t_map *tab);
void				stringtoarray(t_map *tab);
void				skiptab(t_map *tab);
int					get_width(char *str);
int					get_height(char *str);
void				initvar(t_map *tab);
int					checkmap(t_map *tab);
void				openall(t_map *tab);
void				wall_texture(t_map *tab);
void				more_texture(t_map *tab);
void				raycasting(t_map *tab);
void				ft_verline(t_map *tab);
void				auxline(t_map *tab);
void				auxlinetwo(t_map *tab);
void				printhp(t_map *tab);
void				put_pxl_to_img(t_map *tab, int x, int y);
void				to_img(t_map *tab);
void				raycauxthree(t_map *tab);
void				calcularobj(t_map *tab);
int					nopulsed(int key, t_map *tab);
int					pulsed(int key, t_map *tab);
int					deal_key(t_map *tab);
int					write_bmp_header(int fd, int filesize, t_map *tab);
int					write_bmp_data(int file, t_map *tab, int pad);
int					ft_close(t_map *tab, int win);
void				draw_sprite(t_map *tab);
void				ft_swap_int(int *a, int *b);
void				ft_swap_double(double *a, double *b);
void				raysprite(t_map *tab);
void				spritepos(t_map *tab, int x, int y);
int					ft_atoi_color(char *line, int *i);
int    				error(int i);
int					test_texture(char *str);
char				*getstr(char *temp);
int					parsecub(t_map *tab);
#endif
