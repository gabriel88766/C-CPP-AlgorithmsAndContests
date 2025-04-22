#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll gr[25][25];
ll po[50];
vector<ll> p1[25][25], p2[25][25];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll n, m;
    cin >> n >> m;
    po[0] = 1;
    for(int i=1;i<=40;i++){
        po[i] = (po[i-1] * 10) % m;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> gr[i][j];
            gr[i][j] *= (po[2*n - i - j]);
            gr[i][j] %= m;
        }
    }
    //from 1, 1, n-1 moves
    //from n, n, n-1 moves
    for(int i=0;i<(1 << (n-1)); i++){
        ll s1 = gr[1][1], s2 = gr[n][n];
        int x1 = 1, y1 = 1, x2 = n, y2 = n;
        for(int j=0;j<n-1;j++){
            if(i & (1 << j)){
                x1++;
                x2--;
            }else{
                y1++;
                y2--;
            }
            s1 += gr[x1][y1];
            s2 += gr[x2][y2];
        }
        p1[x1][y1].push_back(s1 % m);
        p2[x2][y2].push_back((s2 - gr[x2][y2] + m) % m);
    }
    ll ans = 0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            sort(p1[i][j].begin(), p1[i][j].end());
            sort(p2[i][j].begin(), p2[i][j].end());
            for(auto &x : p1[i][j]){
                auto it = lower_bound(p2[i][j].begin(), p2[i][j].end(), m-x);
                if(it != p2[i][j].begin()) it = prev(it);
                else it = prev(p2[i][j].end());
                ans = max(ans, (x + *it)%m);
            }
        }
    }
    cout << ans << "\n";
}
