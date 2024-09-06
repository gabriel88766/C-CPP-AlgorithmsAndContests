#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ull mult(ull a, ull  b, ull  m){
    __int128 res = (unsigned __int128)a * b % m;
    return (ull)res;
}

ull binpow(ull a, ull b, ull m){
    a %= m;
    ull ans = 1;
    while(b){
        if(b & 1) ans = mult(ans, a, m);
        a = mult(a, a, m);
        b >>= 1;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll m, x;
    cin >> m >> x;
    ll aux = m;
    vector<ll> fp;
    for(ll i=2;i*i<=aux;i++){
        if(!(aux % i)){
            fp.push_back(i);
            while(!(aux % i)) aux /= i;
        }
    }
    if(aux != 1) fp.push_back(aux);
    ll phi = m;
    for(auto y : fp){
        phi /= y;
        phi *= (y-1);
    }
    assert(binpow(x, phi, m) == 1);
    ll bp = phi;
    for(auto y : fp){
        while((!(bp % y)) && binpow(x, bp/y, m) == 1) bp /= y;
    }
    ll ans = 0; //equiv 0
    vector<ll> db;
    for(ll i=1;i*i<=bp;i++){
        if(!(bp % i)){
            db.push_back(i);
            if(i*i != bp) db.push_back(bp/i);
        }
    }
    sort(db.begin(), db.end());
    map<ll, ll> ansd;
    for(auto y : db){
        ll cur = binpow(x, y, m) - 1;
        // cur * x == 0 mod m
        ll minv = m;
        for(auto y : fp){
            while((!(minv % y)) && mult(minv/y, cur, m) == 0) minv /= y;
        }
        ansd[y] = m/minv;
    }
    //TLE :)
    for(int i=0;i<db.size();i++){
        if(ansd[db[i]] != 0){
            ans += ansd[db[i]] / db[i];
            for(auto y : db){
                if(y == db[i]) continue;
                if(!(y % db[i])) ansd[y] -= ansd[db[i]];
            }
        }
    }
    cout << ans << "\n";

}
