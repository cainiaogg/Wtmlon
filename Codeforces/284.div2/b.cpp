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
    int n,m;
    string str,str1;
    cin>>n>>m;
    map<string ,string> Map;
    for(int i = 0;i<m;i++){
        cin>>str>>str1;
        if(str.size()<=str1.size()){
            Map[str] = str; Map[str1] = str;
        }
        if(str.size()>str1.size()){
            Map[str] = str1; Map[str1] = str1;
        }
    }
    for(int i = 0 ;i<n;i++){
        cin>>str;
        cout<<Map[str]<<" ";
    }
    cout<<endl;
    return 0;
}
