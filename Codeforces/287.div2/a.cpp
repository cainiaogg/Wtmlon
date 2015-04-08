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

struct Node
{
    int x;int val;
}node[1000];

int cmp(const Node&a,const Node &b)
{
    return a.val<b.val;
}
int main()
{
    int n,k,val;
    cin>>n>>k;
    for(int i= 1;i<=n;i++){
        scanf("%d",&val);
        node[i-1].x = i;node[i-1].val = val;
    }
    int ans = 0 ;
    sort(node,node+n,cmp);
    while(k>0){
        if(k-node[ans].val<0){
            break;
        }
        else {
            k -= node[ans++].val;
        }
    }
    cout<<ans<<endl;
    for(int i = 0;i<ans;i++)
        printf("%d ",node[i].x);
    cout<<endl;
    return 0;
}
