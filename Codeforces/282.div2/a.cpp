#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <climits>
#include <string>
#include <iostream>
#include <map>
#include <cstdlib>
#include <list>
#include <set>
#include <queue>
#include <stack>
using namespace std;

int ans[]={2,7,2,3,3,4,2,5,1,2};
int main()
{
    int n;
    cin>>n;
    int a = n/10;int b = n%10;
    cout<<ans[a]*ans[b]<<endl;
    return 0;
}
