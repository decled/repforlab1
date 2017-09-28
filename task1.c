#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void* func(void *arg)
{
for (int j=1;j<11;j++)
printf("Child Thread:Iteration %d\n",j);
printf("Child sleep\n");
sleep(2);
}
int main(int argc,char **argv)
{
pthread_t thread;
int arg,result;
result=pthread_create(&thread,NULL,&func,NULL);
if (result!=0)
{
fprintf(stderr,"Error\n");
return -1;
}
for (int i=1;i<11;i++)
printf("Main Thread:Iteration %d\n",i);
printf("Parent sleep\n");
sleep(2);
return 0;
}
