#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, q;
        cin >> n >> q;
        vector<ll> ps(n+1,0), maxl(n+1, 0);
        for(int i=1;i<=n;i++){
            ll aux;
            cin >> aux;
            ps[i] = ps[i-1] + aux;
            maxl[i] = max(maxl[i-1], aux);
        }
        for(int i=1;i<=q;i++){
            ll x;
            cin >> x;
            int j = upper_bound(maxl.begin(), maxl.end(), x) - maxl.begin();
            j--;
            cout << ps[j] << " ";
        }
        cout << "\n";
    }
}
