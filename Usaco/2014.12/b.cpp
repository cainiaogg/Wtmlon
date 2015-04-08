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
#include <vector>
using namespace std;


char str[100][100];
int Map[100][100];
int main()
{
    int n,m;
    freopen("crosswords.in","r",stdin);
    freopen("crosswords.out","w",stdout);
    cin>>n>>m;
    for(int i = 0;i<n;i++)
        scanf("%s",str[i]);
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            if(str[i][j] == '#')continue;
            if((i==0||str[i-1][j]=='#')&&i+2<n&&str[i+1][j]=='.'&&str[i+2][j]=='.') Map[i][j] = 1;
            if((j==0||str[i][j-1]=='#')&&j+2<m&&str[i][j+1]=='.'&&str[i][j+2]=='.') Map[i][j] = 1;
        }
    }
    int ans = 0;
    for(int i = 0;i<n;i++)
        for(int j = 0 ;j<m;j++)
        if(Map[i][j] ) ans++;
    printf("%d\n",ans);
    for(int i = 0;i<n;i++)
    for(int j = 0;j<m;j++){
        if(Map[i][j]) printf("%d %d\n",i+1,j+1);
    }
    return 0;
}
