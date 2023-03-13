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
    int  K, q;
    cin >> n >> K;
    vector<ll> u(n+1), ps(n+1, 0);
    for(int i=1;i<=n;i++) {
        cin >> u[i];
        int li = (i - K > 0 ? i - K : 0);
        ps[i] = ps[li] + u[i];
    }
    //cout << "\n";
    cin >> q;
    for(int i=1;i<=q;i++){
        int l, r;
        cin >> l >> r;
        set<ll>  ss;
        for(int j= l; j<=l+K-1;j++){
            int i1 = (j - K > 0 ? j - K : 0);
            int i2 = ((r/K)*K + j%K);
            if(i2 > r) i2 -= K;
            ss.insert(ps[i2]-ps[i1]);
        }
        if(ss.size()==1) cout << "Yes\n";
        else cout << "No\n";
    }

}
 