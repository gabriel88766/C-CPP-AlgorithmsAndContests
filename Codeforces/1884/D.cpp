#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e6+1;
ll mi[N], p[N];
void mobius(){ //another sieve.
    for(ll i =1; i<N;i++) mi[i] = 1;
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i; j < N; j += i){
                p[j] = 1, mi[j] *= -1;
            }
            for(ll j = i*i; j < N; j += i*i){
                mi[j] = 0;
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    mobius();
    int t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        ll ans = (n * (n-1))/2;
        vector<ll> a(n+1), cnt(n+1);
        for(int i=1;i<=n;i++){
            cin >> a[i];
            cnt[a[i]]++;
        }    
        vector<ll> tt(n+1), ttg(n+1); //total of pairs with some divisor in common from 1 to n
        for(int i=1;i<=n;i++){
            if(cnt[i]){
                ans -= (cnt[i] * (cnt[i] - 1)) >> 1;
            }
            ll sum = 0;
            for(int j=i;j<=n;j+=i){
                if(cnt[j]) sum += cnt[j];
            }
            for(int j=i;j<=n;j+=i){
                if(cnt[j]){
                    sum -= cnt[j];
                    tt[i] += cnt[j] * sum;
                }
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=i;j<=n;j+=i){
                ttg[i] += tt[j] * mi[j/i];
            }
        }
        //vector<ll> ctd(n+1);
        vector<int> vis(n+1, false);
        for(int i=1;i<=n;i++){
            if(!cnt[i]) continue;
            for(int j=i;j<=n;j+=i){
                vis[j] = true;
            }
        }
        for(int i=1;i<=n;i++){
            if(vis[i]){ // 1 or greater
                ans -= ttg[i];
            }
        }
        cout << ans << "\n";
    }
}
