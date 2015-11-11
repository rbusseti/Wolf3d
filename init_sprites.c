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

int    ft_get_sprites(t_sprite **sprites, char *line, int i, int x)
{
    int	    y;

    y = 0;
    while (line[y] != '\0')
    {
	if (line[y] == '4')
	{
	    sprites[i] = malloc(sizeof(**sprites));
	    sprites[i]->posx = x + 0.5;
	    sprites[i]->posy = y + 0.5;
	    sprites[i]->savex = sprites[i]->posx;
	    sprites[i]->savey = sprites[i]->posy;
	    ft_get_sprite_info(sprites[i], "Ressources/triso");
	    i = i + 1;
	    ft_putnbr(i);
	    ft_putchar('\n');
	}
	y++;
    }
    return (i);
}

t_sprite    **ft_init_sprites(char *map_name, t_env *e)
{
    t_sprite	**sprites;
    char	*line;
    int		fd;
    int		i;
    int		x;

    i = 0;
    x = 0;
    line = NULL;
    fd = open(ft_strjoin(e->path, map_name), O_RDONLY);
    ft_putendl("avant get");
    get_next_line(fd, &line);
    ft_putendl("apres get");
    e->nb_sprites = ft_atoi(line);
    sprites = malloc(sizeof(*sprites) * e->nb_sprites);
    ft_putendl("apres malloc");
    while (get_next_line(fd, &line))
    {
	i = ft_get_sprites(sprites, line, i, x);
	x++;
    }
    close(fd);
    return (sprites);
}
