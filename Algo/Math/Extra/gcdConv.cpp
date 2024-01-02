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
ll a[N], b[N], tt[N], ttg[N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    mobius();
    ll n;
    cin >> n;
    vector<ll> a(n+1), b(n+1);
    for(int i=1;i<=n;i++){
        cin >> a[i];
    }    
    for(int i=1;i<=n;i++){
        cin >> b[i];
    }    
    for(int i=1;i<=n;i++){
        ll sum1 = 0, sum2 = 0;
        for(int j=i;j<=n;j+=i){
            sum1 += a[j];
        }
        for(int j=i;j<=n;j+=i){
            sum2 += b[j];
        }
        sum1 %= MOD;
        sum2 %= MOD;
        tt[i] = (sum1 * sum2) % MOD;
    }
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j+=i){
            ttg[i] += tt[j] * mi[j/i];
        }
    }
    for(int i=1;i<=n;i++){
        ll now = ttg[i] % MOD;
        if(now < 0) now += MOD;
        cout << now << " ";
    }
    cout << "\n";
    
}
