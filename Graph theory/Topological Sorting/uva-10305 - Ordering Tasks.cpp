#include<iostream>
#include<string>
#include<stack>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
int graph[102][102];
int vis[102];

//compution function
int dfs(int i);
void toposort();
stack<int> res;
int main(){

	while(cin>>n>>m&&(n&m)){
		if(!n&&m)
			break;
		//initial
		memset(graph,0,sizeof(graph));
		memset(vis,0,sizeof(vis));
		//input 
		int x,y;
		for(int i=0;i<m;i++){
			cin>>x>>y;
			graph[x][y]=1;
		}

		toposort();
		while(!res.size()>=1){
			cout<<res.top()<<" ";
			res.pop();
		}
		cout<<res.top()<<endl;
		res.pop();
		

	}
	return 0;

}
void toposort(){
	for(int i=1;i<=n;i++){
		if(!vis[i])
			dfs(i);
	}

}
int dfs(int u){
	vis[u]=-1;
	for(int i=1;i<=n;i++){
		if(graph[u][i]){
		if(vis[i]==-1)
			return 0;
		else if(!vis[i]&&!dfs(i))
			return 0;
		}
	}
	vis[u]=1;
	res.push(u);
	return 1;

}