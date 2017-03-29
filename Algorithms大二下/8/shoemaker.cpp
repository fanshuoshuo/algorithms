#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
using namespace std;
struct node{
  int num;
  double time,fine,per;
};
int cmp(node a,node b)  
{   if (fabs(a.per-b.per)>0.00001) return a.per>b.per;  
     return a.num<b.num;   
}  
class ShoemakerProblem{
  private:
    node shoemaker[1010];
    int n;
  public : 
    void initial();
    void readcase();
    void computering();
    void outResult();
};
void ShoemakerProblem::initial(){
   
}
void ShoemakerProblem::readcase(){
   string str;
   //getline(cin,str);wrong answer;
   cin>>n;
   double a,b;
   for(int i=0;i<n;i++){
       cin>>shoemaker[i].time>>shoemaker[i].fine;
       shoemaker[i].per=shoemaker[i].fine/shoemaker[i].time;
       shoemaker[i].num=i+1;
   }
}
void ShoemakerProblem::computering(){
   sort(shoemaker,shoemaker+n,cmp); 
    
}
void ShoemakerProblem::outResult(){
    for(int i=0;i<n-1;i++)
       cout<<shoemaker[i].num<<" ";
    cout<<shoemaker[n-1].num<<endl;
   
}
int main(){
   ShoemakerProblem d;
   int t;
   cin>>t;
   while(t--){
     d.initial();
     d.readcase();
     d.computering();
     d.outResult();
     if(t) cout<<endl;
   }
  system("pause");
   return 0;
 
}
