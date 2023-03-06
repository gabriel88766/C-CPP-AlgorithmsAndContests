#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll ans = 0;
ll av[400005], v[200005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll ans = 0;
        vector<ll> av(n+m+1), v(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            av[v[i]] = m+1;
        }
        for(int i=1;i<=m;i++){
            int a, b;
            cin >> a >> b;
            av[v[a]] -= (m-i+1);
            av[b] += (m-i+1);
            v[a] = b;
        }
        for(int i=1;i<=(n+m);i++){
            if(av[i]) ans += (av[i] * (m+1 - av[i])) + (av[i]*(av[i]-1))/2;
        }
        cout << ans << "\n";
    }
}
