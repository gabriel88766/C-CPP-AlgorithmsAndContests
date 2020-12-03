#include <bits/stdc++.h>

using namespace std;

const int MOD = 1e9+7;

long long int fastexp(long long int n,long long int k,long long int mod){
    if(k==0) return 1;
    if(k==1) return n%mod;
    if(k%2) return (fastexp((n*n)%mod,k/2,mod)*n)%mod;
    else return (fastexp((n*n)%mod,k/2,mod))%mod;

}

int main(){
    int n;
    cin >>n;
    cout << fastexp(2,n,MOD);

}
