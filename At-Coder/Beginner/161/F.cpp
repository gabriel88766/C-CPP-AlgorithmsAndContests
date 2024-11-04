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
    vector<ll> ans;
    ll n;
    cin >> n;
    for(ll i=1;i*i<=(n-1);i++){
        if(!((n-1) % i)){
            if((n-1)/i != i) ans.push_back((n-1)/i);
            if(i != 1) ans.push_back(i);
        }
    }
    vector<ll> chk;
    for(ll i=1;i*i<=n;i++){
        if(!(n % i)){
            if(i != 1) chk.push_back(i);
            if(n/i != i) chk.push_back(n/i);
        }
    }
    for(auto x : chk){
        ll aux = n;
        while(!(aux % x)) aux /= x;
        if(aux % x == 1) ans.push_back(x);
    }
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size() << "\n";
}
