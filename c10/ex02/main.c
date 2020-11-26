#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/errno.h>
#include <libgen.h>


void	ft_tail_one(void)
{
	char	buf[1];

	while (1)
		read(0, buf, 1);
}

int		main(int argc, char **argv)
{
	if (argc == 1)
		ft_tail_one();

	return (0);
}
