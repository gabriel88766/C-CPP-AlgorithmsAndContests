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
        int n, q;
        cin >> n >> q;
        vector<int> v(n+1), pl(n+1);
        vector<bool> us(n+1, false);
        for(int i=1;i<=n;i++){
            cin >> v[i];
            pl[v[i]] = i;
        }
        for(int i=0;i<q;i++){
            int l, r, k;
            cin >> l >> r >> k;
            if(pl[k] < l || pl[k] > r) cout << "-1 ";
            else{
                int ln = 0, gn = 0;
                vector<int> nc;
                while(true){
                    int m = (l + r)/2;
                    if(m == pl[k]) break;
                    else if(m < pl[k]){
                        if(v[m] > k){
                            ln++;
                        }
                        l = m + 1;
                    }else{
                        if(v[m] < k){
                            gn++;
                        }
                        r = m - 1;
                    }
                    nc.push_back(v[m]);
                    us[v[m]] = true;
                }
                int mn = min(ln, gn);
                int ans = 2*mn;
                ln -= mn;
                gn -= mn;
                ans += 2*(gn + ln);
                bool ok = true;
                if(gn){
                    int x = n;
                    while(gn){
                        if(!us[x]){
                            if(x > k) gn--;
                            else break;
                        }
                        x--;
                    }
                    if(gn) ok = false;
                }else if(ln){
                    int x = 1;
                    while(ln){
                        if(!us[x]){
                            if(x < k) ln--;
                            else break;
                        }
                        x++;
                    }
                    if(ln) ok = false;
                }
                for(auto &x : nc) us[x] = false;
                if(ok) cout << ans << " ";
                else cout << "-1 ";
            }
        }
        cout << "\n";
    }
}
