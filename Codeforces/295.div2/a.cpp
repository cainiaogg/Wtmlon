#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>

using namespace std;

int main()
{
    int n;
    char str[1111];
    int vis[1111];
    memset(vis,0,sizeof(vis));
    cin>>n;
    scanf("%s",&str);
    for(int i = 0 ;i<n;i++){
        if(str[i]>='a'&&str[i]<='z') str[i] = str[i] - 'a'+ 'A';
    }
    int ans = 0 ;
    for(int i = 0;i<n;i++){
        int t = str[i] - 'A';
        vis[t] = 1;
    }
    for(int i = 0;i<26;i++)
        if(vis[i]) ans++;
    if(ans==26) {
        printf("YES\n");
    }
    else printf("NO\n");
    return 0;
}
