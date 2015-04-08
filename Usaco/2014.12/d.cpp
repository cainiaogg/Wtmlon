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
struct Node
{
    int color;int pos;
}node[maxn];;

int cmp(const Node &a,const Node &b)
{
    return a.pos < b.pos;
}

int main()
{
    int n,A,B;
    char str[100];
    cin>>n>>A>>B;
    for(int i = 0;i<n;i++){
        scanf("%s",str);
        if(str[0]=='S'){
            node[i].color = 1;node[i].pos = i;
        }
        else {
            node[i].color = 0 ;node[i].pos = i;
        }
    }
    system("pause");
        int ans  = 0;
        sort(node,node+n,cmp);
        if(n==1){
            if(node[0].color) printf("%d\n",B-A+1);
            else printf("0\n");
            return 0;
        }
        for(int i = 0;i<n - 1;i++){
            if(i==0){
                if(node[i].color){
                    ans+=node[i].pos - A ;ans++; if(node[i+1].color) ans+=node[i+1].pos - node[i].pos; else ans+=(node[i+1].pos - node[i].pos) /2;
                }
            }
            else{
                if(node[i].color){
                    if(node[i+1].color) ans+=node[i+1].pos - node[i].pos;
                    else ans+=(node[i+1].pos - node[i].pos) /2;
                }
            }
        }
        if(node[n-1].color) ans+=B - node[n-1].pos ;
    return 0;
}
