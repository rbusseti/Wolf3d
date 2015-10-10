#include "get_next_line.h"

static int	ft_check_end(char *buff)
{
    int		i;

    i = 0;
    while (buff[i])
    {
	if (buff[i] == '\n')
	    return (i);
	i++;
    }
    return (-1);
}

static char	*ft_return_str(char *str, int i)
{
    char	*new;
    int		j;

    j = 0;
    new = malloc(sizeof(char) * i + 1);
    while (str[j] && i > j)
    {
	new[j] = str[j];
	j++;
    }
    new[j] = '\0';
    return (new);
}

static char	*ft_buff_save(char *buff)
{
    static char	*buff_save = NULL;
    char	*temp;
    int		i;

    if (buff_save == NULL && buff != NULL)
	temp = ft_strdup(buff);
    else
	temp = ft_strjoin(buff_save, buff);
    if (buff_save)
    {
	free(buff_save);
	buff_save = NULL;
    }
    if ((i = ft_check_end(temp)) >= 0)
    {
	buff_save = ft_strdup(temp + i + 1);
	return (ft_return_str(temp, i));
    }
    buff_save = ft_strdup(temp);
    return (NULL);
}

int		get_next_line(int const fd, char **line)
{
    char	*buff;
    int		ret;

    if (*line)
    {
	free(*line);
	*line = NULL;
    }
    buff = malloc(sizeof(char) * BUFF_SIZE + 1);
    ft_bzero(buff, BUFF_SIZE);
    while ((ret = read(fd, buff, BUFF_SIZE)) && (ft_check_end(buff)) < 0)
    {
	buff[BUFF_SIZE] = '\0';
	ft_buff_save(buff);
	ft_bzero(buff, BUFF_SIZE);
    }
    *line = ft_buff_save(buff);
    if (ret > 0 || *line)
	return (1);
    else
	return (ret);
}
