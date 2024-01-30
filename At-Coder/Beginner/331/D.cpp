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
    int n, q;
    cin >> n >> q;
    vector<vector<char>> v(n+1, vector<char>(n+1));
    vector<vector<ll>> ps(n+1, vector<ll>(n+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> v[i][j];
            if(v[i][j] == 'B') ps[i][j] = 1;
            ps[i][j] += ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1];
        }
    }
    for(int i=0;i<q;i++){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ll h = (c - a + 1)/n;
        ll w = (d - b + 1)/n;
        ll ans = ps[n][n] * w * h;
        bool s1 = false, s2 = false;
        ll m1 = 0, m2 = 0;
        if((c + 1) % n != a % n){
            //from a%n to c%n
            if(c % n >= a % n){
                m1 = (ps[c%n+1][n] - ps[a%n][n]);
            }else{
                m1 = (ps[c%n+1][n] + ps[n][n] - ps[a%n][n]);
            }
        }
        if((d + 1) % n != b % n){
            if(d % n >= b % n){
                m2 = (ps[d%n+1][n] - ps[b%n][n]);
            }else{
                m2 = (ps[d%n+1][n] + ps[n][n] - ps[b%n][n]);
            }
        }
        ans += m1 * w;
        ans += m2 * h;
        if(m1 && m2){
            if(c % n >= a % n){
                if(d % n >= b % n){
                    ans += ps[c%n+1][d%n+1] - ps[a%n][d%n+1] - ps[c%n+1][b%n] + ps[a%n][b%n];
                }else{
                    
                }
            }else{

            }
        }
        //ans += m1 * m2;
        cout << ans << "\n";
    }
}
