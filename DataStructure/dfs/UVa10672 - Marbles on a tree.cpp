#include <vector>  
#include <algorithm>  
#include <iostream>  
#include <cstdio>
using namespace std;  
struct node  
{  
    int stone;  
    int move;  
    int left;  
}nodes[10000+5];  
vector<int> edges[10000+5];  
bool root[10000+5];  
int n,ans;  
int DFS(int root)  
{  
    nodes[root].left=nodes[root].stone-1;  
    nodes[root].move=0;  
    for(int i=0;i<edges[root].size();i++)  
    {  
        DFS(edges[root][i]);  
        nodes[root].left+=nodes[edges[root][i]].left;  
        nodes[root].move+=abs(nodes[edges[root][i]].left)+nodes[edges[root][i]].move;  
    }  
    return nodes[root].move;  
}  
int main()  
{  
    while(scanf("%d",&n)&&n)  
    {  
        int ID,num,next;  
        memset(root,1,sizeof(root));  
        for(int i=0;i<n;i++)  
        {  
            scanf("%d",&ID);  
            ID--;  
            edges[ID].clear();  
            scanf("%d",&nodes[ID].stone);  
            scanf("%d",&num);  
            for(int j=0;j<num;j++)  
            {  
                scanf("%d",&next);  
                root[next-1]=false;  
                edges[ID].push_back(next-1);  
            }  
        }  
        for(int i=0;i<n;i++)  
        {  
            if(root[i])  
            {  
                ans=DFS(i);  
                break;  
            }  
        }  
        printf("%d\n",ans);  
    }  
    return 0;  
}   

