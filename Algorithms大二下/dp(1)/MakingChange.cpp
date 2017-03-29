//uva 166;
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <cstdio>
#include <cstring>
#include <math.h>
#define MAX 20010
const double eps=0.0000001;
using namespace std;
int coin[6]={5,10,20,50,100,200};
class MakingChange{
 private:
   int  num[6];
   int  value; 
   int  ans;
   int  tender[2010];
   int  change[2010];     
 public :
   void initial();
   bool readcase();
   void computering();
   void outResult();
};
void MakingChange::initial(){
     memset(tender,-1,sizeof(tender));tender[0]=0;
     memset(change,-1,sizeof(change));change[0]=0;
     ans=MAX;
}
bool MakingChange::readcase(){
     double tmp;
     cin>>num[0]>>num[1]>>num[2]>>num[3]>>num[4]>>num[5];
     if(num[0]==0&&num[1]==0&&num[2]==0&&num[3]==0&&num[4]==0&&num[5]==0) return false;
     cin>>tmp;
     value=(int)round(tmp*100); 
     return true;
}
void MakingChange::computering(){
   
   int t;
   for(int i=0;i<6;i++) {
        if(num[i]*coin[i]>MAX){ 
              t= coin[i];                                      // 2 4 2 2 1 0 0.95
              for(int k=t;k<MAX;k++){
                   if(tender[k-t]!=-1&&(tender[k]==-1||tender[k-t]+1<tender[k])){
                       tender[k]=tender[k-t]+1;
                    }
              }                                              //5 10  20 50 100 200
              
        }else{
           while(num[i]--){
              t=coin[i];
              for(int k=MAX;k>=t;k--){
                   if(tender[k-t]!=-1 &&  (tender[k]==-1 || tender[k-t]+1<tender[k]))  
                       tender[k]=tender[k-t]+1; 
              }
           }
        }
        
   }
   for(int i=0;i<6;i++){
      t=coin[i];
      for(int k=t;k<MAX;k++){
          if(change[k-t]!=-1&&(change[k]==-1||change[k-t]+1<change[k])){
              change[k]=change[k-t]+1;
          }
      }
   }
   for(int i=value;i<=MAX;i++)  
       {  
           if(tender[i]!=-1 && change[i-value]!=-1 && ans>tender[i]+change[i-value])  
              ans=tender[i]+change[i-value];          
             
       }  
}
void MakingChange::outResult(){
    printf("%3d/n",ans);   
}
int main(){
   MakingChange mc;
   while(mc.readcase()){
      mc.initial();
      mc.computering();
      mc.outResult();
   }
   return 0;
  // system("pause");
}
