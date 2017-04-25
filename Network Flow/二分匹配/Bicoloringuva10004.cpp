#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
#define MAX  10000
// bfs  µØÍ¼Í¼ÉÏË«É« 
using namespace std;
class Bicoloring{
   private:
      int l,n;
      int color[MAX];
      int unvis[MAX];
      vector< vector<int> > graf;
      bool ans;
   public:
      void initial(int );
      void computering();
      void readcase();
      void outResult();
};
void Bicoloring::initial(int N){
     n=N;
     ans=true;
     graf.clear();
     graf.resize(n);
     memset(color,0,sizeof(color));
}
void Bicoloring::computering(){
     queue<int> q,t;
     int c=1;
     int x;
     q.push(0);
     color[0]=c;
     unvis[0]=0;
     while(!q.empty()){
        x=q.front();
        q.pop();
        c=(color[x]*-1);
     for(int i=0;i<graf[x].size();i++){
            int y=graf[x][i];
            if(color[y]==0){
                color[y]=c;
                q.push(y);
            }
            else if(color[y]!=c){
                ans=false;return ;
            }
        }
     }
     
}
void Bicoloring::readcase(){
     cin>>l;
     int a,b;
     for(int i=0;i<l;i++){
        cin>>a>>b;
        graf[a].push_back(b); 
        graf[b].push_back(a);   
     }
   
}
void Bicoloring::outResult(){
     if(ans)cout<<"BICOLORABLE."<<endl;
     else cout<<"NOT BICOLORABLE."<<endl;
}
int main(){
   Bicoloring b;
   int n;
   while(cin>>n&&n){
      b.initial(n);
      b.readcase();
      b.computering();
      b.outResult();
   }
  // system("pause");
   return 0;
}
