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

string deal(string str,int a,int b)
{
    for(int i = 0;i<a;i++){
        for(int j = 0;j<str.size();j++){
            if(str[j]=='9') str[j] = '0';
            else str[j] = str[j]+1;
        }
    }
    string str1;
    str1 = str;
    for(int i = 0;i<str.size();i++){
        str[i] = str1[(i+b)%str.size()];
    }
    return str;
}

int main()
{
    int n;
    string str;
    cin>>n;
    cin>>str;
    string Min ;
    Min = str;
    for(int i = 0;i<=9;i++){
        for(int j = 0;j<1000;j++){
            Min = min(Min,deal(str,i,j));
        }
    }
    cout<<Min<<endl;
    return 0;
}
