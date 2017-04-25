#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
struct point{
   int x,y;
   int  color;
   int dir;
   int time;
};
point p[600];
class  TheMonocycle {
  private:
    int M,N;
    vector<string>  grid;
    bool mark[30][30][4];
    int s[2];
    int t[2];
    int ans;
  public :
     void initial(int,int  );
     void read();
     void computering();
     void outResult();
     void bfs();
     int seekColor(int );
     int turnl(int );
     int turnr(int );        
};
 void TheMonocycle::initial(int m,int n){
      M=m;
      N=n;
      grid.clear();
      grid.resize(M);
      memset(mark,true,sizeof(mark));
      int ans=0;
 }
 void  TheMonocycle::read(){
    string  s;
    for(int i=0;i<M;i++){
       cin>>s;
       grid[i]=s;
    }
    
 }
 void  TheMonocycle::computering(){
    int dx[]={0,1,0,-1};
    int dy[]={1,0,-1,0};
    for(int i=0;i<M;i++){
        for(int k=0;k<N;k++){
          if(grid[i][k]=='S'){
             s[0]=i;
             s[1]=k;
          }
           if(grid[i][k]=='T'){
             t[0]=i;
             t[1]=k;
          }
        }
                       
    }
  //  system("pause");
    queue<point> q;
    point pt;
    p[0].x=s[0];
    p[0].y=s[1];
    p[0].color=1;
    p[0].dir=0;
    p[0].time=0;
    q.push(p[0]);
    mark[s[0]][s[1]][0]=false;
    //
    cout<<s[0]<<s[1]<<endl;
    system("pause");
    while(!q.empty()){
        pt = q.front();
        q.pop();
        if(pt.x==t[0]&&pt.y==t[1]&&pt.color==1){
              ans=pt.time;
              break;
        }else{
             point k;
             int x=pt.x+dx[pt.dir];
             int y=pt.y+dy[pt.dir];
             if(mark[x][y][pt.dir]&&x>=0&&y>=0&&x<M&&y<N){
                  k.x=x;k.y=y;k.color=seekColor(pt.color);
                  k.time=pt.time+1;
                  k.dir=pt.dir;
                  q.push(k);
                  mark[x][y][pt.dir]=false;
             }
             x=pt.x;y=pt.y;
             int l=turnl(pt.dir);
             int r=turnr(pt.dir);
             if(mark[x][y][l]&&x>=0&&y>=0&&x<M&&y<N&&grid[x][y]!='#'){
                  k.x=x;k.y=y;k.color=pt.color;
                  k.time=pt.time+1;
                  k.dir=l;
                  q.push(k);
                  mark[x][y][pt.dir]=false;
             }
             if(mark[x][y][r]&&x>=0&&y>=0&&x<M&&y<N&&grid[x][y]!='#'){
                  k.x=x;k.y=y;k.color=pt.color;
                  k.time=pt.time+1;
                  k.dir=r;
                  q.push(k);
                  mark[x][y][pt.dir]=false;
             }
        }
    }  
     
 }
 int TheMonocycle::seekColor(int x){
     if(x==5)  return 1;
     return x+1;
 }
 void TheMonocycle::bfs(){
      
 }
  void  TheMonocycle::outResult(){
        static int cnt=1;
        if(cnt!=1)
          cout<<endl;
        cout<<"Case #"<<cnt<<endl;
        if(ans==0){
          cout<<"destination not reachable"<<endl;
        }
        else{ 
           cout<<"minimum time = "<<ans<<" sec"<<endl;
        }
 }
  int TheMonocycle::turnl(int x){
      if(x==0)  return 3;
      else return x-1;
 }
  int TheMonocycle::turnr(int x){
    if(x==3)  return 0;
    return x+1;
 }  
int main(){
  TheMonocycle p;
  int m,n;
  while(cin>>m>>n){
     if(m==0&&n==0)
        break;
     p.initial(m,n);
     p.read();
     p.computering();
     p.outResult();
  }
  system("pause");
  return 0;
}
