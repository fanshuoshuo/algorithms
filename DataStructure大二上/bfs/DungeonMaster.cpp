#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;
struct LRC{
    int l;
    int r;
    int c;
    LRC(int a = 0, int b = 0,int c=0){l=a;r=b;this->c=c;}
    bool friend operator == (LRC a, LRC b) {return (a.r == b.r) && (a.c == b.c)&&(a.l==b.l); }
};
const int size = 32;
class DungeonMaster{
private:
    int L;
    int R;
    int C;
    int result;
    LRC  start;
    LRC  end;
    int   cuboid[size][size][size];
public:
    void initial();
    bool readData();
    void computing();
    void outResult();
};
void  DungeonMaster::initial(){
    
}
bool DungeonMaster::readData(){
    char s;
    if( cin>>L>>R>>C&&C&&L&&R){
         for(int i=0;i<L;i++){
	        for(int j=0;j<R;j++){
	           for(int k=0;k<C;k++){
	               cin>>s;
	               if(s=='.')     cuboid[i][j][k]=-1;
	               else if(s=='#')  cuboid[i][j][k]=10000;
	               else if(s=='S')  {cuboid[i][j][k]=0;start=LRC(i,j,k);}
	               else if(s=='E')   {cuboid[i][j][k]=-1;end=LRC(i,j,k);}
	           }
	        char ch=cin.get();
	        }
	     }  
		    return true;
	 }
    return false;
    
}
void DungeonMaster::computing(){//BFS
    const int dl[6] = {-1,1,0,0,0,0};
    const int dr[6] = {0,0,1,-1,0,0};
    const int dc[6] = {0,0,0,0,1,-1};   
    LRC s, ns;
    queue<LRC> q;
    q.push(start);
    while (!q.empty()){
        s = q.front();
        q.pop();
        if (s == end){
            break;
        }else{
            for(int i = 0; i < 6; i++){
                ns = LRC(s.l + dl[i], s.r+ dr[i],s.c+ dc[i]);
                if((0 <= ns.r) && (ns.r <R ) && (0 <= ns.c) && (ns.c < C) && (0 <= ns.l) && (ns.l < L)){
                    if(cuboid[ns.l][ns.r][ns.c]<0){
 
                        cuboid[ns.l][ns.r][ns.c] = cuboid[s.l][s.r][s.c]+1;
                        q.push(ns);
                      
                     }
                }
            }
        }
    }
}
void DungeonMaster::outResult(){
  if(cuboid[end.l][end.r][end.c]!=-1)
  printf("Escaped in %d minute(s).\n",cuboid[end.l][end.r][end.c]);
  else{
   printf("Trapped!\n");
  }
}
int main(){
   DungeonMaster dm;
    while (dm.readData()){
        dm.initial();
        dm.computing();
        dm.outResult();
    }
    return 0;
}

