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
int x[maxn],y[maxn];
int main()
{
    freopen("cowjog.in","r",stdin);
    freopen("cowjog.out","w",stdout);
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++)
        scanf("%d%d",&x[i],&y[i]);
    int ans = 0;
    int board  = y[n];
    for(int i = n-1;i>=1;i--){
        if(y[i]<=board){
            ans++ ; board = y[i];
        }
    }
    cout<<ans+1<<endl;
    return 0;
}
