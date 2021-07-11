#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

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
			// write(1, "1\n", 2);
		}
        else
		{
            kill(pid, SIGUSR2);			
			// write(1, "0\n", 2);
		}
		usleep(20);
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
	pid = atoi(argv[1]);
	// encode(pid, 'h');
	while (argv[2][i])
	{
		encode(pid, argv[2][i]);
		i++;
	}
    encode(pid, '\0');
}