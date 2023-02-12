#include <bits/stdc++.h>

typedef long long int ll;
const ll MOD = 1e9+7;
using namespace std;

ll binpow(ll a, ll  b, ll  m = MOD){
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

int main(){
    ll m, n;
    cin >> m >> n;
    cout << binpow(m, n) << "\n";
}