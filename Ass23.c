#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>

int main()
{	char s[80];
	int p[2],n;
	pipe(p);
	
	n=fork(); // child parent tayar karnya sathi..
	
	if(n==0)
	{
		close(p[0]);
		close(1);
		dup(p[1]);
		close(p[1]);
		execlp("ls","ls","-l",NULL);
	}	
	else
	{	wait();
		printf("Im in parent");
		while(read(p[0],s,80))
		printf("%s",s);
		exit(n);
	}
	
	return 0;
	
}
