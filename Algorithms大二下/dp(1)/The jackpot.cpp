#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
class Thejackpot{
   private:
      int n;
      int s;
      int maxn;
      vector<int> v;
   public:
      void initial(int);
      void readcase();
      void computering();
      void outResult();
           
};
void Thejackpot::initial(int x){
     n=x;
     maxn=0;
     v.clear();
}
void Thejackpot::readcase(){
     int a;
     
     for(int i=0;i<n;i++){
         cin>>a;
         v.push_back(a);
     }
}
void Thejackpot::computering(){
     maxn=0;
     int tmp;
     tmp=0;
     for(int i=0;i<v.size();i++){
        tmp+=v[i];
        if(tmp>maxn) maxn=tmp;
        if(tmp<0)  tmp=0;
     }
}
void Thejackpot::outResult(){
     if(maxn<=0) cout<<"Losing streak."<<endl;
     else {
         cout<<"The maximum winning streak is "<<maxn<<"."<<endl;
     }
}

int main(){
  Thejackpot  tj;
  int n;
  while(cin>>n&&n){
  tj.initial(n);
  tj.readcase();
  tj.computering();
  tj.outResult();
  
}
  //system("pause");
  return 0;
}
