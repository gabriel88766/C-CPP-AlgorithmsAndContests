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
    // t = 1;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<ll> ps(n+1);
        for(int i=1;i<=n;i++){
            cin >> ps[i];
            ps[i] += ps[i-1];
        }
        for(int i=0;i<q;i++){
            ll a, b, k;
            cin >> a >> b >> k;
            ll sum = ps[n] - (ps[b]-ps[a-1]);
            sum += (b-a+1)*k;
            if(sum % 2) cout << "YES\n";
            else cout << "NO\n";
        }
    }
}
