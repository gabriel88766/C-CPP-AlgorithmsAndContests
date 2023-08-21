#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;   
int p[N], sz[N];

void init(int n){
    for(int i=1;i<=n;i++) {p[i] = i; sz[i] = 1;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}

ll binpow(ll a, ll b, ll m = MOD){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        ll n, k;
        cin >> n >> k;
        init(n);
        vector<pair<ll, pair<ll,ll>>> vp(n-1);
        for(int i=0;i<n-1;i++){
            cin >> vp[i].second.first >> vp[i].second.second >> vp[i].first;
        }
        sort(vp.begin(), vp.end());
        ll ans = 1;
        vector<pair<ll,ll>> auxans;
        for(int i=0;i<n-1;i++){
            ll k1 = sz[get(vp[i].second.first)];
            ll k2 = sz[get(vp[i].second.second)];
            unite(vp[i].second.first, vp[i].second.second);
            auxans.push_back({(k1*k2-1), k-vp[i].first});
        }
        for(auto x : auxans){
            ans = (ans * binpow(1+x.second, x.first)) % MOD;
        } 
        cout << ans << "\n";
    }
}
