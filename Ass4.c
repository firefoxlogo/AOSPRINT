#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
 int main()
 {
 	char s[100];
 	int fd;
 	printf("\n Enter file name");
 	scanf("%s",&s);
 	fd=open(s,O_RDONLY);
 	if(fd<0)
 		printf("File not present");
 	else
 		printf("File is present");
 		
 	close(fd);
 	return 0;
 }
