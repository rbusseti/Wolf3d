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
    p->is_tp = 0;
    p->life = 99;
    return (p);
}

t_key	*ft_init_key(void)
{
    t_key   *key;

    key = malloc(sizeof(*key));
    key->left = 0;
    key->right = 0;
    key->up = 0;
    key->down = 0;
    key->space = 0;
    return (key);
}

void	ft_get_teleport(t_list **list, int fd)
{
    t_tp    *tp;
    char    *line;

    line = NULL;
    tp = malloc(sizeof(*tp));
    get_next_line(fd, &line);
    tp->posx = ft_atoi(line);
    get_next_line(fd, &line);
    tp->posy = ft_atoi(line);
    get_next_line(fd, &line);
    tp->destx = ft_atoi(line);
    get_next_line(fd, &line);
    tp->desty = ft_atoi(line);
    ft_list_push_back(list, tp);
}

void	ft_init_teleport(int fd, t_env *e)
{
    char    *line;

    line = NULL;
    e->tp = NULL;
    get_next_line(fd, &line);
    while (ft_strcmp(line, "tp") == 0)
    {
	ft_get_teleport(&(e->tp), fd);
	get_next_line(fd, &line);
    }
}

t_gun	*ft_init_gun(void)
{
    t_gun   *gun;

    gun = malloc(sizeof(*gun));
    gun->split = (int *)malloc(sizeof(int) * 6);
    gun->split[0] = 0;
    gun->split[1] = 84;
    gun->split[2] = 201;
    gun->split[3] = 297;
    gun->split[4] = 387;
    gun->split[5] = 501;
    gun->count = 0;
    gun->texnum = 4;
    gun->ammo = 10;
    return (gun);
}

void	ft_init_world(t_env *e, char *map_name)
{
    int	    fd;

    fd = open(map_name, O_RDONLY);
    e->map = ft_get_map(fd);
    e->p = ft_init_player(fd);
    e->idata = ft_get_img_data(e->img);
    e->key = ft_init_key();
    e->gun = ft_init_gun();
    e->path = "Ressources/";
    ft_init_teleport(fd, e);
    e->sprite = ft_init_sprites(fd, e);
    close(fd);
    e->tex = ft_load_texture(e);
    e->t1 = 0;
    e->t2 = 0;
    e->frame = 0;
    e->sdist = malloc(sizeof(double) * SCRW);
}
