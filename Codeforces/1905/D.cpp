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
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> v(n);
        vector<int> pos(n);
        vector<ll> ans(n);
        for(int i=0;i<n;i++){
             cin >> v[i];
             pos[v[i]] = i;
        }
        set<int> s;
        s.insert(pos[0]);
        for(ll i=1;i<n;i++){
            auto it = s.lower_bound(pos[i]);
            int r = it == s.begin() ? *prev(s.end()) : *prev(it);
            int l = it == s.end() ? *s.begin() : *it;   
            ll cnt = pos[i] - r;
            if(cnt < 0) cnt += n;
            int p = (pos[i]+1)%n;
            ll upd = cnt * i;
            ans[p] += upd;
            if(l+1 < n) ans[l+1] -= upd;
            if(p > l) ans[0] += upd;
            s.insert(pos[i]);
        }
        ll anss = 0;
        for(int i=0;i<n;i++){
            if(i != 0) ans[i] += ans[i-1];
            anss = max(anss, ans[i] + n);
        }

        cout << anss << "\n";
    }
}