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

int gcd(int a,int b)
{
    if(a%b==0) return b;
    return gcd(b,a%b);
}

int judge(int x)
{
    int flag = 0;
    for(int i =1;i<x;i++){
        if(gcd(i,x)>1){
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n;
    int t;
    while(cin>>n){
        int ans = 0;
        for(int i = 0;i<n;i++){
            scanf("%d",&t);
            if(judge(t)) ans+=t;
        }
        cout<<ans<<endl;
    }
    return 0;
}
