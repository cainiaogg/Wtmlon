#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#define rep(i,a,b) for (int i=a;i<=b;i++)
#define drep(i,a,b) for (int i=a;i>=b;i--)
#define INF int(1e8)
#define LL long long
#define D double
#define LD long double
#define pb push_back
#define mp make_pair
#define Pi M_PI
using namespace std;
template<class T> inline T min(T &a,T &b) {return a<b?a:b;}
template<class T> inline T max(T &a,T &b) {return a>b?a:b;}
LL n,p;
LL Pow2(LL a,LL k)
{
    if (k==0) return 0;
    if (k==1) return a%p;
    LL b=0;
    for(;k;k>>=1)
    {
        if (k&1) b=(b+a)%p;
        a=(a+a)%p;
    }
    return b;
}
LL Pow(LL a,LL k)
{
    if (k==0) return 1;
    LL b=1;
    for(;k;k>>=1)
    {
        if (k&1) b=Pow2(b,a);
        a=Pow2(a,a);
    }
    return b;
}
void work()
{
    LL ans=Pow(2,n-1);
    ans=ans*2LL%p;
    ans=(ans-2)%p;
    if (ans<0) ans+=p;
    printf("%I64d\n",ans);
}
int main()
{
    while (scanf("%I64d%I64d",&n,&p)!=EOF) work();
}
