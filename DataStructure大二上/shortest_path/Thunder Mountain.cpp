#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>

const int INF = 0x3F3F3F3F;
const int MAXN = 105;
double x[MAXN], y[MAXN];
double f[MAXN][MAXN], max;
int N, n;

double min( double a, double b)
{
    return a < b ? a : b;
}

double ff( double x)
{
    return x * x;
}

double dist( int i, int j)
{
    return sqrt( ff( x[i] - x[j]) + ff( y[i] - y[j]) );
}

void init()
{
    for( int i = 0; i < n; i ++)
        scanf( "%lf%lf", &x[i], &y[i]);

    for( int i = 0; i < n; i ++)
        for( int j = 0; j < n; j ++)
        {
            if( i == j) f[i][j] = 0.0;
            else {
                f[i][j] = dist( i, j);
                if( f[i][j] > 10.0) f[i][j] = INF;
            }
        }
}

void floyd()
{
    max = 0.0;
    for( int k = 0; k < n; k ++)
        for( int i = 0; i < n; i ++)
            for( int j = 0; j < n; j ++)
            {
                f[i][j] = min( f[i][j], f[i][k] + f[k][j]);
            }
    for( int i = 0; i < n; i ++)
        for( int j = 0; j < n; j ++)
            if( f[i][j] > max ) max = f[i][j];

}

int main()
{
    scanf( "%d", &N);
    for( int i = 1; i <= N; i ++)
    {
        scanf( "%d", &n);
        init();
        floyd();
        printf( "Case #%d:\n", i);
        if( fabs( max - INF) < 0.001) printf( "Send Kurdy\n");
        else printf( "%.4f\n", max);
        printf( "\n");
    }
    return 0;
}