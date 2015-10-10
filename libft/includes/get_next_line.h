#ifndef GET_NEXT_LINE_H

# define GET_NEXT_LINE_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# include "libft.h"

# define BUFF_SIZE 1

int	get_next_line(int const fd, char **line);

#endif
