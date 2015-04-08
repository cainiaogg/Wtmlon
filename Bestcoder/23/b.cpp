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
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const int maxn  = 55555;
int sum[maxn<<2];
LL dp[maxn];
LL dp1[maxn];
int n;
int lowbit(int x)
{
    return x&(-x);
}

int ask(int x)
{
    int ans = 0;
    while(x>0){
        ans+=sum[x];
        x -= lowbit(x);
    }
    return ans;
}

int update(int x)
{
    while(x<=n){
        sum[x]+=1;
        x+=lowbit(x);
    }
}

int a[maxn];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        memset(sum,0,sizeof(sum));
        for(int i = 1;i<=n;i++){
            scanf("%d",&a[i]);
            dp[i] = ask(a[i]);
            update(a[i]);
        }
        memset(sum,0,sizeof(sum));
        for(int i = n;i>=1;i--){
            dp1[i] = ask(n) - ask(a[i] - 1);
            update(a[i]);
        }
        for(int i = n-1;i>=1;i--)
            dp1[i]+=dp1[i+1];
        LL ans = 0;
        for(int i = 1;i<n;i++){
            ans+=dp[i]*dp1[i+1];
        }
        cout<<ans<<endl;
    }
    return 0;
}
