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
    cin >> n >> q;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    vector<pair<ll,ll>> qs;
    vector<int> ans(q);
    for(int i=0;i<q;i++){
        ll x;
        cin >> x;
        qs.push_back({x, i});
    }
    sort(qs.begin(), qs.end());
    ll sum = 0;
    int p = 0;
    for(int i=0;i<n;i++){
        sum += v[i];
        while(p < q && qs[p].first < sum){
            ans[qs[p].second] = i;
            p++;
        }
    }
    while(p < q) ans[qs[p++].second] = n;
    for(auto x : ans) cout << x << "\n";
}   
