#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <queue>
#define MAX 10000
using namespace std;
class  The_Problem_with_the_Problem_Setter{
  private:
    int nk,np;
    vector< vector<int> > graf;
    vector< vector<int> > categories;
    int   link[MAX];
    bool  vis[MAX];
    int   match;
    int  flag;
  public:
     bool crosspath( int );
    void initial(int ,int);
    void readcase();
    void computering();
    void outResult();
};
bool  The_Problem_with_the_Problem_Setter::crosspath(int k){
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
void The_Problem_with_the_Problem_Setter::initial(int x,int y){
   nk=x;
   np=y;
   flag=0;
   graf.clear();
   match=0;
   memset(vis,0,sizeof(vis));
   memset(link,-1,sizeof(link));
}
void The_Problem_with_the_Problem_Setter::readcase(){
   int z;
   int num;
   int count=1;
   categories.resize(nk+1);
   for(int i=1;i<=nk;i++)    {  // 
       cin>>z;
       flag+=z;
       for(int k=0;k<z;k++){
             categories[i].push_back(count++);
       }
   }
   graf.resize(count);
   for(int i=1;i<=np;i++ ){
      cin>>num;
      for(int j=0;j<num;j++){
         cin>>z;
         for(int k=0;k<categories[z].size();i++){
             int x=categories[z][k];
             graf[x].push_back(i);
         }
      }
   }
}
void The_Problem_with_the_Problem_Setter::computering(){
   for (int i=0;i<graf.size();i++){
         if (crosspath(i)){
             match++;
             memset(vis,0,sizeof(vis));
    	}
    }
   if(match==flag)
     cout<<"1"<<endl;
     else 
       cout<<"0"<<endl;
}

void The_Problem_with_the_Problem_Setter::outResult(){
     
}
int main(){
    int nk,np;
    The_Problem_with_the_Problem_Setter d;
    while(cin>>nk>>np){
     if(np==0&&nk==0) break;
     d.initial(np,nk);
     d.readcase();
     d.computering();
     d.outResult();
   }
   system("pause");
   return 0;
 
}
