#include <bits/stdc++.h>

using namespace std;

int main(){
long long int d,k,a,b,t,nmax,nmin,ans1,ans2,ans3,minans;
cin >> d >> k >> a >> b >> t;
long long int fac = k*a + t - b*k;
nmax = d/k;
nmin = min((long long int)1,nmax);

    if(nmin!=0) ans1 = nmin*fac + b*d - t;
    else ans1 = d*a;
    if(nmax!=0) ans2 = nmax*fac + b*d - t;
    else ans2 = d*b;
    if(nmin!=0) ans3 = ans2 - b*(d-nmax*k) + (d-nmax*k) * a + t;
    else ans3 = 1e18;

cout << min(min(ans1,ans2),ans3);
}
