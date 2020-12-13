#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <libgen.h>
#include <string.h>

int		ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (0);
	return (1);
}

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

int		ft_atoi(char *str)
{
	int		i;
	int		val;

	i = 0;
	val = 0;
	// while (ft_isspace(str[i] == 0)) isspace검사를 할 필요가 없네
	// 	++i;
	while (str[i] >= '0' && str[i] <= '9')
	{
		val = val*10 + str[i] - '0';
		++i;
	}
	if (str[i] != 0 || i == 0)
	{
		//오류 : illegal offset
		return(0);
	}
	return(val);
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
		write(1, &size, 1);
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 1 || (argc == 2 && (argv[1][0] == '-' &&
						argv[1][1] == '-' && argv[1][2] == 0)))
		ft_tail_one();
	if (argv[1][0] == '-' && argv[1][1] == 'c' && argv[1][2] == 0) // 캐릭터가 숫자인지 확인하고, atoi
	{
		
	}
		ft_run(argc, argv);
	ft_putstr("\n\nhao\n");

	return (0);
}
