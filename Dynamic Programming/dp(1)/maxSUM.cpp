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
        int n;
        int num[MAX][MAX];
        int dp[MAX];
        int tmp[MAX];
        int ans;
  public:
         void initial();
         void read();
         void computering();
         void out();
  
};
 void maxinum::initial(){
      memset(tmp,0,sizeof(tmp));
      memset(dp,0,sizeof(dp));
      memset(num,0,sizeof(tmp));
     // ans=inf;
      }
 void maxinum::read(){
      cin>>n;
      for(int i=1;i<=n;i++){
         for(int k=1;k<=n;k++){
            cin>>num[i][k];
         }
      }
      
 }
 void maxinum::computering(){
      ans=num[1][1];
      for(int i=1;i<=n;i++){
           memset(tmp,0,sizeof(tmp));
           memset(dp,0,sizeof(dp));
          for(int k=i;k>=1;k--){
             for(int j=1;j<=n;j++){
                tmp[j]+=num[k][j];
                dp[j]=max(dp[j-1]+tmp[j],tmp[j]);
                ans=max(ans,dp[j]); 
 
             }
          }
      }
 }
 void maxinum::out(){
     cout<<ans<<endl;
      }
int main(){
     maxinum  m;
     m.initial();
     m.read();
     m.computering();
     m.out(); 
     system("pause");
     return 0;
}
