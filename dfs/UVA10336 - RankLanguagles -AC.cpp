/*
uva 10336
*/
#include <cstdio>
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include <map>
using namespace std;
class RankLanguagles
{
  private:
    int R,C;
    vector<string> matrix;
    map <char,int>  Mapdata;
  public:
    int  dfs(int , int,char );
    void initional(int,int );
    void readcase();
    void computering ();
    void outResult();
};
void RankLanguagles::initional(int r,int c){
    R=r;C=c;
    matrix.clear();
    Mapdata.clear();
    matrix.resize(r+2); //the aditional two rows for boundaries
  } 
  void RankLanguagles::readcase(){
   for(int i = 1; i < matrix.size()-1; i++){
        cin >> matrix[i];
        matrix[i] = '0' + matrix[i] + '0'; // add left and right boundaries
    }
    for(int i = 0; i < C+2; i++){
        matrix[0].push_back('0');  // top boundary
        matrix[matrix.size()-1].push_back('0'); // bottom boundary
    }
  }
int  RankLanguagles::dfs(int r, int c,char ch){
    static int count=0;
    if(matrix[r][c] == ch){
        count++;
        matrix[r][c] = '0'; // marked visisted
        dfs(r-1, c,ch); // go up
        dfs(r+1, c,ch); // go down
        dfs(r, c-1,ch); // go left
        dfs(r, c+1,ch); // go right
     }
     return count;
 }
  void RankLanguagles::computering (){
     for(int row = 1; row < matrix.size()-1; row++){
      for(int col = 1; col <= C; col++){
           char c=matrix[row][col];
           if(c!='0'){
                 if( dfs(row, col,c)>1){
                     Mapdata[c]++;
                 }
            }
      }
    }
    
}
  void RankLanguagles::outResult(){
    static int cnt=1;
    vector<int > vec;
    int num,max=0;
    cout<<"World #"<<cnt++<<endl;
    int n=0;
    map<char ,int > ::iterator it;
    while(n!=Mapdata.size()){
        max=0;
	    for(it =Mapdata.begin(); it !=Mapdata.end() ;it++){
		      if(max<it->second)
		         max=it->second;
		 }
		      for(it =Mapdata.begin(); it !=Mapdata.end() ;it++){
			        if(max==it->second){
                      cout<<it->first<<": "<<it->second<<endl;
			          n++;
			          it->second=-1;//将其删除  
		            }
		      }
	 }
	 
   } 
int main(){
   int N;
   RankLanguagles RL;
   cin>>N;
   int r,c;
   while(N--){
      cin>>r>>c;
	  RL.initional(r,c);
	  RL.readcase();
	  RL.computering ();
	  RL.outResult();
   }
   return 0;
}

