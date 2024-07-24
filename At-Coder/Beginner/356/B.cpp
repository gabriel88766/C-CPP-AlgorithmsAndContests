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
    int n, m;
    cin >> n >> m;
    vector<ll> g(m), sum(m);
    for(int i=0;i<m;i++) cin >> g[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ll x;
            cin >> x;
            sum[j] += x;
        }
    }
    bool ok = true;
    for(int i=0;i<m;i++) if(g[i] > sum[i]) ok = false;
    if(ok) cout << "Yes\n";
    else cout << "No\n";
}
