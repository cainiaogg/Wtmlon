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
    string str;
    cin>>str;
    int sum = 0;
    for(int i = 0;i<str.size();i++)
        if(str[i]=='#') sum++;
    int gg = 0 ;int flag = 0;
    vector<int> q;
    int suml = 0;
    if(sum==1){
        for(int i = 0;i<str.size();i++){
            if(gg&&str[i]!=')') flag =1;
            if(str[i]=='(') suml++;
            if(str[i]=='#'){
                gg = 1; q.push_back(i+1-suml);
            }
        }
    }
    else{
        int pos;
        for(int i = 0;i<str.size();i++) if(str[i]=='#') pos = i;
        for(int i = 0;i<str.size();i++) if(str[i]=='#'&&i!=pos) q.push_back(1),str[i]=')';
        for(int i = str.size()-1;i>pos;i--) if(str[i]=='(') flag =1;
        int cntl=0;int cntr = 0;
        for(int i = 0;i<str.size();i++){
            if(cntr>cntl){
                flag = 1;break;
            }
            if(str[i]=='(') cntl++;if(str[i]==')') cntr++;
            if(str[i]=='#') {
                int ans = str.size() - i  - (cntl-cntr) -1;
                ans = -ans;
                if(ans<=0) {
                    flag = 1;break;
                }
                else{
                    q.push_back(ans);
                }
            }
        }

    }
    if(flag) printf("-1\n");
    else for(int i = 0;i<q.size();i++) printf("%d\n",q[i]);
    return 0;
}
