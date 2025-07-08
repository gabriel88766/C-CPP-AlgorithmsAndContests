#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll binpow(ll a, ll b, ll m){
    a %= m;
    ll ans = 1;
    while(b > 0){
        if(b & 1) ans = (ans * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return ans;
}


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int a, b, c;
    cin >> a >> b >> c;
    a %= 10;
    vector<bool> used(10, false);
    used[a] = true;
    vector<int> xg = {a};
    while(!used[(xg.back() * a) % 10]){
        xg.push_back((xg.back() * a) % 10);
        used[xg.back()] = true;
    }
    int r = binpow(b, c, xg.size()); 
    //if r = 1, then 0, if r = 2, then 1, and so on
    r--;
    if(r < 0) r += xg.size();
    cout << xg[r] << "\n";
}
