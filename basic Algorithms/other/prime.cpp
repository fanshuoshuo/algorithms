/*
筛选法求素数
source:http://blog.csdn.net/qq_34739984/article/details/52999528
*/

#include <stdio.h>
#include <math.h>
#define N 10000001
int prime[N];
int main()
{
   int i, j;
   for(i=2; i<N; i++){
    if(i%2) prime[i]=1;      //奇数设置为1 
       else prime[i]=0;      //偶数设置为0
   }
   for(i=3; i<=sqrt(N); i++){   
    if(prime[i]==1)
      for(j=i+i; j<N; j+=i) prime[j]=0;
   }
   for(i=2; i<100; i++)//只输出2-100内的素数
    if( prime[i]==1 )printf("%d ",i);
   printf("\n");

   return 0;
}