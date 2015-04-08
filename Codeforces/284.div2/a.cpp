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

    int l;int r;
}node[111111];

int main()
{
    int n,x;
    cin>>n>>x;

    for(int i = 0;i<n;i++)
        scanf("%d%d",&node[i].l,&node[i].r);
    int board = 1;
    int ans = 0;
    for(int i = 0;i<n;i++){
        int t = node[i].l - board;
        t = t/x; int gg = board + t*x;
        ans+=node[i].r - gg + 1;
        board = node[i].r +1;
    }
    cout<<ans<<endl;

    return 0;
}
