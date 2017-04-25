#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#define MAX 150
using namespace std;
class InternetBandwidth{
  private:
    int s,t;
    int n;
    int f[MAX][MAX],pre[MAX],c[MAX][MAX];//c×î´óÖµ   f 
    int ans;
  public:
    void initial(int);
    void readcase();
    void computering();
    void outResult();
};
void InternetBandwidth::initial(int x){
    memset(f,0,sizeof(f));
    memset(c,0,sizeof(c));
    ans=0;
    n=x;
}
void InternetBandwidth::readcase(){
   cin>>s>>t;
   int m;
   int a,b,cap;
   cin>>m;
   for(int i=1;i<=m;i++){
       cin>>a>>b>>cap;
       c[a][b]=c[a][b]+cap;
       c[b][a]=c[b][a]+cap;
   }
   
}
void InternetBandwidth::computering(){
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
           d0=100000000;
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
          //cout<<ans<<endl;
          i=t;
          while(i!=s){
            if(pre[i]>0)  f[pre[i]][i]+=d0;
            else          f[i][-pre[i]]-=d0;
            i=abs(pre[i]);
         }
      }
    }
}
void InternetBandwidth::outResult(){
     static int cnt=1;
     cout<<"Network "<<cnt++<<endl;
     cout<<"The bandwidth is "<<ans<<"."<<endl<<endl;
}
int main(){
   InternetBandwidth d;
   int t;
   while(cin>>t&&t){
     d.initial(t);
     d.readcase();
     d.computering();
     d.outResult();
   }
   //system("pause");
   return 0;
 
}
