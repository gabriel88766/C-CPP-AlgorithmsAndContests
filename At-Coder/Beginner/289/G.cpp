#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n, m;
    cin >> n >> m;
    vector<ll> v(n+1), w(m+1),  ans(m+1), ps(n+1);
    vector<pair<ll,ll>> gr(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    sort(v.begin()+1, v.end());
    for(int i=1;i<=m;i++) cin >> w[i];


    int bp = 1, ep = 2;
    while(ep <= n){
        ll lo = 0, hi = 1e9+1, mid;
        ll fac1 = n-bp+1;
        ll fac2 = n-ep+1;
        if(fac1*v[bp] >= fac2*v[ep]){
            ep++;
            continue;
        }
        while(lo != hi){
            mid = (lo+hi)/2;
            ll fac3 = mid + v[bp];
            ll fac4 = mid + v[ep];
            if(fac1*fac3 >= fac4*fac2) hi = mid;
            else lo = mid+1;
        }
        gr[bp] = {lo, ep};
        bp = ep;
        ep++;
    }
    for(int i=1;i<n;i++){
        if(gr[i].first == 0 && i < gr[i-1].second){
            gr[i] = {gr[i-1].first, gr[i-1].second};
        }
    }
    for(int i=1;i<=m;i++){
        
        int bp = 1, jmp = n/2;
        for(int j = jmp; j > 0; j/=2){
            while(bp+j <=n && gr[bp+j].first > w[i]) bp += j;
        }
        if(gr[bp+1].first <= w[i] && gr[bp].first > w[i]) bp++;
        ans[i] = (n-bp+1) * (v[bp] + w[i]);
    
        
    }   

    for(int i=1;i<=m;i++) cout << ans[i] << " ";

}
