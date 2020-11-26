#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/errno.h>
#include <libgen.h>

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

void		ft_cat(int argc, char **argv)
{
	int		i;
	int		fd;
	char	buf[1];

	i = 1;
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1 && errno == 2)
		{
			ft_putstr(basename(argv[0]));
			ft_putstr(": ");
			ft_putstr(argv[i]);
			ft_putstr(": ");
			ft_putstr(strerror(errno));
			ft_putstr("\n");
		}
		else
		{
			while (read(fd, buf, 1))
				write(1, buf, 1);
			close(fd);
		}
		++i;
	}
}

int			main(int argc, char **argv)
{
	int		i;


	// ft_putstr(strerror(2));
	i = 1;
	if (argc == 1 || (argv[1][0] == '-' && argv[1][1] == 0)
				|| (argv[1][0] == '-' && argv[1][1] == '-' && argv[1][2] == 0))
		ft_cat_one();
	ft_cat(argc, argv);
	return (0);	
}
