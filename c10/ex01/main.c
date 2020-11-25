#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/errno.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_cat_one(void)
{
	char	buf[1];

	while (1)
	{
		read(0, buf, 1);
		write(1, buf, 1);
	}
}

int		ft_cat(char *cont)
{
	int		fd;
	char	buf[1];

	if ((fd = open(cont, O_RDONLY)) == -1)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	else
	{
		while (read(fd, buf, 1))
			write(1, buf, 1);
		close(fd);
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		i;


	ft_putstr(strerror(2));
	i = 1;
	if (argc == 1 || (argv[1][0] == '-' && argv[1][1] == 0)
				|| (argv[1][0] == '-' && argv[1][1] == '-' && argv[1][2] == 0))
		ft_cat_one();
	else
	{
		while (i < argc)
		{
			if (ft_cat(argv[i]) == -1)
				return (0);
			++i;
		}
	}
	return (0);	
}
