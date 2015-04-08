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
struct Node
{
    int x;int y;
}node[111111];

int dist(Node a,Node b)
{
    return abs(a.x-b.x) + abs(b.y-a.y);
}

int main()
{
    freopen("marathon.in","r",stdin);
    freopen("marathon.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 0;i<n;i++)
        scanf("%d%d",&node[i].x,&node[i].y);
    int Max = -1;
    LL sum = 0;
    for(int i = 0;i<n-1;i++)
        sum+=dist(node[i],node[i+1]);
    for(int i =1;i<n-1;i++){
        Max = max(Max,dist(node[i-1],node[i])+ dist(node[i],node[i+1])-dist(node[i-1],node[i+1]));
    }
    sum -=Max;
    cout<<sum<<endl;
    return 0;
}
