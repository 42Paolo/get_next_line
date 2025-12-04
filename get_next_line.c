#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

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
	char		*str_ret;
	char		*ptr_start;
	char		*ptr_tmp;
	int			len_resto;

	if (fd < 0)
		return (NULL);
	str = (char *)malloc(sizeof(char *) * (BUFFER_SIZE));
	str[BUFFER_SIZE] = '\0';
	ptr_start = str;
	ptr_tmp = ptr_start;
	len_resto = ft_strlen(str);
	//ricopiare il resto di str all'inizio di str cosicche poi si possa copiare subito dopo con il read il resto dei caratteri che devo copiare. 
	while (len_resto > 0)
	{
		ptr_tmp = str;
		ptr_tmp++;
		str++;
		len_resto--;
	}
	read(fd, ptr_tmp, BUFFER_SIZE - len_resto);
	//fare la substring della stringa fino a \n, \n compreso, se non ce alcun \n comunque returnare la stringa completa, il tutto dovra essere copiato all'interno di str_ret
	//ovviamente bisogna capire come gestire il puntatore di str, sono abbastanza convinto che bisogna mandarlo avanti, quindi alla funzione di substr dovremo passarlo con & 
	// anche perche senno poi il calolo del reto non ci sara mai alla chiamata dopo.
	//la stringa finale da returnare e str_ret che sara la substr.
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