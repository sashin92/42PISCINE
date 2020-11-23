#include <unistd.h>
#include <fcntl.h>

void    ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	write(1, &str[i++], 1);
}

int     main(int argc, char **argv)
{
	int		fd;
	char	buf[1];

	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else
	{
		if ((fd = open(argv[1], O_RDONLY)) == -1)
			ft_putstr("Cannot read file.\n");
		else
		{
			while (read(fd, buf, 1))
				write(1, &buf[0], 1);
		}
		return (0);
	}
	return (0);
}