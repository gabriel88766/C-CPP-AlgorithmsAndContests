#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
ll gr[N][N];
ll ps[N][N];
ll val[N][N];
ll aux[N];

ll dpno[4][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> gr[i][j];
        }
    }

    ll ans = 0;
    //no intersection.
    auto reset = [&](){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + gr[i][j];
            }
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i + m - 1 <= n && j + m - 1 <= n) val[i][j] = ps[i+m-1][j+m-1] - ps[i+m-1][j-1] - ps[i-1][j+m-1] + ps[i-1][j-1];
                else val[i][j] = -1e16;
            }
        }
    };
    auto calcno = [&](){
        reset();  
        for(int i=1;i<=n;i++){
            dpno[2][i] = dpno[3][i] = dpno[1][i] = -1e16;
            for(int j=1;j<=n;j++){
                dpno[1][i] = max(dpno[1][i], val[i][j]);
            }
            if(i > m){
                dpno[2][i] = max({dpno[2][i-1], dpno[1][i-m] + dpno[1][i]});
                dpno[3][i] = max({dpno[3][i-1], dpno[2][i-m] + dpno[1][i]});
            }
            dpno[1][i] = max(dpno[1][i], dpno[1][i-1]);
        }
        ans = max(ans, dpno[3][n]);
    };
    calcno();
    //1 intersection
    //the intersection is up. if not, then if I make the upside down matrix it will work
    auto calcone = [&](){
        reset();
        for(int j=0;j<=n;j++) aux[j] = 0;
        for(int i=m+1;i<=n-m+1;i++){
            for(int j=1;j<=n;j++) aux[j] = max(aux[j], val[i-m][j]);
            ll m1 = 0;
            ll msum = 0;
            for(int j=m+1;j<=n;j++){
                m1 = max(m1, aux[j-m]);
                msum = max(msum, m1 + aux[j]);
            }
            for(int j=1;j<=n;j++) ans = max(ans, msum + val[i][j]);
        }
    };
    auto reverse =[&](){
        for(int i=1;i<=n/2;i++){
            for(int j=1;j<=n;j++){
                swap(gr[i][j], gr[n-i+1][j]);
            }
        }
    };
    auto transpose = [&](){
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                swap(gr[i][j], gr[j][i]);
            }
        }
    };
    calcone();
    reverse();
    calcone();
    reverse();
    //2 intersection
    //at most 1 intersection in transpose
    transpose();
    calcone();
    reverse();
    calcone();
    reverse();
    //triple intersection (i, j, k such that k - i < m)
    //the same as no intersection, but transpose the matrix
    calcno();

    cout << ans << "\n";
}
