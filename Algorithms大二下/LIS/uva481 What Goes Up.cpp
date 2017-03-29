#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <sstream>
using namespace std;
class  WhatGoesUp{
  private:
    vector<int> num;
    int front[50000];
    int p[50000];
    int ans;
  public:
    void initial();
    void readcase();
    void computering();
    void outResult(int);
    int binary(int ,int);
};
int  WhatGoesUp::binary(int r,int v){
    int l=1;
    while(l<r){
       int mid=(l+r)>>1;
       if(num[p[mid]]<v) l=mid+1;
       else r=mid;
    }
    return r;
}
void WhatGoesUp::initial(){
   num.clear();
   num.push_back(0);
   memset(p,0,sizeof(p));
}
void WhatGoesUp::readcase(){
     int tmp;
     while (scanf("%d",&tmp) != EOF ) {
           
        num.push_back(tmp);
        if(num.size()==9) break;
     }
}
void WhatGoesUp::computering(){
    p[1]=1;
    int k=1;
     for(int i=2;i<num.size();i++){
         if(num[i]>num[p[k]]) {
            p[++k]=num[i];// 3   4   8    
            front[i]=p[k-1];
         }
         else {
              int id=binary(k,num[i]);
              p[id]=i;front[i]=p[id-1];
       }
    }
     ans=k;
     cout<<ans<<endl;
     cout<<"-"<<endl;
     cout<<p[k]<<endl;
     outResult(p[k]);
     
}
void WhatGoesUp::outResult(int k){
     if(front[k]){
         outResult(front[k]);
     }
     printf("%d\n",num[k]);
}
int main(){
   WhatGoesUp d;
   d.initial();
   d.readcase();
   d.computering();
   system("pause");
   return 0;
 
}
