#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll a, b;
void getrc(vector<ll> &cur, ll mx, ll ox){
    //from cur, want to go 
    vector<ll> nv;
    for(ll i = mx-21;i<=mx-1;i++){
        bool ok = false;
        for(auto &x : cur){
            if(x == i) ok = true;
            else if(i < x) continue;
            else{
                ll q = (i - x) / a;
                ll r = (i - x) % a;
                if((b-a) * q >= r) ok = true; 
            }
        }
        if(ok) nv.push_back(i);
    }
    for(auto &x : cur) if(x > ox) nv.push_back(x);
    cur = nv;
}


void getpc(vector<ll> &cur, ll mn){
    vector<ll> nv;
    for(ll i=mn+1;i<=mn+20;i++){
        bool ok = false;
        for(auto &x : cur){
            if(x == i) ok = true;
            if(x > i) continue;
            ll d = i - x;
            if(d >= a && d <= b) ok = true;
        }
        if(ok) nv.push_back(i);
    }
    cur = nv;
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, m;
    cin >> n >> m >> a >> b;
    vector<ll> pl;
    pl.push_back(1);
    for(int i=0;i<m;i++){
        ll l, r;
        cin >> l >> r;
        // while(pl.size() && pl.back() >= l) pl.pop_back()
        if(pl.size() == 0) break;
        getrc(pl, l, r);
        getpc(pl, r);
    }
    while(pl.size() && pl.back() > n) pl.pop_back();
    getrc(pl, n+1, INF_LL);
    if(pl.back() == n) cout << "Yes\n";
    else cout << "No\n";
}
