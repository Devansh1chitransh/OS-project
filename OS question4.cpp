
#include <pthread.h>
#include<stdio.h>
 

int a = 0;
 long fibonacci[100]; 
void *runner(void *parameter) 
{ 
if (a <= 0) 
pthread_exit(0); 
fibonacci[0] = 0;
 if (a > 1) 
{ 
fibonacci[1] = 1;
 for (int i = 2; i < a; i++)
 {
 
 fibonacci[i] = fibonacci[i-1] + fibonacci[i-2];
 }
 } 
pthread_exit(0);
 } 
 
int main(int useless, char *arg[]) 
{
 pthread_t fid;
 pthread_attr_t attribute;
 pthread_attr_init(&attribute);
 printf("how many fibonacci number do you want to be printed ");
 scanf("%d", &a);
 if (a > 100)
 {
 printf("Printing ....100  possible maximum\n"); 
a = 100;
 }
 pthread_create(&fid, &attribute, runner, arg[1]); 
pthread_join(fid, NULL);
 if (a > 0)
 printf("%ld", fibonacci[0]);
 for (int i = 1; i < a; i++) 
printf(", %ld", fibonacci[i]);
 printf("\n");
 return 0;
 }
