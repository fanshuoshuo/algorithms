#include <bits/stdc++.h>
#define maxn 100

using namespace std;
int g[maxn][maxn];
int m,n;
int target;
int diff;
int res;
vector<pair<int,int> >resPath;
void dfs(vector<pair<int,int>>&path,int sum,int x,int y){
    if(x<0 || y>n-1) {
        if(abs(sum-target)<diff){
            diff=abs(sum-target);
            res=sum;
            resPath=path;
        }
        return ;
    }
    path.push_back(pair<int,int>(x,y));
    dfs(path,sum+g[x][y],x,y+1);
    dfs(path,sum+g[x][y],x-1,y);
    path.pop_back();
}

void initial(){
    memset(g,0,sizeof g);
    diff=INT_MAX;
    res=-1;
    target=0;
    resPath.clear();
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
        vector<pair<int,int>>path;
        dfs(path,0,m-1,0);
        cout<<"res="<<res<<endl;
        for(int i=0;i<resPath.size();i++){
            cout<<"("<<resPath[i].first<<"," <<resPath[i].second<<") ";
        }
        cout<<endl;
    }
    return 0;
}
/*测试用例
3 3
1 2 3
4 5 6
7 8 9
33  
*/
