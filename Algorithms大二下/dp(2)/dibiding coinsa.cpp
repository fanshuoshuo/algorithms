#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
using namespace std;
class dividingCoins{
  private:
    int n;
    vector<int>  v;
    int dp[500110];
    int sum;
   public:
    void initial();
    void readcase();
    void computering();
    void outResult();
};
void dividingCoins::initial(){
     v.clear();
     sum=0;
     memset( dp,0, sizeof( dp));  
}
void dividingCoins::readcase(){
     cin>>n;
     int a;
     v.resize(n);
    
     for(int i=0;i<n;i++){
        cin>>v[i]; 
        sum+=v[i];       
     }
}
void dividingCoins::computering(){
     dp[0]=1;
     for( int i=0;i<n;i++) { 
            for( int j=sum;j>=v[i];j--)  
                if(!dp[j]) dp[j] =dp[j-v[i]];  
     }
   //5    3 1 3 4       11
    //      0 0 0 0 0 0 0
            1   1 1
}
void dividingCoins::outResult(){
}
int main(){
   dividingCoins dc;
   int t;
   cin>>t;
   while(t--){
     dc.initial();
     dc.readcase();
     dc.computering();
     dc.outResult();
   }
   system("pause");
   return 0;
  // system("pause");
}
