#include "wolf3d.h"

t_idata *ft_get_img_data(void *img)
{
    t_idata *idata;

    idata = malloc(sizeof(*idata));
    idata->adr = mlx_get_data_addr(img, &(idata->bpp), &(idata->line), &(idata->edian));
    return (idata);
}

t_tex	*ft_load_texture(t_env *e)
{
    int	    width;
    int	    height;
    void    *texture;
    t_tex   *tex;

    tex = malloc (sizeof(*tex));

    texture = mlx_xpm_file_to_image(e->mlx, "Ressources/wall.xpm", &width, &height);
    tex->wall = ft_get_img_data(texture);
    free(texture);

    texture = mlx_xpm_file_to_image(e->mlx, "Ressources/floor.xpm", &width, &height);
    tex->floor = ft_get_img_data(texture);
    free(texture);

    texture = mlx_xpm_file_to_image(e->mlx, "Ressources/ceil.xpm", &width, &height);
    tex->sky = ft_get_img_data(texture);
    free(texture);

    texture = mlx_xpm_file_to_image(e->mlx, "Ressources/sword.xpm", &width, &height);
    tex->sword = ft_get_img_data(texture);
    return (tex);
}
