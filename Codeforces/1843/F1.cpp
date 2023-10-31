#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

struct In{
    int l, r;
};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<In> vp1(n+2), vp2(n+2);
        vector<int> v(n+2);
        int cnt = 1;
        vp1[1] = vp2[1] = {0, 1};
        v[1] = 1;
        for(int i=0;i<n;i++){
            char c;
            cin >> c;
            if(c == '?'){
                int u, v, k;
                cin >> u >> v >> k;
                if(k >= vp2[v].l && k <= vp2[v].r) cout << "YES\n";
                else cout << "NO\n";
            }else{
                int u, x;
                cin >> u >> x;
                cnt++;
                v[cnt] = v[u] + x;
                vp1[cnt] = {min(vp1[u].l, v[cnt]), max(vp1[u].r, v[cnt])};
                vp2[cnt] = {min(v[cnt] - vp1[u].r, vp2[u].l), max(v[cnt] - vp1[u].l, vp2[u].r)};
            }
        }
    }
}
