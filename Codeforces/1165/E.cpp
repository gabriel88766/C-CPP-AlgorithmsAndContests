#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
ll a[N], b[N], c[N], ord[N];

bool func(ll a, ll b){
    return c[a] < c[b];
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
    for(int i=0;i<n;i++) cin >> b[i];
    for(ll i=0;i<n;i++) c[i] = (i+1)*(n-i)*a[i];
    
    for(int i=0;i<n;i++) ord[i] = i;
    sort(b, b + n, greater<ll>());
    sort(ord, ord + n, func);
    for(int i=0;i<n;i++) c[i] = c[i] % MOD;
    ll ans = 0;
    for(int i=0;i<n;i++) ans = (ans + b[i]*c[ord[i]]) % MOD;
    cout << ans;
}
