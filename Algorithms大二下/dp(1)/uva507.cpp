#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdio>
using namespace std;
class Thejackpot{
   private:
      int n;
      int start;
      int end;
      int ans;
      int dp[20010];
      vector<int> v;
   public:
      void initial(int);
      void readcase();
      void computering();
      void outResult();
           
};
void Thejackpot::initial(int x){
     n=x;
     ans=-1;
     v.clear();
     for(int i=0;i<n;i++){
		 dp[i]=0;
	}
     start=1;
     end=1;
}
void Thejackpot::readcase(){
     int a;
     v.push_back(0);
     for(int i=1;i<n;i++){
         cin>>a;
         v.push_back(a);
     }
}
void Thejackpot::computering(){
     static int cnt=1;
     int tmp;
     int prefrom=1,preto=1;
     for(int i=1;i<v.size();i++){
         dp[i]=max(dp[i-1]+v[i],dp[i]);
         if(ans<dp[i]) ans=dp[i];
     }
     if(ans<=0){
        cout<<"Route "<<cnt++<<" has no nice parts"<<endl;
        return ;
     }
     else{
          for(int i=n-1;i>=0;i--){       
    		if(dp[i]==ans){
    			preto=i+1;
    			while(i>=1&&dp[i-1]+v[i]>=0){
    				i--;
    			}
    			prefrom=i+1;
    			if(preto-prefrom>=end-start){
    				start=prefrom;
    				end=preto;
    			}
    		}
    	 }
     }
     printf("The nicest part of route %d is between stops %d and %d\n",cnt++,start,end);
}
void Thejackpot::outResult(){
    
}

int main(){
  Thejackpot  tj;
  int n;
  int t;
  cin>>t;
  while(t--){
  cin>>n;
  tj.initial(n);
  tj.readcase();
  tj.computering();
  tj.outResult();
  
}
  system("pause");
  return 0;
}
