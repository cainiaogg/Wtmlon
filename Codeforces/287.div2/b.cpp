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
double eps = 1e-6;
int main()
{
    int r,x,y,x1,y1;
    cin>>r;
    cin>>x>>y>>x1>>y1;
    double dist = (x1 - x )*(x1 - x) + (y1 - y) * (y1-y);
    dist = sqrt(dist);
    if(dist<2*r){
        int t =ceil(dist/2/r);
        cout<<t<<endl;
    }
    else{
        dist -=2*r;
        int t =ceil(dist/2/r);
        printf("%d\n",t+1);
    }
    return 0;
}
