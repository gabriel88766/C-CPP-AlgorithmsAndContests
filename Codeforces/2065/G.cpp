#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
int p[N], sp[N]; // 0 if prime, 1 if not prime
ll v[N], cnt[N];
void sieve(){
    for(ll i=2; i<N; i++){
        if(!p[i]){
            for(ll j = i*i; j < N; j += i){
                p[j] = 1; //marking all multiples of i as not prime
            }
        }
    }
    for(int i=2;i<N;i++){
        for(int j=2;j<N;j++){
            if(i*j >= N) break;
            if((!p[i]) && (!p[j])) sp[i*j] = 1;
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    sieve();
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1;i<=n;i++) cnt[i] = 0;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            cnt[v[i]]++;
        }
        //a[i] a[j] are distinct primes
        //a[i] is multiple of a[j] and a[j] is semi prime
        ll ans = 0;
        for(int i=2;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i*j > n) break;
                if(sp[i*j]){
                    if(j == 1){
                        ll aux = cnt[i*j];
                        ans += (aux * (aux + 1))/2;
                    }else{
                        ans += cnt[i] * cnt[i*j];
                    }
                }
            }
        }
        // cout << "\n";
        ll ps = 0;
        for(int i=2;i<=n;i++){
            if(!p[i]){
                ans += ps * cnt[i];
                ps += cnt[i];
            }
        }
        cout << ans << "\n";
    }
}
