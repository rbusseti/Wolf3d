#include <math.h>

double	ft_add_angle(double angle1, double angle2)
{
    angle1 = angle1 + angle2;
    if (angle1 < 0)
	angle1 = 360 + angle1;
    else if (angle1 >= 360)
	angle1 = angle1 - 360;
    return (angle1);
}
