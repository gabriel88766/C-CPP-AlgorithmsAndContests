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
        ll ans = 0;
        int n;
        cin >> n;
        vector<ll> v(n+1);
        for(int i=1;i<=n;i++){
            cin >> v[i];
        }
        //first unassigned
        for(int i=2;i<=n;i++) ans -= v[i];
        ll cur = ans;
        for(int i=2;i<=n;i++){
            cur += v[i]; //i is unassigned
            if(i == 2){
                cur += v[i-1];
            }else cur += abs(v[i-1]);
            ans = max(ans, cur);
        }
        cout << ans << "\n";

    }
}
