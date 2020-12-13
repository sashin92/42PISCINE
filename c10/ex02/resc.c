// 허용함수 : close, open, read, write, malloc, free, strerror, basename
#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <string.h>
#include <sys/errno.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_stdout(void)
{
	char	buf[1];

	while (1)
		read(0, buf, 1);
}

void	ft_error_one(char **argv)
{
	ft_putstr("usage: ");
	ft_putstr(basename(argv[0]));
	ft_putstr(" [-F | -f | -r] [-q] [-b # | -c # | -n #] [file ...]\n");
}

void	ft_error_two(char **argv, int idx)
{
	ft_putstr(basename(argv[0]));
	ft_putstr(": ");
	ft_putstr(argv[idx]);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

void	ft_error_three(char **argv)
{
	ft_putstr(basename(argv[0]));
	ft_putstr(": illegal offset -- ");
	ft_putstr(argv[2]);
	ft_putstr("\n");
}

int		ft_isnum(char *str)
{
	while (*str)
	{
		if (*str >= '0' && *str <= '9')
			++str;
		else
			return (1);
	}
	return (0);
}

int		ft_run(int argc, char **argv)
{
	int		fd;
	int		idx;
	char	buf[1];

	idx = 3;
	if (argc == 2)
		ft_error_one(argv);
	if (argc == 3)
	{
		if (ft_isnum(argv[2]))
			ft_error_three(argv);
		else
			ft_stdout();
	}
	while (idx < argc)
	{
		if ((fd = open(argv[idx], O_RDONLY)) < 0)
		{
			ft_error_two(argv, idx++);
			continue ;
		}
		while (read(fd, buf, 1)) // 이제 숫자를 읽어 그 크기만큼 할당한 후 뒷쪽 것들을 읽어낸다.
			write(1, buf, 1);
		++idx;

		close(fd);
	}

	return (1);
}


int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_stdout();
	else if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] ==0)
		ft_run(argc, argv);

	return (0);
}
