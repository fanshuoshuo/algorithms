#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#define MAX 10005
using namespace std;
void process(int &a,int &b,int &c,int d);
class TheCandymanCan{
  private:
    int num[35];
    int a,b,c;
    int n;
    int Max,Min;
    int ans;
  public:
    void initial();
    void readcase();
    void computering();
    void outResult();
};
void TheCandymanCan::initial(){
  memset(num,0,sizeof(num));
  ans=10000000;
}
void TheCandymanCan::readcase(){
  cin>>n;
  for(int i=0;i<n;i++){
     cin>>num[i];
  }   
}
void TheCandymanCan::computering(){
   int a,b,c;
   int tmp[30];
   static int cnt=1;
   if(n<=3){
     Max=max(num[0],num[1]);Max=max(num[2],Max);
     Min=min(num[0],num[1]);Min=min(num[2],Min);
     cout<<"Case "<<cnt++<<": "<<Max-Min<<endl;
     return ;
  } 
  int minn;
  for(int i=0;i<n-2;i++){
     for(int j=i+1;j<n-1;j++){
        for(int k=j+1;k<n;k++){
            a=num[i];b=num[j];c=num[k];
            for(int m=0;m<n;m++) tmp[m]=num[m];
            tmp[i]=0;tmp[j]=0;tmp[k]=0;
           // cout<<a<<" "<<b<<" "<<c<<endl;
            for(int p=0;p<n;p++){
               
                   if(tmp[p])  process(a,b,c,tmp[p]);
                   //cout<<a<<" "<<b<<" "<<c<<endl;
            }
            Max=max(max(a,b),c);
            Min=min(min(a,b),c);
            ans=min(ans,Max-Min);
            //cout<<ans<<endl;
        }
        
     }
  }
  // 3  3  5   3 3 5  3 3 5
  cout<<"Case "<<cnt++<<": "<<ans<<endl;
}
void TheCandymanCan::outResult(){
}
int main(){
   TheCandymanCan d;
   int t;
   cin>>t;
   while(t--){
     d.initial();
     d.readcase();
     d.computering();
     d.outResult();
   }
   system("pause");
   return 0;
 
}
void  process(int &a,int &b,int &c,int d){
    int x;
    x=min(a,b);
    x=min(x,c);
    a-=x;b-=x;c-=x;//   3  3  5    0  0  2 //  3  3   2
    x=min(a,b);
    x=min(x,c);
    if(x==a) {a+=d;return ;}
    else if(x==b)  {b+=d;return ;}
    else c+=d;
}
