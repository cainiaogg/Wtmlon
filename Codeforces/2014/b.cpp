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

int a[333],b[333][333];
int main()
{
    int n;
    cin>>n;
    string str;
    for(int i = 1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i= 1;i<=n;i++){
        cin>>str;
        for(int j = 0;j<n;j++){
            b[i][j+1] = str[j] - '0';
        }
    }
    for(int k = 1;k<=n;k++)
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++)
            if(b[i][k]==1&&b[k][j]==1) b[i][j] = 1;
    }
    for(int i = 1;i<=n;i++){
      //  for(int j = i;j<=n;j++){
            for(int k = i;k<=n;k++){
                for(int l = k;l<=n;l++){
                    if(b[k][l]&&a[k]>a[l]){
                        swap(a[k],a[l]);
                    }
                }
            }
        //}
    }
    for(int i = 1;i<=n;i++)
        printf("%d ",a[i]);
    cout<<endl;
    return 0;
}
