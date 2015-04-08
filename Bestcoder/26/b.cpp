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
    double b,a;
    int t;
    scanf("%d",&t);
    int Icase = 0;
    while(t--){
        printf("Case #%d: ",++Icase);
        cin>>a>>b;
        double k =  a*(a+1)/ 2.0;
        double c =  (a-1) /a;
        double gg = 1;
        for(int i = 0;i<b;i++){
            gg*=c;
        }
        gg = 1 - gg;
        k = k*gg;
        printf("%.3f\n",k);
    }
    return 0;
}
