#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#define MAX 405
const int INF = 0x3f3f3f3f;
using namespace std;
class APlugForUNIX {
  private:
    int s,t;
    int n;
    int m;
    map<string,int> Map;
   int f[MAX][MAX],pre[MAX],c[MAX][MAX];
    int ans;
  public:
    void initial();
    void readcase();
    void computering();
    void outResult();
};
void APlugForUNIX::initial(){
    memset(f,0,sizeof(f));
    memset(c,0,sizeof(c));
    ans=0;
    n=2;
    s=1;t=2;
    Map.clear();
}
void APlugForUNIX::readcase(){
    int x;
    cin>>x;
    for(int i=1;i<=x;i++){
       string str;
       cin>>str;
       if (!Map[str]) Map[str] = ++n;
       int v = Map[str]; c[s][v]++;
    } 
    cin>>m;
    for(int i=1;i<=m;i++){
      string str,ss;
      cin>>str>>ss;
      if (!Map[ss]) Map[ss] = ++n;
      int u = Map[ss];
      c[u][t]++;
    }
    cin>>x;
    for (int i = 1; i <= x; i++){
            string str1, str2;
            cin>>str1>>str2;
            if (!Map[str1]) Map[str1] = ++n;
            if (!Map[str2]) Map[str2] = ++n;
            int v = Map[str1], u = Map[str2];
            c[u][v] = INF;
    }
      
}
void APlugForUNIX::computering(){
    int i,d0;
    pre[t]=1;
    while(pre[t]!=0){
        queue<int> q;
        memset(pre,0,sizeof(pre));
        q.push(s);
        pre[s]=s;
        while(!q.empty()&&pre[t]==0){
             int k=q.front();
             q.pop();
             for(int j=1;j<=n;j++){
                  if(pre[j]==0){
                      if(f[k][j]<c[k][j]){
                          pre[j]=k;
                          q.push(j);
                      }else{
                           if(f[j][k]>0){
                                 pre[j]=-k;
                                 q.push(j);
                           }
                      }
                  }
             }
        }
        
        if(pre[t]!=0){
           d0=INF+100;
           i=t;
           while(i!=s){
               if(pre[i]>0){
                    int d=c[pre[i]][i]-f[pre[i]][i]; 
                    if(d<d0)  d0=d;
               }else{
                   if(f[i][-pre[i]]<d0){
                       d0=f[i][-pre[i]]<d0;
                   }
               }
               i=abs(pre[i]);
           }
        
          ans+=d0;
          i=t;
          while(i!=s){
            if(pre[i]>0)  f[pre[i]][i]+=d0;
            else          f[i][-pre[i]]-=d0;
            i=abs(pre[i]);
         }
      }
    }
}
void APlugForUNIX::outResult(){
   cout<<m-ans<<endl;
}
int main(){
   APlugForUNIX d;
   int t;
   cin>>t;
   while(t--){
     d.initial();
     d.readcase();
     d.computering();
     if(t) cout<<endl;
     d.outResult();
   }
   return 0;
 
}
