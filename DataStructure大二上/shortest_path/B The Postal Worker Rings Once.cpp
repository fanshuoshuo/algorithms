/*
  UVA 117 The Postal Worker Rings Once
  AC by J.Dark
  ON 2012/11/18
  Time 0.008s
*/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
#define MAX 999999;
#define FG 96
using namespace std;

class Graph{
public:
   void Initial();
   void Input(string STR);
   void Compute();    
private:
   int from, to, ans;
   int a[27][27];
   map<int, int> degree;     
};

void Graph::Initial(){
    for(int i=1; i<27; i++){
       for(int k=1; k<27; k++){
          a[i][k] = MAX;
       }
       a[i][i] = 0;
    }
    degree.clear();
    ans = 0;
}

void Graph::Input(string STR){
   int u, v, length;
   u = STR[0] - FG;
   v = STR[STR.length()-1] - FG;
   length = STR.length();
   a[u][v] = a[v][u] = length;
   degree[u]++;
   degree[v]++;
   ans += length;

}

void Graph::Compute(){
     bool flag = false;
     int i, j, k;
     for(i=1; i<27; i++){
            if(degree[i]%2 !=0){
                if(flag)
                   to = i;
                else{
                    from = i;
                    flag = true;
                }
            }
     }

     for(int k=1; k<27; k++){
        for(int i=1; i<27; i++){
           for(int j=1; j<27; j++){
              if( a[i][j] > a[i][k] + a[k][j])
                 a[i][j] = a[i][k] + a[k][j];
           }
        }
     }
     if(flag){
         ans += a[from][to];              
         cout << ans << endl;
     }
     else
       cout << ans << endl;
}


int main(){
    string STR;
    Graph xx;

    while(cin >> STR){
              xx.Initial();
              xx.Input(STR);
              while(cin >> STR && STR != "deadend"){
                   xx.Input(STR);
              }
              xx.Compute();
    }
               
    //system("pause");
    return 0;
}
