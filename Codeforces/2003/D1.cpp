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
        ll n, m;
        cin >> n >> m;
        vector<ll> m1(n, -1), m2(n, -1);
        ll mv = 0;
        for(int i=0;i<n;i++){
            int sz;
            cin >> sz;
            vector<ll> cur(sz);
            for(int i=0;i<sz;i++){
                cin >> cur[i];
            }
            sort(cur.begin(), cur.end());
            cur.resize(unique(cur.begin(), cur.end()) - cur.begin());
            int p = 0;
            for(int j=0;;j++){
                if(p >= cur.size() || cur[p] != j){
                    if(m1[i] == -1) m1[i] = j;
                    else{
                        m2[i] = j;
                        break;
                    }
                }else p++;
            }
            mv = max(mv, m2[i]);
        }
        ll ans = min(mv, m) + 1;
        ans *= mv;
        if(m > mv){
            ans += ((m + mv + 1) * (m - mv))/2;
        }
        cout << ans << "\n";
    }
}
