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
    map<int, vector<int>> mp;
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        mp[x].push_back(i);
    }
    ll ans = 0;
    for(auto &[k, v] : mp){
        int bg = 1;
        for(auto &x : v){
            ll lf = x - bg + 1;
            ll rg = n - x + 1;
            ans += lf*rg;
            bg = x + 1;
        }
    }
    cout << ans << "\n";
}
