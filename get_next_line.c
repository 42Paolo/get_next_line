#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

#include <stdio.h>
#include <stdlib.h>

char *substring_before_char(const char *str, char delim)
{
    if (!str)
        return NULL;
    const char *ptr = str;
    int len = 0;
    while (ptr[len] && ptr[len] != delim)
        len++;
    char *result = malloc(len + 1);
    if (!result)
        return NULL;
    int i = 0;
    while (i < len)
    {
        result[i] = str[i];
        i++;
    }
    result[i] = '\0';
    return result;
}

int ft_strlen(char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}



char *get_next_line(int fd)
{
	static char *str;
	char		*read_str;
	int			len_resto;
	if (fd < 0)
		return (NULL);
	str = (char *)malloc(sizeof(char *) * (BUFFER_SIZE));
	len_resto = ft_strlen(str);
	read(fd, read_str, BUFFER_SIZE - len_resto);

}

int main(void)
{
    int fd;
    char *line;
    const char *filename = "test.txt";

    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("Error opening file");
        return 1;
    }
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}