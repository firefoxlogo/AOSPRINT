#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<setjmp.h>
static jmp_buf b;
static int gint;
void f1(int,int,int,int);
void f2();
int main()
{
int aint;
static int sint;
volatile int vint;
register int rint;
gint=1;
aint=2;
sint=3;
vint=4;
rint=5;
printf("\n Before long jmp");
printf("\ngint=%d\taint=%d\tsint=%d\tvint=%d\trint=%d",gint,aint,sint,vint,rint);
if(setjmp(b)!=0)
{
printf("\n after longjmp");
printf("\ngint=%d\taint=%d\tsint=%d\tvint=%d\trint=%d",gint,aint,sint,vint,rint);
exit(0);
}
printf("\nupdating values");
gint=91;
aint=92;
sint=93;
vint=94;
rint=95;
f1(aint,sint,vint,rint);
return 0;
}
void f1(int a,int b,int c,int d)
{
printf("\n in f1");
printf("\ngint=%d\taint=%d\tsint=%d\tvint=%d\trint=%d",gint,a,b,c,d);
f2();
}
void f2()
{
longjmp(b,1);
}
