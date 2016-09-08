一、

//Poj 1330
//#include"stdafx.h"
#include<iostream>
#include<cstdio>
#include<stdio.h>
#include<algorithm>
#include<iostream>
#include<map>
#include<cmath>
#include <vector>
using namespace std;
const int N =10000;
class  NearestCommonAncestors {
private: 
	void DFS(int i, int dep);
	int Num;
	vector<int> son[N];
	vector<int> father;
	vector<int> row;
	int x, y;
public :
	void initial(int n);
	void readcase();
	void computer();
	void output();
};
void NearestCommonAncestors::DFS(int i,int dep) {
	row[i] = dep;

	/*for (int j = 0;j < son[i].size();j++) {
		DFS(son[i][j], dep + 1);
	}*/
	for (vector<int> ::iterator it = son[i].begin(); it <son[i].end();it++) {
	     DFS(*it, dep + 1);
	}
}
void  NearestCommonAncestors::initial(int n) {
	Num = n;

	father.clear();father.resize(n);
	for (int i = 0;i < n;i++)
		father[i] = -1;
	//memset(test,254,sizeof(test)); 如果是数组，可以用此方法迅速清0；
	row.clear();row.resize(n);
	for (int i = 0;i < n;i++)
		son[i].clear();


}
void NearestCommonAncestors::readcase() {
	for (int i = 0;i < Num-1;i++) {
		cin >> x >> y;
		son[x - 1].push_back(y - 1);
		father[y - 1] = x - 1;
	}
	cin >> x >> y;

}
void NearestCommonAncestors::computer() {
	int i;
	for (i = 0;father[i] >= 0;i++);
	DFS(i,0);
	x--;y--;
	while (x != y) {
		if (row[x] > row[y])
			x = father[x];
		else
			y = father[y];       //error y = father[i];  
	}

}
void NearestCommonAncestors::output() {
	cout << x + 1 << endl;

}
int main() {

	NearestCommonAncestors NCA;
	int Numcase;
	int n;
	cin >> Numcase;
	while (Numcase--) {
        cin >> n;
	    NCA.initial(n);
		NCA.readcase();
		NCA.computer();
		NCA.output();

	}
	
	//system("pause");
	return 0;
	
	
}

