#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll ps[20][200005];
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
        for(int i=0;i<20;i++){
            for(int j=0;j<=n;j++){
                ps[i][j] = 0;
            }
        }
        vector<tuple<int, int, int>> upd;
        for(int i=1;i<=q;i++){
            int l, r;
            cin >> l >> r;
            const int bck = l - 1;
            for(int j = 0; j < 20; j++){
                const int cx = 1 << j;
                if(r - bck >= cx){
                    ps[j][bck + cx] += 1;
                    int d = (r - bck) / cx;
                    int lx = (d + 1) * cx + bck;
                    if(lx <= n) {
                        upd.push_back({j, lx, -d});
                        ps[j][lx] -= 1;
                    }
                }else break;
            }
        }
        for(int i=0;i<20;i++){
            const int cx = 1 << i;
            for(int j=cx;j<=n;j++){
                ps[i][j] += ps[i][j-cx];
            }
        }
        for(auto [a, b, c] : upd) ps[a][b] += c;
        for(int i=0;i<20;i++){
            const int cx = 1 << i;
            for(int j=cx;j<=n;j++){
                ps[i][j] += ps[i][j-cx];
            }
        }
        for(int i=1;i<=n;i++){
            ll cv = 0;
            for(int j=0;j<20;j++){
                if(j == 0) cv += ps[j][i];
                else cv += ps[j][i] * (1LL << (2*j - 1));
            }
            cout << cv << " ";
        }
        cout << "\n";
    }
}
