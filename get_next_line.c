#include <stdlib.h>
#include <unistd.h>

int	fill_buff(int fd, char **buff, int buff_size)
{
	int	i;

	i = read(fd, buff, buff_size);
	if (!i)
		*buff = NULL;
	return (i);
}

int	look4endl(char *buff, int buff_size, int b_read)
{
	int	i;

	i = 0;
	if (buff == NULL)
		return (-1);
	while (i < buff_size && i < b_read && buff[i] != '\n')
		i++;
	return (i);
}

int	save_in_ret(char *ret, char *buff, int buff_size, int ret_size)
{
	char	*aux;
	int		i;
	int		j;

	if(buff_size == -1)
		return 1;
	aux = malloc((ret_size + buff_size) * sizeof(char));
	if(!aux)
		return (0);
	i = 0;
	j = 0;
	while (i < ret_size)
	{
		aux[i] = ret[i];
		i++;
	}
	while (i - ret_size < buff_size)
	{
		aux[i] = ret[j];
		i++;
		j++;
	}
	free_mem(ret, ret_size);
	ret = aux;
	return 1;
}

void	free_mem(char *ptr, int ptr_size)
{
	int i;

	i = 0;
	while (i < ptr_size)
	{
		ptr[i] = 0;
		i++;
	}
	free(ptr);
}
//problemas en principio cuando el buffer se queda lleno de cosas
//de la siguiente linea

// tener en cuenta que si se lee entero pero se encuentro un \n antes
// i sera distinto del valor de i retornado anteriormente a si que
// igual lo puedo guardar en algun sitio para comprobarlos y ver si hago algo con
// esto no se la verdad
char	*get_next_line(int fd)
{
	static int	i;
	static int	buff_size;
	static char	*buff;
	static char	*ret;
	static int	ret_size;

#ifdef BUFFER_SIZE
	buff_size = BUFFER_SIZE;
#else
	buff_size = 42;
#endif
	buff = malloc(buff_size * sizeof(char));
	ret_size = 0;
	i = buff_size;
	ret = NULL;
	while (i == buff_size)
	{
		i = fill_buff(fd, &buff, buff_size);
		i = look4endl(buff, buff_size, i);
		if(!save_in_ret(ret, buff, i, ret_size))
			return NULL;
	}
	return (ret);
}
