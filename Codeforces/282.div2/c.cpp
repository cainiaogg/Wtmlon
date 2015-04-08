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

int a[111111];
int main()
{
    string str;
    vector<int>q;
    int pos;
    cin>>str;
    memset(a,0,sizeof(a));
    for(int i = 0;i<str.size();i++) if(str[i]=='#') pos = i;
    for(int i = 0;i<str.size();i++) if(str[i]=='#'&&i!=pos) str[i]=')',q.push_back(1);
    for(int i = 0;i<str.size();i++) if(str[i]=='(') a[i] = -1;
    else if(str[i]==')') a[i] = 1;
    int sum = 0;
    int flag =0;
    for(int i = 0;i<str.size();i++) sum+=a[i];
    if(sum>=0) flag = 1;
    else {a[pos] = -sum;q.push_back(a[pos]);}
    int cntl = 0;int  cntr = 0;
    for(int i = 0;i<str.size();i++){
        if(a[i]>0) cntr+=a[i];
        else cntl+=-a[i];
        if(cntr>cntl) {
            flag = 1;break;
        }
    }
    if(flag){
        printf("-1\n");
    }
    else for(int i = 0;i<q.size();i++) printf("%d\n",q[i]);
    return 0;
}
