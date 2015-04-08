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

const int maxn = 111111;
const int INF = 0xfffffff;
int sum1[maxn];
int sum2[maxn];
int n;
int a[maxn];
int erfen1(int l,int r,int key)
{
    int ans = INF;
    int k = l;
    while(l<=r){
        int mid=(l+r)>>1;
        if(sum1[mid]-sum1[k-1] == key) ans=mid;
        if(sum1[mid]-sum1[k-1] >= key) r = mid-1;
        else l = mid+1;
    }
    return ans;
}
int erfen2(int l,int r,int key)
{
    int ans = INF;
    int k = l;
    while(l<=r){
        int mid=(l+r)>>1;
        if(sum2[mid] - sum2[k-1]==key) ans = mid;
        if(sum2[mid] - sum2[k-1]>=key) r = mid-1;
        else l = mid+1;
    }
    return ans;
}
int judge(int t)
{
    int ans1 = 0;int ans2 = 0;
    int l = 1;
    while(l<=n){
        int t1 = erfen1(l,n,t);
        int t2 = erfen2(l,n,t);
        l = min(t1,t2) + 1;
        if(l>n+1) return 0;
        if(t1==t2&&t1==INF) continue;
        if(t1<t2) ans1++;
        else ans2++;
        if(l-1==n){
            if(ans1>ans2&&t1>t2) return 0;
            if(ans2>ans1&&t2>t1) return 0;
        }
    }
    if(ans1==ans2) return 0;
    return ans1>ans2? ans1:ans2;
}

struct Node
{
    int x;int y;
};
int cmp(const Node &a,const Node & b)
{
    return a.x<b.x;
}
vector<Node > q;
int main()
{
    cin>>n;
    memset(sum2,0,sizeof(sum2));
    memset(sum1,0,sizeof(sum1));
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        if(a[i]==1) sum1[i] = 1;
        else sum2[i] = 1;
    }
    for(int i =1;i<=n;i++)
        sum1[i]+=sum1[i-1],sum2[i]+=sum2[i-1];
    for(int t = 1;t<=n;t++){
        int gg = judge(t);
        if(gg==0) continue;
        Node k ; k.x = gg; k.y = t;
        q.push_back(k);
    }
    sort(q.begin(),q.end(),cmp);
    printf("%d\n",q.size());
    for(int i = 0;i<q.size();i++)
        printf("%d %d\n",q[i].x,q[i].y);
    return 0;
}
