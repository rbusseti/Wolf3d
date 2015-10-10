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
    int		mapx;
    int		mapy;
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
    int		stepx;
    int		stepy;
    int		side;
}		t_ray;

typedef struct	s_draw
{
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

typedef struct	s_env
{
    void	*mlx;
    void	*win;
    void	*img;
    t_key	*key;
    t_idata	*idata;
    t_play	*p;
    char	**map;
    double	camx;
}		t_env;

void	ft_init_world(t_env *e, char *map_name);
int	ft_loop_hook(t_env *e);
int	ft_expose_hook(t_env *e);
int	ft_mouse_hook(int button, int x, int y, void *param);
void	ft_update(t_env *e);
void	ft_draw(t_draw pen, int i, t_env *e);
int	ft_key_pressed(int keycode, t_env *e);
int	ft_key_released(int keycode, t_env *e);
void	ft_move_character(t_env *e);

#endif
