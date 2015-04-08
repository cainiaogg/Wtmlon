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
typedef long long LL;
using namespace std;
int main()
{

    int n,B;
    char str[300];
    int ans[300];int a[300][40];
    while(cin>>n>>B){
        memset(ans,0,sizeof(ans));
        int Max = -1;
        memset(a,0,sizeof(a));
        for(int i = 0 ;i <n;i++){
            scanf("%s",str);
            int len =strlen(str);
            Max = max(Max,len);
            for(int j = 0;j<len/2;j++) swap(str[j],str[len-j-1]);
            for(int j = 0;j<len;j++){
                if(str[j]>='0'&&str[j]<='9') a[i][j] = str[j] - '0';
                if(str[j]>='a'&&str[j]<='z') a[i][j] = str[j] - 'a'+10;
            }
        }
        for(int i = 0;i<Max;i++){
            int sum = 0;
            for(int j = 0;j<n;j++){
                sum+=a[j][i];
            }
            sum%=B;
            ans[i]=sum;
        }
        int pos = Max;
        while(pos>-1&&ans[pos]==0) pos--;
        if(pos==-1){
            printf("0\n");continue;
        }
        for(int i = pos;i>=0;i--){
            if(ans[i]>=0&&ans[i]<=9) printf("%d",ans[i]);
            else printf("%c",ans[i]+'a'-10);
        }
        cout<<endl;
    }
    return 0;
}
