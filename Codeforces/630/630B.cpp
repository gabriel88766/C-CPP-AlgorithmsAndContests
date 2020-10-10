#include <bits/stdc++.h>

using namespace std;

long double fexp(long double n,long long int x){
    long double res = 1;
    while(x){
        if(x%2) res = res*n;
        n*=n;
        x>>=1;
    }
    return res;
}

int main(){
long double fac = 1.000000011;
long long int n,x;
cin >> n >> x;
long double ans = n * fexp(fac,x);
cout << setprecision(25) << ans;

}
