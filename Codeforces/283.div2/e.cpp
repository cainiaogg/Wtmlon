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

int val[maxn];
struct Node
{
    int x;int y;int id;
}part[maxn],actor[maxn];;

int cmp(const Node& a,const Node &b)
{
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}

int erfen(int l,int r,int key)
{
    int ans = -1;
    while(l<=r){
        int mid=(l+r)>>1;
        if(actor[mid].x>=key) ans = mid;
        if(actor[mid].x>=key) r = mid-1;
        else l = mid+1;
    }
    return ans;
}

int main()
{
    int n,m;
    cin>>n;
    for(int i = 0 ;i<n;i++){
        scanf("%d%d",&part[i].x,&part[i].y);
        part[i].id = i;
    }
    cin>>m;
    for(int i = 0 ;i<m;i++){
        scanf("%d%d",&actor[i].x,&actor[i].y);
        actor[i].id = i;
    }
    sort(part,part+n,cmp);
    sort(actor,actor+m,cmp);
    int flag = 1;
    for(int i = 0;i<n;i++){
        int t  = erfen(1,m,part[i].x);
        int gg =0;
        if(t==-1){
            flag = 0;break;
        }
        for(int j = t;j<m;j++){
            printf("%d %djiji\n",actor[j].y,part[i].y);
            if(actor[j].y>=part[i].y){
                gg=1;val[part[i].id] =actor[j].id;
                break;
            }
        }
        if(!gg){
            flag = 0 ;break;
        }
    }
    if(flag==0)printf("NO\n");
    else{
        printf("YES\n");
        for(int i = 0;i<n;i++){
            printf("%d ",val[i]+1);
        }
        cout<<endl;
    }
    return 0;
}
