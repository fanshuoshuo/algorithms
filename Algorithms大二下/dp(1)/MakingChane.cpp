//uva  166
//by fan
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cstdio>
#include <cstring>
#include <math.h>
#include <algorithm>
#define MAX   510
using namespace std;
int coin[6]={5,10,20,50,100,200};
class MakingChane{
   private:
      int num[6];
      int value;
      int ans;
      vector<int> change;
      vector<int>  pay;
      vector<int>  visited;
   public :
      void preprocess();
      void initial();
      bool readcase();
      void computering();
      void outResult();
  };
  void  MakingChane::initial(){
        pay.clear();
        change.clear();
       // visited.clear();
       
  }
  bool  MakingChane::readcase(){
     double tmp;
     cin>>num[0]>>num[1]>>num[2]>>num[3]>>num[4]>>num[5];
     if(num[0]==0&&num[1]==0&&num[2]==0&&num[3]==0&&num[4]==0&&num[5]==0) return false;
     cin>>tmp;
     value=(int)round(tmp*100); 
     return true;
        
  }
  void  MakingChane::computering(){
        
  }
  void  MakingChane::outResult(){
     printf("%3d/n",ans);
  }
  void  MakingChane::preprocess(){
    visited.clear();
    visited.resize(MAX);
    change.clear();
    for(int i=0;i<MAX;i++){
       change.push_back(MAX);
    }
    change[0]=0;
    for(int k=0;k<6;k++){
         for(int i=0;i+coin[k]<change.size();i++){
             if(visited[i]){
                  change[i+coin[k]]=min(change[i+coin[k]],change[i+1]);
                  visited[i+coin[k]]=true;
             }
         }
    }
  }
///////////////////////
int main(){
  
   int n0,n1,n2,n3,n4,n5;
   MakingChane  mc;
   mc.preprocess();
   while(mc.readcase()){
      mc.initial();
      mc.computering();
      mc.outResult();
   }
   
   return 0;
}
