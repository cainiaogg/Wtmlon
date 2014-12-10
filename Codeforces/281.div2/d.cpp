#include<stdio.h>
#include<iostream>
#include<math.h>
#include<string.h>
#include<queue>
#include<algorithm>
using namespace std;

int main()
{
    int n;
    cin>>n;
    if(n&1){
        cout<<"black"<<endl;
        return 0;
    }
    else printf("white\n1 2\n");
    return 0;
}
