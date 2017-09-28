#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

struct param
{
int num;
char *name;
char *str;
};
struct param p1,p2,p3,p4;
void makeparam()
{
p1.num=1;
p2.num=2;
p3.num=3;
p4.num=4;
p1.name="thread1";
p2.name="thread2";
p3.name="thread3";
p4.name="thread4";
p1.str="First thread";
p2.str="Second thread";
p3.str="Third thread";
p4.str="Fourth thread";
}
void *func(void *arg)

{struct param targ=*(struct param*) arg;
if(targ.num<1)
{
printf("it is impossible to write");
}
else{
for (int i=1;i<targ.num+1;i++)
printf("Name of thread:%s, str:%s, num:%d\n",targ.name,targ.str,i );
}
sleep(1);
}
int main(int argc,char **argv)
{
pthread_t thread1,thread2,thread3,thread4;
int result1,result2,result3,result4;
makeparam();
result1=pthread_create(&thread1,NULL,&func,&p1);
result2=pthread_create(&thread2,NULL,&func,&p2);
result3=pthread_create(&thread3,NULL,&func,&p3);
result4=pthread_create(&thread4,NULL,&func,&p4);
if((result1!=0)||(result2!=0)||(result3!=0)||(result4!=0))
{
fprintf(stderr,"Error\n");
return 1;
}
while(1);
}
