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
    int n, k;
    cin >> n >> k;
    ll x, a, b, c;
    cin >> x >> a >> b >> c;
    vector<int> v = {(int)x};
    while(v.size() < n){
        x = a*x + b;
        x %= c;
        v.push_back(x);
    }
    ll sum = 0;
    ll ans = 0;
    for(int i=0;i<n;i++){
        sum += v[i];
        if(i >= k-1){
            ans ^= sum;
            sum -= v[i-k+1];
        }
    }
    cout << ans << "\n";
}
