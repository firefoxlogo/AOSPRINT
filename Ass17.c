#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<dirent.h>
#include<string.h>

void b1(void);
void b2(void);
void b3(void);

int main()
{
	printf("\n I'm in main");
	atexit(b1);
	atexit(b2);
	atexit(b1);
	atexit(b3);
	printf("\n I'm out from main");
	return 0;
}

void b1(void)
{
	printf("\n I'm b1");
}
void b2(void)
{
	printf("\n I'm b2");
}
void b3(void)
{
	printf("\n I'm b3");
}
