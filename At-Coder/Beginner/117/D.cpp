#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int M = 40;
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    vector<ll> cnt(M);
    ll ans = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        ans += a[i] ^ k;
        for(int j=0;j<M;j++){
            if(a[i] & (1LL << j)) cnt[j]++;
        }
    }
    for(int j=0; j < M; j++){
        //j is the first bit 1 -> 0 in k
        if(!(k & (1LL << j))) continue;
        ll cur = 0;
        for(int u=M-1;u>j;u--){
            if(k & (1LL << u)) cur += (n - cnt[u]) * (1LL << u);
            else cur += cnt[u] * (1LL << u); 
        }
        cur += cnt[j] * (1LL << j);
        for(int u=j-1;u>=0;u--){
            if(cnt[u] < n - cnt[u]) cur += (n - cnt[u]) * (1LL << u);
            else cur += cnt[u] * (1LL << u);
        }
        ans = max(ans, cur);
    }
    cout << ans << "\n";
    
}
