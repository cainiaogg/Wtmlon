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

string str[1111];
int main()
{
    int n,m;
    cin>>n>>m;
    int vis[1111];
    memset(vis,0,sizeof(vis));
    for(int i = 0;i<n;i++) cin>>str[i];
    int ans = 0 ;
    while(1){
        int pos = -1;
        for(int j = m-1;j>=0;j--) if(!vis[j]) pos = j;
        if(pos==-1) break;
        for(int i = 0;i<n-1;i++) if(str[i][pos]>str[i+1][pos]){
            ans++; vis[pos] = 1; break;
        }
        if(vis[pos]) continue;
        int flag = 0;
        for(int i = 0;i<n-1;i++) if(str[i][pos]==str[i+1][pos]) flag = 1;
        if(!flag) break;
        int gg = 0;
        for(int i = 0;i<n-1;i++){
            for(int j = 0;j<m;j++){
                if(vis[j]) continue;
                if(str[i][j]==str[i+1][j]) continue;
                if(str[i][j]<str[i+1][j]) break;
                if(str[i][j]>str[i+1][j]){
                    vis[j] = 1;ans++;gg=1;
                }
            }
        }
        if(!gg) break;
    }
    cout<<ans<<endl;
    return 0;
}
