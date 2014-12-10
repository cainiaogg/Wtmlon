#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>

using namespace std;

struct Node
{
    int t;string major ;int order ; string color;
}node[111];
int val[2][111];
int vis[2][111];
int main()
{
    memset(vis,0,sizeof(vis));
    memset(val,0,sizeof(val));
    string home ,away;
    int t;
    cin>>away>>home;
    cin>>t;
    for(int i = 0;i<t;i++)
        cin>>node[i].t>>node[i].major>>node[i].order>>node[i].color;

    for(int i = 0;i<t;i++){
        if(node[i].major=="a"){
            if(node[i].color=="r"){
                if(!vis[0][node[i].order])
                cout<<home<<" "<<node[i].order<<" "<<node[i].t<<endl,vis[0][node[i].order]=1;
            }
            else{
                val[0][node[i].order]++;
                if(val[0][node[i].order]==2&&!vis[0][node[i].order])
                cout<<home<<" "<<node[i].order<<" "<<node[i].t<<endl,vis[0][node[i].order]=1;
            }
        }
        else{
            if(node[i].color=="r"){
                if(!vis[1][node[i].order])
                cout<<away<<" "<<node[i].order<<" "<<node[i].t<<endl,vis[1][node[i].order]=1;
            }
            else{
                val[1][node[i].order]++;
                if(val[1][node[i].order]==2&&!vis[1][node[i].order]){
                    cout<<away<<" "<<node[i].order<<" "<<node[i].t<<endl,val[1][node[i].order]=0,
                    vis[1][node[i].order]=1;
                }
            }
        }
    }
    return 0;
}
