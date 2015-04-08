#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
#include <set>
#include <bitset>
#include <queue>
#include <stack>
#include <string>
#include <iostream>
#include <cmath>
#include <climits>

using namespace std;
typedef long long LL;
LL k;
const LL maxn = 22222;
LL dp[maxn][55];
const LL INF = 1000000000000000000LL;
LL head[maxn];
LL len;
struct Node
{
    LL next;LL to;LL val;
}e[maxn<<1];

LL ans;

void add(LL from,LL to,LL val)
{
    e[len].to  = to;
    e[len].next = head[from];
    e[len].val = val;
    head[from] = len++;
}

void dfs(LL cur,LL pre)
{
    for(LL i = 0 ;i<=k;i++) dp[cur][i] = INF;
    dp[cur][0] = dp[cur][1] = 0;
    for(LL i = head[cur];i!=-1;i=e[i].next){
        LL cc=e[i].to;LL val = e[i].val;
        if(cc==pre) continue;
        dfs(cc,cur);
        for(LL j = k;j>=0;j--){
            for(LL t  = 0;t<=j;t++){
                if(dp[cc][t]==INF||dp[cur][j-t]==INF) continue;
                dp[cur][j] = min(dp[cur][j],dp[cc][t]+dp[cur][j-t]+2*t*(k-t)*val);
            }
        }
    }
    ans = min(ans,dp[cur][k]);
}

int main()
{
    LL a,b,c;
    LL T;
    LL n;
    cin>>T;
    while(T--){
        ans = INF;
        len = 0;
        memset(head,-1,sizeof(head));
        cin>>n>>k;
        for(LL i = 0 ;i<n-1;i++){
            scanf("%I64d%I64d%I64d",&a,&b,&c);
            add(a,b,c); add(b,a,c);
        }
        dfs(1,-1);
        cout<<ans<<endl;
    }
    return 0;
}
