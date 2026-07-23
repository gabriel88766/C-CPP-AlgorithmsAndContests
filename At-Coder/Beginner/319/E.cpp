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
    ll n, x, y;
    cin >> n >> x >> y;
    vector<pair<ll, ll>> pt(n-1);
    for(int j=0;j<n-1;j++) cin >> pt[j].first >> pt[j].second;
    vector<ll> qnt(840);
    for(int j = 0; j < 840; j++){
        ll cur = j;
        for(auto [p, t] : pt){
            ll r = cur % p;
            ll nd = r ? p - r : 0;
            cur += nd + t;
        }
        qnt[j] = cur - j;
    }
    int q;
    cin >> q;
    for(int i=1;i<=q;i++){
        ll cur;
        cin >> cur;
        cur += x;
        cur += qnt[cur % 840];
        cur += y;
        cout << cur << "\n";
    }
}
