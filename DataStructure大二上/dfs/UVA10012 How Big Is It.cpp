#include <iostream>  
#include <vector>
#include <algorithm>  
#include <cstring>  
#include <cstdlib>  
#include <cstdio>  
#include <cmath>  
using namespace std;  
int vis[8], num;  
double a[8], b[8], d[8], Max;  
void check(int cur) 
{  
    d[cur] = b[cur];  
    double dis1, dis2, dis;  
    for(int i = cur - 1; i >= 0; i--)  
    {  
        dis1 = b[i] + b[cur];  
        dis2 = b[i] - b[cur];  
        dis = d[i] + sqrt(dis1 * dis1 - dis2 * dis2);  
        if(dis > d[cur])  
            d[cur] = dis;  
    }  
}  
void dfs(int cur, double sum) 
{  
    if(sum > Max)  
        return ;  
    if(cur == num)  
    {  
        double l = b[0];  
        sum += b[cur - 1];  
        for(int i = 0; i < num - 1; i++)  
            if(d[i] + b[i] > sum)  
                sum = d[i] + b[i];  
        for(int i = 1; i < num; i++)  
            if(b[i] - d[i] > l)  
                l = b[i] - d[i];  
        sum += l;  
        if(sum < Max)  
            Max = sum;  
        return ;  
    }  
    for(int i = 0; i < num; i++)  
        if(!vis[i])  
        {  
            vis[i] = 1;  
            b[cur] = a[i];  
            check(cur);  
            dfs(cur + 1, d[cur]);  
            vis[i] = 0;  
        }  
}  
int main()  
{ 
    int n;  
    scanf("%d", &n);  
    memset(vis, 0, sizeof(vis));  
    while(n--)  
    {  
        Max = 0x7FFFFFFF;  
        scanf("%d", &num);  
        for(int i = 0; i < num; i++)  
            scanf("%lf", &a[i]);  
        for(int i = 0; i < num; i++)  
        {  
            vis[i] = 1;  
            d[0] = 0;  
            b[0] = a[i];  
            dfs(1, 0);  
            vis[i] = 0;  
        }  
        printf("%.3lf\n", Max);  
    }  
    return 0;  
}  
