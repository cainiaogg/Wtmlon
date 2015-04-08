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

const int maxn = 3*11111;
int a[maxn];
int main()
{
    int n,t;
    memset(a,0,sizeof(a));
    cin>>n>>t;
    for(int i = 1;i<=n-1;i++)
        scanf("%d",&a[i]);
    int flag = 0;
    int pos = 1;
    while(pos<=n){
        if(pos == t){
            flag =1; break;
        }
        if(pos==n) break;
        pos += a[pos];
    }
    if(flag) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
