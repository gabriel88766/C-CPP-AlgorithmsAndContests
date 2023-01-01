#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

//Evaluate a^n == mod m -- O(log n)
ll binpow(ll a, ll  b, ll  m){
    a %= m;
    ll res = 1;
    while(b > 0){
        if(b & 1) 
            res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    for(int i=0; i< n; i++){
        ll a,b,c;
        cin >> a >> b >> c;
        cout << binpow(a, binpow(b, c, 1e9+6), 1e9+7) << "\n";
    }
}
