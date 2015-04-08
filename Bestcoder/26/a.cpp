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
    int n,m;
    while(scanf("%d%d",&n,&m)!=EOF){
        int t = m %n;
        if(t==0) cout<<n-1<<endl;
        else cout<<t-1<<endl;
    }
    return 0;

}
