#ifndef WOLF3D_H

# define WOLF3D_H

# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <time.h>

# include "libft.h"
# include "mlx.h"
# include "const.h"

typedef struct	s_box
{
    double	north;
    double	south;
    double	east;
    double	west;
}		t_box;

typedef struct	s_play
{
    double	basex;
    double	basey;
    double	posx;
    double	posy;
    double	dirx;
    double	diry;
    double	planex;
    double	planey;
    int		is_tp;
    int		life;
}		t_play;

typedef struct	s_ray
{
    double	posx;
    double	posy;
    double	dirx;
    double	diry;
    double	firstx;
    double	firsty;
    double	nextx;
    double	nexty;
    double	truedist;
    double	wallx;
    int		stepx;
    int		stepy;
    int		mapx;
    int		mapy;
    int		side;
    int		wallh;
    int		walltop;
    int		wallbot;
}		t_ray;

typedef struct	s_idata
{
    char	*adr;
    int		bpp;
    int		line;
    int		edian;
}		t_idata;

typedef struct	s_key
{
    char    left;
    char    right;
    char    up;
    char    down;
    char    space;
}		t_key;

typedef struct	s_tex
{

    t_idata	*wall;
    t_idata	*floor;
    t_idata	*sky;
    t_idata	*sword;
}		t_tex;

typedef struct	s_tp
{
    int		posx;
    int		posy;
    int		destx;
    int		desty;
}		t_tp;

typedef struct	s_gun
{
    int		count;
    int		gap;
    int		texnum;
    int		*split;
    int		ammo;
}		t_gun;

typedef struct	s_sprite
{
    double	posx;
    double	posy;
    double	savex;
    double	savey;
    double	dist;
    char	vis;
    char	shoot;
    char	pick;
    char	move;
    char	*name;
    int		life;
    int		id;
    int		base_id;
    int		frame;
}		t_sprite;

typedef struct	s_calcsp
{
    double	posx;
    double	posy;
    double	transx;
    double	transy;
    double	inv;
    int		height;
    int		top;
    int		bot;
    int		width;
    int		left;
    int		right;
    int		lsave;
    int		rsave;
    int		screenx;
}		t_calcsp;

typedef struct	s_env
{
    void	*mlx;
    void	*win;
    void	*img;
    t_key	*key;
    t_idata	*idata;
    t_play	*p;
    t_gun	*gun;
    t_idata	**tex;
    char	**map;
    char	**tex_name;
    char	*path;
    t_list	*tp;
    double	camx;
    time_t	t1;
    time_t	t2;
    int		frame;
    double	*sdist;
    t_sprite	**sprite;
    int		nb_sprites;
    int		nb_tex;
    char	restart;
}		t_env;

typedef struct	s_floor
{
    double	wallx;
    double	wally;
    double	currentx;
    double	currenty;
    int		texx;
    int		texy; 
}		t_floor;

void		ft_init_world(t_env *e, char *map_name);
int		ft_loop_hook(t_env *e);
int		ft_expose_hook(t_env *e);
int		ft_mouse_hook(int button, int x, int y, void *param);
void		ft_update(t_env *e);
void		ft_draw(int i, t_env *e, t_ray *ray);
int		ft_key_pressed(int keycode, t_env *e);
int		ft_key_released(int keycode, t_env *e);
void		ft_move_character(t_env *e);
t_idata		*ft_get_img_data(void *img);
t_idata		**ft_load_texture(t_env *e);
unsigned long	ft_get_wall_texture(t_idata *wall, t_ray *ray, int j);
unsigned long	ft_get_floor_texture(t_idata **img, t_ray *ray, t_floor *floor, int j, char **map);
unsigned long	ft_get_color(int x, int y, t_idata *img, double truedist);
void		ft_pixel_put_to_image(unsigned long color, t_idata *idata, int y, int x);
void		ft_teleport(t_env *e);
void		ft_print_list(t_list **list);
void		ft_draw_gun(t_env *e);
void		ft_shoot(t_env *e);
void		ft_draw_overlay(t_env *e);
void		ft_calc_sprites(t_env *e);
void		ft_comb_sort(t_sprite **sprite, int size);
void		ft_pickup(t_env *e);
t_sprite	**ft_init_sprites(char *map_name, t_env *e);
void		ft_move_enemy(t_env *e);
void		ft_restart_level(t_env *e);
int		ft_check_box(double x1, double y1, double x2, double y2);

#endif
