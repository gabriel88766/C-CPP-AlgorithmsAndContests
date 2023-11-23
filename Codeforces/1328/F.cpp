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
    int n, k;
    cin >> n >> k;
    vector<ll> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(), v.end());
    ll ans = INF_LL;
    ll s1 = 0, s2 = 0;
    for(int i=0;i<n;i++) s2 += v[i];

    auto x = v;
    x.resize(unique(x.begin(), x.end()) - x.begin());
    vector<ll> cntg(x.size());
    vector<ll> cntl(x.size());
    vector<ll> cnt(x.size());
    int p = 0;
    for(int i=0;i<n;i++){
        if(v[i] != x[p]) p++;
        cnt[p]++;
    }
    for(int i=0;i<x.size();i++){
        if(i){
            cntg[i] = cntg[i-1] - cnt[i];
        }else cntg[i] = n - cnt[i];
    }
    for(int i=x.size()-1;i>=0;i--){
        if(i != x.size() - 1){
            cntl[i] = cntl[i+1] - cnt[i];
        }else cntl[i] = n - cnt[i];
    }

    for(int i=0;i<x.size();i++){
        s2 -= x[i] * cnt[i];
        //cout << s1 << " " << s2 << " " << cnt[i] << " " << cntl[i] << " " << cntg[i] << "\n";
        ll cur = INF_LL;
        if(cnt[i] >= k){
            ans = 0;
            break;
        } 
        ll c1 = cntl[i] * (x[i] - 1) - s1;
        ll c2 = s2 - cntg[i] * (x[i] + 1);
        if(cntl[i] + cnt[i] >= k){
            ll qt = k - cnt[i];
            cur = min(cur, c1 + qt);
        }
        if(cntg[i] + cnt[i] >= k){
            ll qt = k - cnt[i];
            cur = min(cur, c2 + qt);
        }
        cur = min(cur, c1 + c2 + k-cnt[i]);
        ans = min(ans, cur);
        s1 += x[i] * cnt[i];
    }
    cout << ans << "\n";
}
