#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void send(char c, pid_t pid)
{
	int i;
	i = 128;
	while (i)
	{
		if (c & i)
		{
			if (kill(pid, SIGUSR1) == -1)
			{
				printf("ERROR!");
				exit(0);
			}
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
			{
				printf("ERROR!");
				exit(0);
			}
		}
		i >>= 1;
	}
	usleep(500);
}

int main (int argc, char **argv)
{
	pid_t pid;
	char *message;
	int i;

	i = 0;
	if (argc != 3)
	{
		printf("ERROR\n"); //switch to ft_printf
		exit(0);
	}
	pid = atoi(argv[1]);
	message = argv[2];
	while (message[i])
		send(message[i++], pid);

	return (0);
}
1.
a & b ? do_thing1 : do_thing2

2.
if a & b
	do_thing1
else
	do_thing2