#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>

int main()
{
	int p1[2],p2[2],n;
	char s[80];
	pipe(p1);
	pipe(p2);
	
	n=fork(); // child parent tayar karnya sathi..
	
	if(n!=0)
	{
		close(p1[0]);
		close(p2[1]);
		printf("\n Server -> Hello From Server");
		write(p1[1],"\nHello From Server",20);
		read(p2[0],s,80);
		printf("\nServer Read->%s",s);
	
	}
	else
	{
		close(p1[1]);
		close(p2[0]);
		read(p1[0],s,80);
		printf("\nClient Read->%s",s);
		printf("\n Client -> Hello From Client\n");
		write(p2[1],"\nHello From Client",20);
	}
	return 0;
		
}
