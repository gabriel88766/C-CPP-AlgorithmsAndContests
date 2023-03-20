#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll p;
    cin >> p;
    ll an = p-1;
    ll aux = an;
    vector<ll> div, f;
    for(ll i = 1; i*i <= an; i++){
        if(!(an%i)){
            if(i != 1){
                if(!(aux%i)){
                    while(!(aux % i)){
                        aux /= i;
                    }
                    f.push_back(i);
                }
            }
            div.push_back(i);
            if(i*i != an) div.push_back(an/i);
        }
    }
    if(aux != 1) f.push_back(aux);
    sort(div.begin(), div.end());
    ll ans = 1;
    for(auto x: div){
        aux = an/x;
        ll phi = aux;
        for(auto y : f) if(!(phi%y)) phi -= phi/y;
        ans = (ans + (aux%MOD)*(phi%MOD)) % MOD;
    }
    cout << ans;
}
