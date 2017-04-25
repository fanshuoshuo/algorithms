#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
#include <string>
const int MAX=110;
#define inf -99999999 
using namespace std;
class maxinum{
  private:
     private:
        int m,n;
        int num[MAX][MAX];
        int dp[MAX];
        int tmp[MAX];
        int ans;
  public:
         void initial(int ,int);
         void read();
         void computering();
         void out();
  
};
 void maxinum::initial(int x,int y){
      m=x;n=y;
      memset(tmp,0,sizeof(tmp));
      memset(dp,0,sizeof(dp));
      memset(num,0,sizeof(tmp));
     // ans=inf;
      }
 void maxinum::read(){
      int t;
      for(int i=1;i<=m;i++){
         for(int k=1;k<=n;k++){
            cin>>t;
            if(t)  num[i][k]=-10010;
            else   num[i][k]=1;
         }
      }
      cout<<endl;
     for(int i=1;i<=m;i++){
         for(int k=1;k<=n;k++){
           cout<<num[i][k]<<" ";
         }
         cout<<endl;
         }
 }
 void maxinum::computering(){
      ans=num[1][1];
      for(int i=1;i<=m;i++){
          memset(tmp,0,sizeof(tmp));
          memset(dp,0,sizeof(dp));
          for(int k=i;k>=1;k--){
             for(int j=1;j<=n;j++){
                tmp[j]+=num[k][j];
                //if(tmp[j]==(i-k+1)){
                dp[j]=max(dp[j-1]+tmp[j],tmp[j]);
                ans=max(ans,dp[j]); }           
          }
          //cout<<ans<<endl;
      }
 }
 void maxinum::out(){
     cout<<ans<<endl;
      }
int main(){
     int m,n;
     maxinum  mn;
     while(cin>>m>>n){
     if(m==0&&n==0) break;
     mn.initial(m,n);
     mn.read();
     mn.computering();
     mn.out(); 
     }
     system("pause");
     return 0;
}
