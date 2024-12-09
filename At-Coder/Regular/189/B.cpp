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
    int n;
    cin >> n;
    vector<ll> v(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    ll bg = v[1];
    vector<ll> dif[2];
    for(int i=2;i<=n;i++){
        dif[i%2].push_back(v[i] - v[i-1]);
    }
    for(int i=0;i<2;i++) sort(dif[i].begin(), dif[i].end(), greater<ll>());
    ll sum = bg;
    for(int i=2;i<=n;i++){
        bg += dif[i%2].back();
        dif[i%2].pop_back();
        sum += bg;
    }
    cout << sum << "\n";
}
