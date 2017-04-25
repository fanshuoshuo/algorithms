#include <iostream>
#include <cmath>
using namespace std;
bool isprime(int N);
int main(){
  int N;
  int cnt=1;
  while(cin>>N&&N){             
      if(isprime(N))
         cout<<cnt<<": yes"<<endl;
      else
          cout<<cnt<<": no"<<endl;
      cnt++;
  }
 // system("pause");
  return 0;
}
bool isprime(int N){
   if(N==1||N==2)
       return false;
    if(N%2==0)
        return false;
   for(int i=3;i<=int(sqrt(double(N)));i+=2){
        if(N%i==0)
            return false;
           
   }
   return true;
  
}
