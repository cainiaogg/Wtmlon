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
    int first ;int second;int id;int cha;
}node[1000];

int cmp(const Node &a,const Node&b)
{
    if(a.cha == b.cha){
        if(a.second == b.second){
            return a.id<b.id;
        }
        return a.second < b.second;
    }
    return a.cha>b.cha;
}

int main()
{
    int n;
    while(cin>>n){
        for(int i = 0;i<n;i++){
            scanf("%d%d",&node[i].first,&node[i].second);
            node[i].id = i; node[i].cha = node[i].first - node[i].second;
        }
        sort(node,node+n,cmp);
        for(int i = 0;i<n;i++){
            printf("%d ",node[i].id);
        }
        cout<<endl;
    }
    return 0;
}
