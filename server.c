#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void handler(int signal)
{
	static int i = 0;
	static unsigned char c = 0;

	c <<= 1;
	c += signal == SIGUSR1;
	if (++i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

int main (void)
{
	pid_t pid;
	pid = getpid();

	printf("pid: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		pause();
	}

	return 0;
}