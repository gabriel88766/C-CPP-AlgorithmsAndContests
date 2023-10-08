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
    map<ll, ll> mp;
    //test ' O ' 
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        ll a, b;
        cin >> a >> b;
        mp[a] = b;
    }
    ll ans = 0;
    for(auto x : mp){
        ans += x.second % 2;
        if(x.second > 1) mp[x.first * 2] += x.second / 2;
    }
    cout << ans << "\n";

}
