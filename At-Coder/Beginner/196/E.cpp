#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n;
    vector<pair<ll, ll>> fcs(n);
    for(int i=0;i<n;i++){
        cin >> fcs[i].first >> fcs[i].second;
    }
    cin >> q;
    vector<int>  qr;
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        qr.push_back(x);
    }
    int mn = *min_element(qr.begin(), qr.end());
    int mx = *max_element(qr.begin(), qr.end());
    auto calc = [&](int x){
        ll ans = x;
        for(auto [a, t] : fcs){
            if(t == 1) ans += a;
            if(t == 2) ans = max(ans, a);
            if(t == 3) ans = min(ans, a);
        }
        return ans;
    };
    auto beg = calc(mn);
    auto fin = calc(mx);
    if(beg == fin){
        while(q--) cout << beg << "\n";
        return 0;
    }else{
        ll mx1 = mn;
        for(int jmp = mx - mn; jmp >= 1; jmp>>=1){
            while(calc(mx1 + jmp) == beg) mx1 += jmp;
        }
        ll mx2 = mx1 + fin - beg;
        for(auto x : qr){
            if(x <= mx1) cout << beg << "\n";
            else if(x <= mx2) cout << x - mx1 + beg << "\n";
            else cout << fin << "\n";
        }
    }
}
