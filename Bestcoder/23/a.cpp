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
    int T;
    int n;
    int a[1111];
    cin>>T;
    int b[1111];
    while(T--){
        cin>>n;
        int ans = 0;
        int ans1 = 0;
        for(int i = 0 ;i<n;i++){
            scanf("%d",&a[i]);
            if(i&1) ans+= a[i];
            else ans1+=a[i];
        }
        int flag = 1;
        for(int i = 0;i<n;i++)
        b[i] = a[n-i-1];
        for(int i = 0;i<n;i++)
        if(a[i]!=b[i]){
             flag = 0;break;
        }
        if(!flag&&ans==ans1){
            printf("Yes\n");
        }
        else printf("No\n");
    }
    return 0;
}
