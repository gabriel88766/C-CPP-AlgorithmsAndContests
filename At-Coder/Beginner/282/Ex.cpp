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
    //I THINK THIS WILL BE N LOG^2 N, BUT NOT SURE!!
    ll n, s;
    cin >> n >> s;
    vector<pair<ll, ll>> va(n);
    vector<ll> ps(n+1);
    for(int i=0;i<n;i++){
        cin >> va[i].first;
        va[i].second = i + 1;
    }
    for(int i=1;i<=n;i++){
        cin >> ps[i];
        ps[i] += ps[i-1];
    }
    sort(va.begin(), va.end());
    set<int> brd;
    brd.insert(0);
    brd.insert(n+1);
    ll ans = 0;
    for(auto [av, j] : va){
        auto it = brd.lower_bound(j);
        int r = *it - 1;
        int l = *prev(it) + 1;
        if(j - l < r - j){
            for(int u=l;u<=j;u++){
                ll cs = av + ps[j] - ps[u-1];
                if(cs > s) continue;
                ll ms =  s - cs + 1 + ps[j];
                auto it = lower_bound(ps.begin() + j, ps.begin() + r + 1, ms);
                ans += it - ps.begin() - j;
            }
        }else{
            for(int u=j;u<=r;u++){
                ll cs = av + ps[u] - ps[j-1];
                if(cs > s) continue;
                //ps[j-1] - ps[x] + cs <= s
                //ps[x] >= cs - s + ps[j-1]
                auto it = lower_bound(ps.begin() + l - 1, ps.end(), cs - s + ps[j-1]);
                ans += j - (it - ps.begin());
            }
        }
        brd.insert(j);
    }
    cout << ans << "\n";
}
