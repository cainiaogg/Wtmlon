#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#define PS system("pause");
#define maxn 109
#define maxm
#define INF
#pragma comment(linker, "/STACK:1024000000,1024000000")
using namespace std;
const int MOD=1000000007;
int a[maxn];long long f[maxn][maxn];int n;
long long C[maxn][maxn];
long long solve(int L,int R)
{
    if(f[L][R]!=-1)
        return f[L][R];
    if(L==R)
        return f[L][R]=1;
    f[L][R]=(solve(L+1,R)+solve(L,R-1))%MOD;
    for(int i=L+1;i<R;i++)
    {
        if(a[i-1]!=a[i+1])
            continue;
        f[L][R]=(f[L][R]+solve(L,i-1)*solve(i+1,R)%MOD*C[R-L][i-L]%MOD)%MOD;
    }
    return f[L][R];
}
int main()
{
    for(int i=0;i<maxn;i++)
    {
        C[i][i]=C[i][0]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%MOD;
    }
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        memset(f,-1,sizeof(f));
        printf("%I64d\n",solve(1,n));
    }
    return 0;
}
