#include <unistd.h>
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include "utils.h"

t_decoding  msg;
char unsigned string[] = "\0\0\0\0\0\0\0\0\0\0\0\0\0";
 
void    sig_handler(int signum, siginfo_t *info, void *q)
{
	info = 0;
	q = 0;
	info++;
	q++;


    msg.string[msg.i] = (msg.string[msg.i] >> 1);
    if (signum == SIGUSR1)
	{
        msg.string[msg.i] += 128;
	}
    msg.j++;


// check if char is complete and if that is 0 message is complete
    if (msg.j == 8)
    {
		if (!msg.string[msg.i])
		{
		    write(1, msg.string, ft_strlen(msg.string));
			write(1, "\n", 1);
			msg.i = -1;
		}
        msg.i++;
        msg.j = 0;
    }
}
 
int     main(void)
{
    struct sigaction   act, act2;
    pid_t   pid;

	msg.j = 0;
	msg.i = 0;
    msg.string = string;
 
    act.sa_sigaction = sig_handler;
    act.sa_flags = SA_SIGINFO;
 
    act2.sa_sigaction = sig_handler;
    act2.sa_flags = SA_SIGINFO;
 
    pid = getpid();
	write(1, "pid = ", 6);
	ft_putnbr(pid);
	write(1, "\n", 1);
 
    sigaction(SIGUSR1, &act, 0);
    sigaction(SIGUSR2, &act2, 0);
	while (1)
		sleep(1);
 
    return (0);
}

