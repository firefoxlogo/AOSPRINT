#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>
#include<signal.h>

void Sh(int);
int main()
{
	signal(SIGINT,Sh);
	while(1)
	{
	
	
	}
	return 0;
}

void Sh(int n)
{
	if(n==SIGINT)
	{
		printf("\n Cnt+C Pressed");
		fflush(stdout);
		signal(SIGINT,SIG_DFL);
	
	}
}
