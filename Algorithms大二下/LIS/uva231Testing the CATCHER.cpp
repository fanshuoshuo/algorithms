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
class TestingtheCATCHER{
  private:
    vector<int>  num;
    int len[1000];
    int ans;
  public:
    void initial();
    bool readcase();
    void computering();
    void outResult();
    int binary(int ,int);
};
int TestingtheCATCHER::binary(int i,int k){
    if(num[i]>len[1])  return 1;
    int j,h;
    for( h=1,j=k;h!=j-1;){
         if(len[k=(h+j)/2]>=num[i])  h=k;
         else  j=k;
    }  
    return j;
}
void TestingtheCATCHER::initial(){
   num.clear();
   memset(len,0,sizeof(len));
}
bool TestingtheCATCHER::readcase(){
   initial();
   int a;
   cin>>a;
   if(a==-1) return false;
   num.push_back(a);
   while(cin>>a&&a!=-1) num.push_back(a);
   return true;
   
}
void TestingtheCATCHER::computering(){
     len[1]=num[0];
     int k=1;
     for(int i=1;i<num.size();i++){
         if(num[i]<=len[k])  len[++k]=num[i];
         else len[binary(i,k)]=num[i];
     }
    ans=k;
   
}
void TestingtheCATCHER::outResult(){
     static int cnt=1;
     cout<<"Test #"<<cnt++<<":"<<endl;
     cout<<"  maximum possible interceptions: "<<ans<<endl;
}
int main(){
   TestingtheCATCHER d;
   int t=0;
   while(d.readcase()){
     d.computering();
     if(t++) cout<<endl;
     d.outResult();
   }
   system("pause");
   return 0;
 
}
