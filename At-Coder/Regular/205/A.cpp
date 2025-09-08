#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 505;
char gr[N][N];
ll cnt[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, q;
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> gr[i][j];
        }
    } 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(gr[i][j] == '.' && gr[i+1][j] == '.' && gr[i][j+1] == '.' && gr[i+1][j+1] == '.'){
                cnt[i][j]++;
            }
            cnt[i][j] += cnt[i-1][j] + cnt[i][j-1] - cnt[i-1][j-1];
        }
    }   
    for(int i=1;i<=q;i++){
        int u, d, l, r;
        cin >> u >> d >> l >> r;
        ll ans = cnt[d-1][r-1] - cnt[d-1][l-1] - cnt[u-1][r-1] + cnt[u-1][l-1];
        cout << ans << "\n";
    }
}
