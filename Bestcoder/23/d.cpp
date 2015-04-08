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

const int mod = 1e9+9;

struct edge
{
    int next;int to;int val;
};

void add(int from,int to,int next)
{
    e[len].to = to;
    e[len].next =  head[from];
    e[len].val = val;
    head[from] = len++;
}


int main()
{
    cin>>T;
    while(T--){
        cin>>n>>m>>t;
        for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
        for(int i = 1;i<=m;i++) scanf("%d",&val[i]);
        cin>>f;
        for(int  i = 0;i<f;i++){
            scanf("%d%d",&a,&b);
            add(a,b);
        }
    }
    return 0;
}
