#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <libgen.h>
#include <string.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}


void	ft_tail_one(void)
{
	char	buf[1];

	while (1)
		read(0, buf, 1);
}

void	ft_run(int argc, char **argv)
{
	int		i;
	int		fd;
	int		size;
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
			size = 0;
			while (read(fd, buf, 1))
				++size;
		}
		
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_tail_one();
	else
		ft_run(argc, argv);
	ft_putstr("hao\n");

	return (0);
}
