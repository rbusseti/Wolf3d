#include "wolf3d.h"

char	**ft_get_map(int fd)
{
    int	    i;
    char    *line;
    char    **map;

    i = 0;
    line = NULL;
    get_next_line(fd, &line);
    map = malloc(sizeof(char *) * (ft_atoi(line) + 1));
    get_next_line(fd, &line);
    while (ft_strcmp(line, "end") != 0)
    {
	map[i] = ft_strdup(line);
        i++;
        get_next_line(fd, &line);
    }
    map[i] = NULL;
    return (map);
}

t_play	*ft_init_player(int fd)
{
    char    *line;
    t_play  *p;

    line = NULL;
    p = malloc(sizeof(*p));
    get_next_line(fd, &line);
    p->posx = ft_atoi(line);
    get_next_line(fd, &line);
    p->posy = ft_atoi(line);
    p->dirx = -1;
    p->diry = 0;
    p->planex = 0;
    p->planey = 0.66;
    return (p);
}

t_idata *ft_get_img_data(t_env *e)
{
    t_idata *idata;

    idata = malloc(sizeof(*idata));
    idata->adr = mlx_get_data_addr(e->img, &(idata->bpp), &(idata->line), &(idata->edian));
    return (idata);
}

t_key	*ft_init_key(void)
{
    t_key   *key;

    key = malloc(sizeof(*key));
    key->left = 0;
    key->right = 0;
    key->up = 0;
    key->down = 0;
    return (key);
}

void	ft_init_world(t_env *e, char *map_name)
{
    int	    fd;

    fd = open(map_name, O_RDONLY);
    e->map = ft_get_map(fd);
    e->p = ft_init_player(fd);
    e->idata = ft_get_img_data(e);
    e->key = ft_init_key();
    close(fd);
}
