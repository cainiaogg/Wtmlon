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

int vis[10000];
int a[111];
int maxn;
void gao(int x)
{
    if(x==maxn){
        int b[100];
        for(int i = 0;i<maxn;i++)b[i] = a[i];
        for(int i = 0;i<maxn-1;i++)
            if(b[i]>b[i+1]) b[i] = 0;
        for(int i = 0;i<maxn;i++)
            printf("%d ",b[i]);
        cout<<endl;
        return ;
    }
    for(int i = 1;i<=maxn;i++){
        if(vis[i]) continue;
        vis[i] = 1;
        a[x] = i;
        gao(x+1);
        vis[i] = 0;
    }
}

int main()
{
    int n;
    while(cin>>n){
        memset(vis,0,sizeof(vis));
        maxn=  n;
        gao(0);
    }
    return 0;
}
