#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    map<ll, ll> mp;
    ll cur;
    cin >> cur;
    ll cnt = 0;
    int c = 0;
    do{
        mp[cur] = cnt;
        ll x = c > 100 ?  uniform_int_distribution<ll>(1, 1000000)(rng) : 1;
        cout << "+ " << x << "\n";
        cout.flush();
        cnt += x;
        cin >> cur;
        ++c;
    }while(!mp.count(cur));
    ll mult = cnt - mp[cur];
    ll aux = mult;
    vector<ll> fact;
    for(ll i = 2; i * i <= mult; i++){
        if(!(aux % i)){
            fact.push_back(i);
            while(!(aux % i)) aux /= i;
        }
    }
    if(aux != 1) fact.push_back(aux);
    bool ok;
    aux = mult;
    do{
        ok = false;
        ll newv;
        for(auto x : fact){
            if(!(aux % x)){
                ll newaux = aux / x;
                cout << "+ " << newaux << "\n";
                cout.flush();
                cin >> newv;
                if(newv == cur){
                    ok = true;
                    aux = newaux;
                    break;
                }
                cur = newv;
            }
        }
    }while(ok);
    cout << "! " << aux << "\n";
    cout.flush();
}