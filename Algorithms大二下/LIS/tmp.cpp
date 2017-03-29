
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
int data[ 100000 ]; 
int length[ 100000 ]; 
int front[ 100000 ]; 
int Q[ 100000 ]; 
 
void output( int v ) 
{ 
    if ( front[v] )  
        output( front[v] ); 
    printf("%d\n",data[v]); 
} 
 
int bs( int r, int v ) 
{ 
    int l = 1; 
    while ( l < r ) { 
        int mid = (l+r)>>1; 
        if ( data[Q[mid]] < v ) 
            l = mid+1; 
        else r = mid; 
    } 
    return r; 
} 
 
int main() 
{ 
    int count = 1; 
    while ( scanf("%d",&data[count]) != EOF ) 
        count ++; 
     
    int tail = 0; 
    Q[++ tail] = 1; 
    for ( int i = 2 ; i < count ; ++ i )  
        if ( data[Q[tail]] < data[i] ) { 
            Q[++ tail] = i; 
            front[i] = Q[tail-1]; 
        }else { 
            int id = bs( tail, data[i] ); 
            Q[ id ] = i; 
            front[i] = Q[id-1]; 
        } 
         
    printf("%d\n-\n",tail); 
    output( Q[tail] ); 
    system("pause");
    return 0; 
} 
