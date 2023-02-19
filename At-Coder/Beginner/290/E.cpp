#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<ll> apr[N], vec;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    ll n;
    cin >> n;
    ll ans = 0;
    for(ll i=0;i<n/2;i++){
        ans += (n-2*i)*(n-2*i-1)/2;
    }
    for(ll i=0;i<n;i++){
        int aux;
        cin >> aux;
        apr[aux].push_back(min(i+1, n-i));
    }
    
    for(int i=1;i<=n;i++){
        sort(apr[i].begin(), apr[i].end());
        for(ll j=0;j<apr[i].size();j++){
            ll val = apr[i].size();
            ans -= apr[i][j] * (val-j-1);
        }
    }
    cout << ans;
}
