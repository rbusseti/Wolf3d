#include <stdio.h>
#include "wolf3d.h"
#include "update.h"

void	print_struct(t_ray ray)
{
    printf("firstx: %f \n", ray.firstx);
    printf("firsty: %f \n", ray.firsty);
    printf("gapx: %f \n", ray.gapx);
    printf("gapy: %f \n", ray.gapy);
    printf("dist: %f \n\n", ray.dist);
}
