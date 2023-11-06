#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
	char a1[]="Atharav NIjampurkar";
	char a2[]="H.V.Desai,pune";
	int fd;
	fd=open("a1.txt",O_WRONLY|O_TRUNC|O_CREAT,0666);
	write(fd,a1,20);
	lseek(fd,100,SEEK_CUR);
	write(fd,a2,15);
	close(fd);
	return 0;
}
