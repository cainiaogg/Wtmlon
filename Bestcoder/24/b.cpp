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
const LL mod = 1e9+7;
LL a[111];
LL dp[111][111];
int C[111][111];
LL dfs(LL l,LL r)
{
    if(r<l) return 1;
    if(l==r) return 1;
    if(~dp[l][r]) return dp[l][r];
    LL ans = 0;
    for(int i = l;i<=r;i++){
        ans+=dfs(l,i-1)* dfs(i+1,r) %mod*C[r-l][i-l]%mod;
        ans%=mod;
    }
    for(LL i = l+1;i<r;i++){
        if(a[i-1]==a[i+1]) continue;
        ans-=dfs(l,i-1)*dfs(i+1,r)%mod; ans = (ans+mod) %mod;
    }
    return dp[l][r] = ans;
}

void init()
{
        for(int i=0;i<111;i++)
    {
        C[i][i]=C[i][0]=1;
        for(int j=1;j<i;j++)
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
    }
}

int main()
{
    LL n;
    init();
    while(cin>>n){
        memset(dp,-1,sizeof(dp));
        for(LL i = 1;i<=n;i++)scanf("%I64d",&a[i]);
        cout<<dfs(1,n)<<endl;
    }
    return 0;
}
