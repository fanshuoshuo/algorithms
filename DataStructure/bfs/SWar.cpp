#include <cstdio>
#include<iostream>
#include<vector>
#include<string>
#include <queue>

struct RC{
    int r;
    int c;
    RC(int a = 0, int b = 0){r = a; c = b;}
};
 
using namespace std;
class SWar
{
  private:
      int R;
      int num;
      vector<string> matrix;
  public:
  int cnt;
  void bfs(int,int);
  void initional(int,int );
  void readcase();
  void computering ();
  void outResult();
};
void SWar::initional(int r,int a){
     R=r;cnt=0;
     num=a;
     matrix.clear();
     matrix.resize(r+2); //the aditional two rows for boundaries
  } 
void SWar::readcase(){
   for(int i = 1; i <= R; i++){
        cin >> matrix[i];
        matrix[i] = '*' + matrix[i] + '*'; // add left and right boundaries  reload'+'
    }
    for(int i = 0; i < R+2; i++){
        matrix[0].push_back('*');  // top boundary
        matrix[R+1].push_back('*'); // bottom boundary
    }
  }

void SWar::computering (){
    const int dr[8] = {-1,-1, 0 ,1,1,1 ,0, -1 };
    const int dc[8] = {0 ,1 , 1 ,1,0,-1,-1,-1};  
    for(int row = 1; row <=R; row++){
      for(int col = 1; col < R+2; col++){
           if(matrix[row][col]=='1'){
                // bfs()
                RC s, ns;
                queue<RC> q;
                matrix[row][col]='0';
                s.r=row;
                s.c=col;
                q.push(s);
                while (!q.empty()){
                    s = q.front();
                    q.pop();
                    for(int i = 0; i < 8; i++){
                       ns = RC(s.r + dr[i], s.c + dc[i]);
                       if(matrix[ns.r][ns.c]=='1'){
                         matrix[ns.r][ns.c] ='0';
                         q.push(ns);
                       }
                     }
                 }
                 cnt++;
            }
        }
    }
}
void SWar::outResult(){
    cout<<"Image number "<<num<<" contains "<<cnt<<" war eagles."<<endl;
  }
int main(){ 
   SWar OD;
   
   int r;
   int num=0;
   while(cin>>r&&!cin.eof()){
      num++;
      OD.initional(r,num);
      OD.readcase();
      OD.computering ();
      OD.outResult();
   }
  // system("pause");
   return 0;
}

