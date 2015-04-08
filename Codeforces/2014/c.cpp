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
const int maxn = 1111;
int val[maxn];
int a[maxn];
int b[maxn];
int c[maxn];
typedef long long LL;
int main()
{
    int n,m;
    cin>>n>>m;
    for(int i = 1;i<=n;i++)
        scanf("%d",&val[i]);
    for(int i = 1;i<=m;i++)
        scanf("%d",&b[i]);
    int ans = 0;
    for(int i = 1;i<=m;i++){
        int flag = 0;
        for(int j = 0;j<ans;j++)
        if(b[i]==c[j]){
            flag = 1;break;
        }
        if(!flag) c[ans++] = b[i];
    }
    for(int i = 0;i<ans/2;i++)
        swap(c[i],c[ans-i-1]);
    LL sum = 0;
    for(int i = 1;i<=m;i++){
        int pos = -1;
        for(int j = 0;j<ans;j++){
            if(b[i]==c[j]){
                pos = j;break;
            }
        }
        for(int j = pos+1;j<ans;j++)
            sum+=val[c[j]];
        int t = c[pos];
        for(int j = pos;j<ans-1;j++)
            c[j] = c[j+1];
        c[ans-1] = t;
    }
    cout<<sum<<endl;
    return 0;
}
