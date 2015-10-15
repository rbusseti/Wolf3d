#ifndef WOLF3D_H

# define WOLF3D_H

# include <math.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft.h"
# include "mlx.h"
# include "const.h"

typedef struct	s_play
{
    double	posx;
    double	posy;
    double	dirx;
    double	diry;
    double	planex;
    double	planey;
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
}		t_ray;

typedef struct	s_draw
{
    int		wallh;
    int		walltop;
    int		wallbot;
    int		side;
    double	dirx;
    double	diry;
}		t_draw;

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
}		t_key;

typedef struct	s_tex
{
    t_idata	*wall;
    t_idata	*floor;
    t_idata	*sky;
    t_idata	*sword;
}		t_tex;

typedef struct	s_env
{
    void	*mlx;
    void	*win;
    void	*img;
    void	*swrdimg;
    t_key	*key;
    t_idata	*idata;
    t_play	*p;
    t_tex	*tex;
    char	**map;
    double	camx;
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

void	ft_init_world(t_env *e, char *map_name);
int	ft_loop_hook(t_env *e);
int	ft_expose_hook(t_env *e);
int	ft_mouse_hook(int button, int x, int y, void *param);
void	ft_update(t_env *e);
void	ft_draw(t_draw pen, int i, t_env *e, t_ray *ray);
int	ft_key_pressed(int keycode, t_env *e);
int	ft_key_released(int keycode, t_env *e);
void	ft_move_character(t_env *e);
t_idata	*ft_get_img_data(void *img);
t_tex	*ft_load_texture(t_env *e);
unsigned long	ft_get_wall_texture(t_idata *wall, t_ray *ray, t_draw *pen, int j);
unsigned long	ft_get_floor_texture(t_idata *wall, t_ray *ray, t_floor *floor, int j);
unsigned long	ft_get_color(int x, int y, t_idata *img);
void	ft_pixel_put_to_image(unsigned long color, t_idata *idata, int y, int x);


#endif
