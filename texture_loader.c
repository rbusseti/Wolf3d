#include "wolf3d.h"

t_idata *ft_get_img_data(void *img)
{
    t_idata *idata;

    idata = malloc(sizeof(*idata));
    idata->adr = mlx_get_data_addr(img, &(idata->bpp), &(idata->line), &(idata->edian));
    return (idata);
}

t_idata	**ft_load_texture(t_env *e)
{
    int	    width;
    int	    height;
    void    *texture;
    t_idata **tex;

    tex = malloc(sizeof(t_idata*) * 20);

    texture = mlx_xpm_file_to_image(e->mlx, "Ressources/floor.xpm", &width, &height);
    tex[0] = ft_get_img_data(texture);
    free(texture);

    texture = mlx_xpm_file_to_image(e->mlx, "Ressources/wall.xpm", &width, &height);
    tex[1] = ft_get_img_data(texture);
    free(texture);

    texture = mlx_xpm_file_to_image(e->mlx, "Ressources/ceil.xpm", &width, &height);
    tex[2] = ft_get_img_data(texture);
    free(texture);

    texture = mlx_xpm_file_to_image(e->mlx, "Ressources/teleport.xpm", &width, &height);
    tex[3] = ft_get_img_data(texture);
    free(texture);

    texture = mlx_xpm_file_to_image(e->mlx, "Ressources/gun.xpm", &width, &height);
    tex[9] = ft_get_img_data(texture);
    free(texture);

    texture = mlx_xpm_file_to_image(e->mlx, "Ressources/overlay.xpm", &width, &height);
    tex[12] = ft_get_img_data(texture);
    free(texture);

    texture = mlx_xpm_file_to_image(e->mlx, "Ressources/numbers.xpm", &width, &height);
    tex[13] = ft_get_img_data(texture);
    
    return (tex);
}
