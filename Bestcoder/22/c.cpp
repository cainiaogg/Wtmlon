#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<math.h>
#include<algorithm>
using namespace std;
double pi = acos(-1);
double g  = 9.8;
int h,v;
double gao(double v,double h,double d)
{
    double t  = sqrt(v*v*sin(d)*sin(d)/g/g+2*h/g) + v*sin(d)/g;
    return t*v*cos(d);
}

void solve()
{
    double l = 0; double r = pi/2;
    double Max = -1;
    for(int i = 0;i<30;i++){
        double mid = (l+r)/2.0;
        double midmid = (mid+r)/2.0;
        double midans = gao(v,h,mid);
        double midmidans = gao(v,h,midmid);
        if(midans>=midmidans) r=midmid;
        else l = mid;
    }

    printf("%.2f\n",max(gao(v,h,l),gao(v,h,r)));
}

int main()
{
    int T;
    cin>>T;
    while(T--){
        double Max = -1;
        cin>>h>>v;
        solve();
    }
    return 0;
}
