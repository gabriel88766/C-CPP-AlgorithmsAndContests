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
    int t;
    cin >> t;
    while(t--){
        ll n, k, q;
        cin >> n >> k >> q;
        vector<ll> v(n+1);
        vector<ll> pos;
        int li = 1;
        for(int i=1;i<=n;i++){
            cin >> v[i];
            if(v[i] > q){
                if(li != i) pos.push_back(i-li);
                li = i+1;
            }
        }
        if(li != (n+1)) pos.push_back(n+1-li);
        ll ans = 0;
        for(auto x : pos){
            if(x >= k){
                ans += ((x - k + 1)*(x - k + 2))/2;
            }
        }
        cout << ans << "\n";
    }
}
