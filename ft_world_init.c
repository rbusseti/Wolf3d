# include "wolf3d.h"

char	**get_map(int fd)
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

t_cam	*ft_cam_init(void)
{
    t_cam   *cam;

    cam = malloc(sizeof(*cam));
    cam->angle = 0;
    cam->next_ray = FOV / SCRW;
    cam->dist = 277;
    return (cam);
}

int	ft_world_init(t_env *e)
{
    int	    fd;
    char    *line;

    line = NULL;
    fd = open("world/map0.txt", O_RDONLY);
    e->map = get_map(fd);
    get_next_line(fd, &line);
    e->cam = ft_cam_init();
    e->cam->posx = ft_atoi(line) * C_SIZE;
    get_next_line(fd, &line);
    e->cam->posy = ft_atoi(line) * C_SIZE;
    close(fd);
    return (0);
}
