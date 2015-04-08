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
    int n,k,T;
    cin>>T;
    while(T--){
        cin>>n>>k;
        if(k&1){
            if(k-n/2>0&&(k-n)%2==0) printf("A\n");
            else printf("B\n");
        }
        else {
            if(k-n/2>0&&(k-n)&1) printf("A\n");
            else printf("B\n");
        }
    }
    return 0;
}
