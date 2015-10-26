#include "wolf3d.h"

t_idata *ft_get_img_data(void *img)
{
    t_idata *idata;

    idata = malloc(sizeof(*idata));
    idata->adr = mlx_get_data_addr(img, &(idata->bpp), &(idata->line), &(idata->edian));
    return (idata);
}

char	**ft_get_texture_name(t_env *e)
{
    char    *line;
    char    **tex_name;
    int	    fd;
    int	    i;

    line = NULL;
    fd = open(ft_strjoin(e->path, "init_tex.txt"), O_RDONLY);
    i = 0;
    get_next_line(fd, &line);
    e->nb_tex = ft_atoi(line);
    tex_name = malloc(sizeof(char *) * e->nb_tex);
    while (i < e->nb_tex)
    {
	get_next_line(fd, &line);
	tex_name[i] = ft_strdup(line);
	i++;
    }
    tex_name[i] = NULL;
    close(fd);
    return (tex_name);
}

t_idata	**ft_load_texture(t_env *e)
{
    int	    w;
    int	    h;
    int	    i;
    void    *texture;
    t_idata **tex;

    e->tex_name = ft_get_texture_name(e);
    tex = malloc(sizeof(t_idata*) * e->nb_tex);
    i = 0;
    while (i < e->nb_tex)
    {
	texture = mlx_xpm_file_to_image\
	    (e->mlx, ft_strjoin(e->path, e->tex_name[i]), &w, &h);
	tex[i] = ft_get_img_data(texture);
	free(texture);
	i++;
    }
    return (tex);
}
