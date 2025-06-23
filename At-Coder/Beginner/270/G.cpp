#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;



pair<ll, ll> comb(pair<ll, ll> a, pair<ll, ll> b, ll p){
    ll fa = a.first * b.first;
    ll fb = a.first * b.second + a.second; 
    return {fa % p, fb % p};
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll a, p, b, s, g;
        cin >> p >> a >> b >> s >> g;
        if(s == g){
            cout << "0\n";
            continue;
        }
        vector<pair<ll, ll>> fs(31);
        fs[0] = {a, b};
        for(int i=1;i<=30;i++){
            fs[i] = comb(fs[i-1], fs[i-1], p);
        }
        int md = sqrt(p) + 2;
        map<int, int> mp;
        ll x = g;
        bool nok = false;
        for(int i=0;i<md;i++){
            if(!mp.count(x)) mp[x] = i;
            else nok = true;
            x = (a * x + b) % p;
        }
        if(nok){
            bool ok = false;
            x = s;
            for(int i=1;i<=md;i++){
                x = (a * x + b) % p;
                if(x == g){
                    ok = true;
                    cout << i << "\n";
                    break;
                }
            }
            if(!ok) cout << "-1\n";
        }else{
            pair<ll, ll> f = {1, 0};
            for(int i=0;i<=30;i++){
                if(md & (1 << i)) f = comb(f, fs[i], p);
            }
            bool ok = false;
            for(int i=1;i<=md;i++){
                s = (f.first * s + f.second) % p;
                if(mp.count(s)){
                    ok = true;
                    cout << md * i - mp[s] << "\n";
                    break;
                }
            }
            if(!ok) cout << "-1\n";
        }
    }

}
