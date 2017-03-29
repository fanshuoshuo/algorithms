#include <iostream>
#include <cstdio>
#include <cmath>
#include<algorithm> 
const int N = 210; 

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
      public:
         void initial(int);
         void readgraph();
         void floyd();
         void solve(int);
         double dis(XY &,XY &);
         
};
double Floyd::dis(XY &a,XY &b)
{
       return sqrt(((a.x-b.x)*(a.x-b.x))+((a.y-b.y)*(a.y-b.y)));
}
void Floyd::initial(int a)
{
     n=a; 
}
void Floyd::readgraph()
{ 
     int a,b;
     for(int i=0; i<n; i++)
     {
             cin>>a>>b;
             xy[i].x=a;
             xy[i].y=b;
     }
     for(int i=0; i<n; i++)
       for(int j=0; j<n ; j++)
       {
          d[i][j]=dis(xy[i],xy[j]);
       }       
} 
void Floyd::floyd()
{
    for(int k=0; k<n; ++k) 
    for(int i=0; i<n; ++i)
    { 
        for(int j=0; j<n; ++j)
        { 
            double tmp = max(d[i][k],d[k][j]);
            d[i][j] = min(d[i][j],tmp); 
        } 
    } 
}
void Floyd::solve(int cnt)
{   
 
     floyd(); 
     
     double ans;
     
     ans=d[0][1];
     
     printf("Scenario #%d\n",cnt);
     printf("Frog Distance = %0.3f\n\n",ans);
}
int main()
{
    int a,cnt=0;
    Floyd ff;
    string s;
    
    while(cin>>a && a)
    {
       ff.initial(a);
       ff.readgraph(); 
       ff.solve(++cnt);
    } 
    return 0; 
}
