#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <deque>
#include <sstream>
using namespace std;
class StacksOfFlapjacks{
  private:
   deque<int>  q;
  public: 
    void initial();
    bool readcase();
    void computering();
    void outResult();
};
void StacksOfFlapjacks::initial(){
     q.clear();
}
bool StacksOfFlapjacks::readcase(){
     initial();
     string str;
     int num;
     stringstream ss;
     while(getline(cin,str)){
        ss<<str;
        cout<<str<<endl;
        while(ss>>num){ q.push_front(num);
        }         
         return true;
     }
     return false;
   
}
void StacksOfFlapjacks::computering(){
    deque<int>::iterator imax;
    for(deque<int>::iterator it=q.begin();it!=q.end();it++){
         imax=max_element(it,q.end());
         if(it!=imax){
            if(imax!=q.end()-1){
               reverse(imax,q.end());
               cout<<distance(q.begin(),imax)+1<<" ";
            }
              reverse(it,q.end());
              cout<<distance(q.begin(),it)+1<<" ";
         }
    }
   
}
void StacksOfFlapjacks::outResult(){
     cout<<"0"<<endl;
}
int main(){
   StacksOfFlapjacks d;
  
   while(d.readcase()){
     d.computering();
     d.outResult();
   }
   system("pause");
   return 0;
 
}
