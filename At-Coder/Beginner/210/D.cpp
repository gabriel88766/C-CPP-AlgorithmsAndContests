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
    ll h, w, c;
    cin >> h >> w >> c;
    vector<ll> mn(w, INF_LL);
    vector<vector<ll>> gr(h, vector<ll>(w));
    ll rmn = INF_LL, ans = INF_LL;
    //THIS SOLVE JUST THE CASE I >= I' and J >= J'
    //missing case I >= I' and J' >= J;
    for(int i=0;i<h;i++){
        rmn = INF_LL;
        for(int j=0;j<w;j++){
            cin >> gr[i][j];
            rmn = min(rmn, mn[j]);
            ans = min(ans, c*(i+j) + rmn + gr[i][j]);
            mn[j] = min(mn[j], gr[i][j] + c * -(i + j));
            rmn = min(rmn, mn[j]);
        }
    }
    fill(mn.begin(), mn.end(), INF_LL);
    for(int i=0;i<h;i++){
        rmn = INF_LL;
        for(int j=w-1;j>=0;j--){
            rmn = min(rmn, mn[j]);
            ans = min(ans, c*(i-j) + rmn + gr[i][j]);
            mn[j] = min(mn[j], gr[i][j] + c * -(i - j));
            rmn = min(rmn, mn[j]);
        }
    }
    cout << ans << "\n";
}
