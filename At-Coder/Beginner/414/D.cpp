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
    ll n, m;
    cin >> n >> m;
    vector<ll> av(n);
    for(int i=0;i<n;i++) cin >> av[i];
    sort(av.begin(), av.end());
    vector<ll> df;
    ll ans = av.back() - av[0];
    for(int i=1;i<n;i++) df.push_back(av[i] - av[i-1]);
    sort(df.begin(), df.end(), greater<ll>());
    for(int i=0;i<m-1;i++) ans -= df[i];
    cout << ans << "\n";
}
