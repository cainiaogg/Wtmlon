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

int main()
{
    int n;
    int a[1000];
    int  vis[1111];
    vector<int> q;
    memset(vis,0,sizeof(vis));
    cin>>n;
    for(int i = 0;i<n;i++)
        scanf("%d",&a[i]);
    int Min = 100000;
    for(int i = 1;i<n-1;i++){
        int Max = -1;
        vis[i] = 1;
        q.clear();
        for(int j = 0;j<n;j++) if(!vis[j]) q.push_back(a[j]);
        vis[i] = 0;
        for(int j = 0;j<q.size()-1;j++){
            Max = max(abs(q[j]- q[j+1]),Max);
        }
        Min = min(Min, Max);
    }
    printf("%d\n",Min);
    return 0;
}
