#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;


string func(set<ll> &dvsp, ll n){
    string s = to_string(n);
    bool ok = true;
    for(auto c : s) if(c == '0') ok = false;
    string rev = s;
    reverse(rev.begin(), rev.end());
    if(rev != s) ok = false;
    if(ok) return s;
    for(auto x : dvsp){
        ll d1 = x;
        string s = to_string(d1);
        reverse(s.begin(), s.end());
        ll d2 = stol(s);
        if(INF_LL/d1 < d2) continue;
        ll md = d1 * d2;
        if(n % md) continue;
        auto aux = func(dvsp, n/md);
        if(aux != "-1"){
            return to_string(d1) +'*'+ aux +'*'+ to_string(d2);
        }
    }
    return "-1";
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    cin >> n;
    set<ll> ad;
    for(ll i=2;i*i<=n;i++){
        if(!(n % i)){
            ad.insert(i);
            if(i*i != n) ad.insert(n/i);
        }
    }
    set<ll> pd;
    for(auto x : ad){
        string s = to_string(x);
        bool ok = true;
        for(auto c : s) if(c == '0') ok = false;
        if(!ok) continue;
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        if(ad.count(stol(rev)) && x <= stol(rev)) pd.insert(x);
    }
    auto s = func(pd, n);
    cout << s << "\n";

}
