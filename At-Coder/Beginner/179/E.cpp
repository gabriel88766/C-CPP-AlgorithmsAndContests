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
    ll n, x, m;
    cin >> n >> x >> m;
    ll ans = 0;
    if(n <= m){
        for(int i=1;i<=n;i++){
            ans += x;
            x = (x * x) % m;
        }
        cout << ans << "\n";
        return 0;
    }
    for(int i=1;i<=m;i++){
        ans += x;
        x = (x * x) % m;
    }
    n -= m;
    vector<ll> vx;
    ll aux = x;
    while(vx.size() == 0 || aux != x){
        vx.push_back(aux);
        aux = (aux * aux) % m;
    }
    ll sv = 0;
    for(auto x : vx) sv += x;
    n--; 
    ans += (n / vx.size()) * sv;
    for(int j=0;j<= (n % vx.size()); j++) ans += vx[j];
    cout << ans << "\n";
}
