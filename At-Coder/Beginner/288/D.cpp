#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+6;
ll v[N];
int n;


//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int  k, q;
    cin >> n >> k;
    vector<ll> u(n+1), ps(n+1, 0);
    for(int i=1;i<=n;i++) {
        cin >> u[i];
        ps[i] = ps[i-1] + u[i];
    }
    //cout << "\n";
    cin >> q;
    for(int i=1;i<=q;i++){
        int l, r;
        cin >> l >> r;
        //aux = -u[l];
        bool ok = true;
        for(int j= r-k+2; j<=r;j++){
            ll aux = ps[r-k+1] - ps[j-k-1 > 0 ? j-k-1 : 0];
            cout << r-k+1 << " " << j-k-1 <<  " " << aux << "\n";
            if((u[j] + aux) != 0) ok = false;
        }
        if(ok) cout << "Yes\n";
        else cout << "No\n";
    }

}
 