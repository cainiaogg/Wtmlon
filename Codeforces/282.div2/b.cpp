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

int main()
{
    int n;
    int a,b;
    cin>>a>>b;
    if(b>a){
        cout<<0<<endl; return 0;
    }
    if(a==b){
        cout<<"infinity"<<endl; return 0;
    }
    int k = a-b;
    int ans = 0;
    for(int i = 1;i<=sqrt(k);i++){
        if(k%i==0){
            if(i>b) ans++;
            if(k/i>b) ans++;
            if(i==k/i&&i>b) ans--;
        }
    }
    cout<<ans<<endl;
    return 0;
}
