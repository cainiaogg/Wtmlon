#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdlib>
#include<queue>
#include<algorithm>
using namespace std;
typedef long long LL;

const LL mod = 1e9+7;
const LL maxn =  33333;


LL n,m;
LL ans[maxn];
LL color[maxn];
LL cnt[maxn];
LL d[maxn];
LL nd[maxn];
struct Node
{
    LL l;LL r;LL id;
}node[maxn];

LL unit;

LL quick(LL a,LL b)
{
    LL sum = 1;
    while(b){
        if(b&1) sum*= a;
        sum%=mod;
        a*=a;a%=mod;
        b>>=1;
    }
    return sum;
}

void init()
{
    d[0] = nd[0] = 1;
    for(LL i = 1;i<=maxn;i++) d[i] =  i*d[i-1] %mod;
    for(LL i = 1;i<=maxn;i++) nd[i] = quick(d[i],mod-2);
}

int cmp(const Node &a,const Node &b)
{
    if(a.l/unit == b.l/unit) return a.r < b.r;
    return a.l/unit<b.l/unit;
}

void gao()
{
    LL temp = 1;
    LL l = 1;LL r = 0;// 由于初始区间 l >r ,所以下面循环得从r 开始，如果查询区间不是从1开始就会出现l经过一段，r重复经过这一段。
    memset(cnt ,0 ,sizeof(cnt));
    for(LL i = 0 ;i<m;i++){
        while(r>node[i].r){
            temp *= nd[cnt[color[r]]] ;temp %=mod;
            cnt[color[r]]--;
            temp *= d[cnt[color[r]]];temp %=mod;
            r--;
        }
        while(r<node[i].r){
            r++;
            temp *=nd[cnt[color[r]]];temp %=mod;
            cnt[color[r]]++;
            temp *= d[cnt[color[r]]];temp %=mod;
        }
        while(l<node[i].l){
            temp *= nd[cnt[color[l]]]; temp %=mod;
            cnt[color[l]]--;
            temp *= d[cnt[color[l]]]; temp %=mod;
            l++;
        }
        while(l>node[i].l){
            l--;
            temp *= nd[cnt[color[l]]]; temp %=mod;
            cnt[color[l]]++;
            temp *= d[cnt[color[l]]];temp %=mod;
        }
        ans[node[i].id]  = d[r-l+1] * quick(temp,mod-2) %mod;
    }
}

int main()
{

    LL T;
    init();
    cin>>T;
    while(T--){
        cin>>n>>m;
        for(LL i = 1;i<=n;i++)
            scanf("%I64d",&color[i]);
        for(LL i = 0 ;i<m;i++){
            scanf("%I64d%I64d",&node[i].l,&node[i].r);
            node[i].id =  i;
        }
        unit = (LL) sqrt(n);
        sort(node,node+m,cmp);
        gao();
        for(LL i = 0;i<m;i++){
            printf("%I64d\n",ans[i]);
        }
    }
    return 0;
}
