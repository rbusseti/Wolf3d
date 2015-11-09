#include "wolf3d.h"

void	    ft_get_sprite_info(t_sprite *sprite, char *file)
{
    int	    fd;
    char    *line;

    line = NULL;
    fd = open(ft_strjoin(file, ".txt"), O_RDONLY);
    get_next_line(fd, &line);
    sprite->name = ft_strdup(line);
    get_next_line(fd, &line);
    sprite->vis = ft_atoi(ft_strsplit(line, ' ')[1]);
    get_next_line(fd, &line);
    sprite->shoot = ft_atoi(ft_strsplit(line, ' ')[1]);
    get_next_line(fd, &line);
    sprite->pick = ft_atoi(ft_strsplit(line, ' ')[1]);
    get_next_line(fd, &line);
    sprite->life = ft_atoi(ft_strsplit(line, ' ')[1]);
    get_next_line(fd, &line);
    sprite->id = ft_atoi(ft_strsplit(line, ' ')[1]);
    get_next_line(fd, &line);
    sprite->frame = ft_atoi(ft_strsplit(line, ' ')[1]);
    sprite->base_id = sprite->id;
    sprite->move = 0;
    close(fd);
}

t_sprite    **ft_init_sprites(int fd, t_env *e)
{
    t_sprite	**sprites;
    char	*line;
    char	**split;
    int		i;

    i = 0;
    line = NULL;
    split = NULL;
    get_next_line(fd, &line);
    e->nb_sprites = ft_atoi(line);
    sprites = malloc(sizeof(*sprites) * e->nb_sprites);
    get_next_line(fd, &line);
    while (ft_strcmp(line, "end") != 0)
    {
	sprites[i] = malloc(sizeof(**sprites));
	split = ft_strsplit(line, ' ');
	sprites[i]->posx = ft_atoi(split[1]) + 0.5;
	sprites[i]->posy = ft_atoi(split[2]) + 0.5;
	sprites[i]->savex = sprites[i]->posx;
	sprites[i]->savey = sprites[i]->posy;
	ft_get_sprite_info(sprites[i], ft_strjoin(e->path, split[0]));
	get_next_line(fd, &line);
	i++;
    }
    return (sprites);
}
