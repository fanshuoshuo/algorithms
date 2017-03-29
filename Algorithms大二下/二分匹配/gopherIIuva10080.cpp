#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#include <sstream>
#define MAX 10000
using namespace std;
double computeringDis(double x1,double x2,double y1,double  y2){
   
   return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)  );
}
class GopherII{
  private:
    int n,m,s,v;
    int match;
    vector< vector<int> > graf;
    double dis;
    int link[MAX];
    bool vis[MAX];
  public:
    void initial(int ,int ,int ,int);
    void readcase();
    void computering();
    void outResult();
    bool crosspath(int k);
};
bool GopherII::crosspath(int k){
    for (int  i=0;i<graf[k].size();i++){
		int j=graf[k][i];
		if (!vis[j])
		{
			vis[j]=true;
			if (link[j]==-1 || crosspath(link[j]))
			{
				link[j]=k;
				return true;
			}
		}
	}
	return false;
}
void GopherII::initial(int n,int m,int s,int v){
     this->n=n;
     this->m=m;
     this->s=s;
     this->v=v;
     dis=s*v;
     graf.clear();
     graf.resize(n);
     match=0;
     memset(vis,0,sizeof(vis));
     memset(link,-1,sizeof(link));
}
void GopherII::readcase(){
    double x,y;
    double gopher[1000][2];
    double hole[1000][2];
    for(int i=0;i<n;i++){
       cin>>gopher[i][0]>>gopher[i][1];
    }
    for(int i=0;i<m;i++){
       cin>>hole[i][0]>>hole[i][1];
    }
    const double eps=1e-10;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( computeringDis(gopher[i][0],hole[j][0],gopher[i][1],hole[j][1])<=(double)dis ) {
                 graf[i].push_back(j);
            }
        }
    }
  
}
void GopherII::computering(){
for (int i=0;i<n;i++){
         if (crosspath(i)){
             match++;
             memset(vis,0,sizeof(vis));
    	}
    }
    cout<<n-match<<endl;
}
void GopherII::outResult(){
     
}
int main(){
   GopherII d;
   int n,m,s,v;
   while(cin>>n>>m>>s>>v){
     d.initial(n,m,s,v);
     d.readcase();
     d.computering();
     d.outResult();
   }
   system("pause");
   return 0;
 
}
