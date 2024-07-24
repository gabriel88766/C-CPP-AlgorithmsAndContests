#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const ll N = 1e6+1;
ll ps[N];
ll cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i=0;i<n;i++){
         cin >> v[i];
         cnt[v[i]]++;
         ps[v[i]]++;
    }
    sort(v.begin(), v.end());
    for(int i=2;i<N;i++) ps[i] += ps[i-1];

    ll ans = 0;
    for(ll i=1;i<N;i++){
        for(ll d=1;i*d<N;d++){
            ll l = i*d;
            ll r = min(N-1, l+i-1);
            if(d == 1) l++;
            if(r < l) continue; //d == 1, i == 1
            ans += (ps[r] - ps[l-1]) * cnt[i] * d;
        }
        ans += (cnt[i]*(cnt[i]-1))/2;
    }

    cout << ans << "\n";
}
