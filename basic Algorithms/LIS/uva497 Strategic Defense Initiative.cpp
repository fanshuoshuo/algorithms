#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <cstdio>
#include <map>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <sstream>
using namespace std;
class StrategicDefenseInitiative{
  private:
    vector<int>  num;
    int len[1000];
    int mark[1000];
    int path[1000];
    int maxlen;
    int maxP;
  public:
    void initial();
    void readcase();
    void computering();
    void outResult();
};
void StrategicDefenseInitiative::initial(){
   num.clear();
   memset(len,0,sizeof(len));
   memset(mark,-1,sizeof(mark));
   maxlen=0;
   maxP=0;
}
void StrategicDefenseInitiative::readcase(){
     char str[50];
     int tmp;
     stringstream ss;
     while(gets(str)&&strlen(str)){
         tmp=atoi(str);
         num.push_back(tmp);
         //str>>ss;
        // ss>>tmp;?
     }
     /*
     string str
     while(getlien(cin,str)&&str.size()){
         str>>ss
     
         //str>>ss;
        // ss>>tmp;?
     }*/
   
}
void StrategicDefenseInitiative::computering(){
    int i,j,k;
    int p;
    len[0]=1;
    for(  i=1;i<num.size();i++){
          k=0;
          for( j=0;j<i;j++){
              if(num[j]<num[i]&&k<len[j])  {k=len[j];p=j;}
          }
              len[i]=k+1;
              mark[i]=p;
    }
    for(int i=0;i<num.size();i++){
        if(maxlen<len[i]){
            maxlen=len[i];
            maxP=i;
        }
    }
    k = maxP;  
     for(int i=maxlen; i>0; i--){  
        path[i] = num[k];  
        k = mark[k];  
     }  

}
void StrategicDefenseInitiative::outResult(){
     static int cnt=0;
     if(cnt>0)  cout<<endl;
     cout<<"Max hits: "<<maxlen<<endl;
     for(int i=1; i<=maxlen; i++)   
        cout<< path[i] << endl; 
     cnt++;
}
int main(){
   StrategicDefenseInitiative d;
   int t;
   cin>>t;
   getchar();
   getchar();
   while(t--){
     d.initial();
     d.readcase();
     d.computering();
    d.outResult();
     
   }
   system("pause");
   return 0;
 
}
