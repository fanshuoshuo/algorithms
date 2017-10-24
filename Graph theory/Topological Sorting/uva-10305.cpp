#include "stdio.h"
#include "string.h"

int task[102][102];
int vis[102];
int n,m;
int k;
int topo[102];

int dfs(int u);
void toposort(void);

int main()
{
    int i;
    int a,b;
    while(scanf("%d%d",&n,&m)==2)
    {
        if(!n&&!m)
            break;

        memset(task,0,sizeof(task));
        memset(vis,0,sizeof(vis));

        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            task[a][b]=1;
        }
        k=n-1;

        toposort();

        for(i=0;i<n-1;i++)
            printf("%d ",topo[i]);
        printf("%d\n",topo[n-1]);

    }

    return 0;
}

int dfs(int u)
{
    int i;
    vis[u]=-1;

    for(i=1;i<=n;i++)
    {
        if(task[u][i])
        {
            if(vis[i]==-1)
                return 0;
            else if(!vis[i]&&!dfs(i))
                return 0;
        }
    }

    vis[u]=1;
    topo[k--]=u;
    return 1;
}

void toposort()
{
    int i;

    for(i=1;i<=n;i++)
    {
        if(!vis[i])
        {
            dfs(i);
        }
    }
}