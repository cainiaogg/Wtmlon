#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>

using namespace std;


int m;
const int maxn = 1e4 + 10;
int dist[maxn<<1];
int vis[maxn<<1];
int bfs(int x)
{
    queue<int> q;
    q.push(x);
    memset(dist,0,sizeof(dist));
    memset(vis,0,sizeof(vis));
    while(!q.empty()){
        int cur= q.front();
        q.pop();
        if(cur==m){
            return dist[cur];
        }
        int ans = cur - 1;
        if(ans>0&&!vis[ans]){
            dist[ans] = dist[cur] + 1;
            vis[ans]  = 1;
            q.push(ans);
        }
        ans = cur*2;
        if(ans<=2*m&&!vis[ans]){
            dist[ans] = dist[cur]+1;
            vis[ans] = 1;
            q.push(ans);
        }
    }
}


int main()
{
    int n;
    cin>>n>>m;
    if(n>2*m)
        cout<<n - m<<endl;
    else cout<<bfs(n)<<endl;
    return 0;
}
