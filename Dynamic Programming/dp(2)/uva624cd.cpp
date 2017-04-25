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
class CD{
  private:
    int n,m;
    bool dp[MAX];
    int num[30];
    bool Map[30][MAX];
  public:
    void initial(int ,int);
    void readcase();
    void computering();
    void outResult();
};
void CD::initial(int x,int y){
     memset(dp,0,sizeof(dp));
     memset(num,0,sizeof(num));
     memset(Map,0,sizeof(Map));
     n=x;m=y;
   
}
void CD::readcase(){
   for(int i=0;i<m;i++){    //m sizof num
      cin>>num[i];
   }
   
}
void CD::computering(){
     int imax=0; 
     dp[0]=1;  
     for(int i=m-1;i>=0;i--) { //   µ¹Ðð 
        for(int j=n;j>=num[i];j--)  {  
            if(dp[j-num[i]])  {  
                    dp[j]=1;  
                    Map[i][j]=1;  
                    imax=max(imax,j);  
                }  
        }  
     }  
       for(int i=0,j=imax;i<m&&j>0;i++)  {  
            if(Map[i][j]) {printf("%d ",num[i]);j-=num[i];}  
       }  
        printf("sum:%d\n",imax);  
}
void CD::outResult(){
}
int main(){
   CD d;
   int n,m;
   while(cin>>n>>m){
     d.initial(n,m);
     d.readcase();
     d.computering();
     d.outResult();
   }
   system("pause");
   return 0;
 
}
