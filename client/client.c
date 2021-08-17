#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "utils.h"

void    encode(int pid, unsigned char msg)
{
    int i;
 
    i = 8;
    while(i)
    {
        i--;
        if (msg % 2 == 1)
		{
		    kill(pid, SIGUSR1);
		}
        else
		{
            kill(pid, SIGUSR2);			
		}
		usleep(200);
        msg = msg >> 1;
    }
}

int		main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc != 3)
	{
		write(1, "Only two arguments alowed, PID then msg\n", 40);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	while (argv[2][i])
	{
		encode(pid, argv[2][i]);
		i++;
	}
    encode(pid, '\0');
}