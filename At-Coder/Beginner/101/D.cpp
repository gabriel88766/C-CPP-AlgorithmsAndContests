#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

vector<ll> snk = {1, 2, 3, 4, 5, 6, 7, 8, 9, 19, 29, 39, 49, 59, 69, 79, 89, 99};
//cout << fixed << setprecision(6)
ll sdig(ll n){
    ll ans = 0;
    while(n){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=0;i<=12;i++){
        ll aux = 1;
        for(int j=0;j<i;j++) aux *= 10;
        double low = 1e30;
        vector<ll> v;
        for(int j=999;j>=100;j--){
            ll cur = j * aux + (aux - 1);
            ll s = sdig(cur);
            double d = ((double) cur)/s;
            if(d + EPS < low){
                v.push_back(cur);
                low = d;
            }
        }
        reverse(v.begin(), v.end());
        for(auto x : v) snk.push_back(x);
    }
    int k;
    cin >> k;
    for(int i=0;i<k;i++) cout << snk[i] << "\n";
}
