#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353;
const int INF_INT = 0x3f3f3f3f;
const double PI = acos(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n;
    cin >> n;
    ll cur = 1;
    vector<ll> v;
    while(cur <= n){
        ll curn = n/cur;
        ll mn = n/curn;
        v.push_back(curn);
        cur = mn + 1;
    }
    reverse(v.begin(), v.end());
    cout << v.size() << "\n";
    for(auto x : v) cout << x << " ";
}
