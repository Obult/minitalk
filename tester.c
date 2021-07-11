#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int		main(int argc, char ** argv)
{
	if (argv[2][0] == '1')
		kill(atoi(argv[1]), SIGUSR1);
	else
		kill(atoi(argv[1]), SIGUSR2);
	return (0);
}