#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+1;
vector<ll> b[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    for(int i=0;i<n;i++){
        ll aux;
        cin >> aux;
        b[v[i]].push_back(aux);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        sort(b[i].begin(), b[i].end(), greater<ll>());
        for(int j=1;j<b[i].size();j++) ans += b[i][j];
    }
    cout << ans << "\n";
    
}
