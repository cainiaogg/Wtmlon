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
typedef long long LL ;
const LL mod = 2333333;
#define lson l,mid,rt<<1
#define rson mid+1,r,rt<<1|1
const LL maxn = 55555;
LL color[maxn<<2];
LL sum[maxn<<2];



LL down(LL l,LL r,LL rt)
{
    LL len = r-l+1;
    if(color[rt]){
        color[rt<<1] +=color[rt] ;color[rt<<1] %=mod;
        color[rt<<1|1]+=color[rt] ;color[rt<<1|1] %=mod;
        sum[rt<<1]  += color[rt] * (len- (len>>1))%mod; sum[rt<<1]%=mod;
        sum[rt<<1|1] += color[rt] * (len>>1)%mod; sum[rt<<1|1] %=mod;
        color[rt] = 0;
    }
}

LL quick(LL a,LL b)
{
    LL ans = 1;
    while(b){
        if(b&1) ans *=a;
        ans %= mod;
        a*=a; b>>=1;
        a%=mod;
    }
    return ans;
}

void up(LL rt)
{
    sum[rt] = sum[rt<<1]+sum[rt<<1|1];
    sum[rt] %= mod;
}
void build(LL l,LL r,LL rt)
{
    color[rt] = 0;
    if(l==r){
        scanf("%d",&sum[rt]);return;
    }
    LL mid=(l+r)>>1;
    build(lson);
    build(rson);
    up(rt);
}

LL ask(LL L,LL R,LL l,LL r,LL rt)
{
    if(L<=l&&r<=R){
        return sum[rt];
    }
    down(l,r,rt);
    LL mid=(l+r)>>1;
    LL ans = 0;
    if(L<=mid) ans+=ask(L,R,lson);
    ans%=mod;
    if(R>mid) ans+=ask(L,R,rson);
    ans%=mod;
    return ans;
}

void update(LL key,LL add,LL l,LL r,LL rt)
{
    if(l==r){
        sum[rt]  =add;return ;
    }
    down(l,r,rt);
    LL mid=(l+r)>>1;
    if(key<=mid) update(key,add,lson);
    else update(key,add,rson);
    up(rt);
}

void update1(LL L,LL R,LL add,LL l,LL r,LL rt)
{
    if(L<=l&&r<=R){
        sum[rt]+=(r-l+1) * add; color[rt]  += add;
        sum[rt] %= mod; color[rt] %=mod;
        return ;
    }
    LL mid=(l+r)>>1;
    down(l,r,rt);
    if(L<=mid) update1(L,R,add,lson);
    if(R>mid) update1(L,R,add,rson);
    up(rt);
}

int main()
{
    LL t,a,b,c;
    LL n,m;
    while(scanf("%I64d%I64d",&n,&m)!=EOF){
        build(1,n,1);
        for(LL i = 0;i<m;i++){
            scanf("%I64d",&t);
            if(t==2){
                scanf("%I64d",&a);
                LL k = ask(a,a,1,n,1);
                update(a,quick(2,k),1,n,1);
            }
            if(t==3){
                scanf("%I64d%I64d%I64d",&a,&b,&c);
                c%=mod;
                update1(a,b,c,1,n,1);
            }
            if(t==1){
                scanf("%I64d%I64d",&a,&b);
                printf("%I64d\n",ask(a,b,1,n,1));
            }
        }
    }
    return 0;
}
