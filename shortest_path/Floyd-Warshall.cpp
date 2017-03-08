/*
uva 534 
code by  ShuoshuoFan
date 20151211
AC
*/
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
const int N=210;
using namespace std;
struct XY{
	int x,y;
};
class Floyd{
	private:
		double d[N][N];
		XY xy[205];
		int all;
		int n;
	public :
		void initialize(int );
		void readgraph();
		void floyd();
		void solve(int );
		double dis(XY &,XY &);
};
double Floyd::dis(XY &a,XY &b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
void Floyd::initialize(int a){
	n=a;
}
void Floyd::readgraph(){
	for(int i=0;i<n;i++){
		cin>>xy[i].x>>xy[i].y;
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			d[i][j]=dis(xy[i],xy[j]);
}
void Floyd::floyd(){
	for(int k=0;k<n;k++)
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				double tmp=max(d[i][k],d[k][j]);
				d[i][j]=min(d[i][j],tmp);	
			}
				
}
void Floyd::solve(int cnt){
	floyd();
	double ans;
	ans=d[0][1];
	cout<<"Scenario #"<<cnt<<endl;
	printf("Frog Distance =%0.3f\n\n",ans);
}				
int main(){
	int a,cnt=0;
	Floyd f;
	string s;
	while(cin>>a&&a){
		f.initialize(a);
		f.readgraph();
		f.solve(++cnt);
	}
 	return 0;
} 
/*

Input:graphA[n][n]
Floyd-Warshall(A)
	for k = 0 to n-1
		for j =0 to n-1 
			for i = 0 to n-1
				if(A[i][j]>A[i][k]+A[k][j])
					A[i][j]=A[i][k]+A[k][j]
					



*/
