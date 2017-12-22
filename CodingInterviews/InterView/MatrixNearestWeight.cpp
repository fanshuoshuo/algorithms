/*
阿里的一道面试题目，
带权重的矩阵，从左下走到右上，给定一个权重
求最接近的路径之和
*/


#include <bits/stdc++.h>
#define maxn 100

using namespace std;
int g[maxn][maxn];
int m,n;     //保存行数和列数 
int target;
int diff;
int res;
void dfs(int sum,int x,int y){
    if(x<0 || y>n-1) {
        if(abs(sum-target)<diff){
            diff=abs(sum-target);
            res=sum;
        }
        return ;
    }
    dfs(sum+g[x][y],x,y+1);
    dfs(sum+g[x][y],x-1,y);
}

void initial(){
    memset(g,0,sizeof g);
    diff=INT_MAX;
    res=-1;
    target=0;
}
int main()
{
    while(cin>>m>>n){
        initial();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>g[i][j];
            }
        }
        cin>>target;
        dfs(0,m-1,0);
        cout<<"res="<<res<<endl;
    }
    return 0;
}
