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
    ll l, r, k;
    cin >> l >> r >> k;
    ll aux = 1;
    vector<ll> ans;
    if(aux >= l) ans = {1};
    while(r/k >= aux){
        aux *= k;
        if(aux >= l) ans.push_back(aux);
    }
    if(ans.size()) for(auto x : ans) cout << x << " ";
    else cout << "-1\n";
}
