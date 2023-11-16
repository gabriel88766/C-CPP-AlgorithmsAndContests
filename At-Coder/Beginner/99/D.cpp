#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int d[3][31];
int cnt[3][31];
int D[31][31];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, c;
    cin >> n >> c;
    for(int i=1;i<=c;i++){
        for(int j=1;j<=c;j++){
            cin >> D[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int p = (i + j) % 3;
            int aux;
            cin >> aux;
            cnt[p][aux]++;
        }
    }
    for(int i=0;i<3;i++){
        for(int j=1;j<=c;j++){
            //d[i][j]
            for(int k=1;k<=c;k++){
                d[i][j] += cnt[i][k] * D[k][j];
            }
        }
    }
    int ans = INF_INT;
    for(int i=1;i<=c;i++){
        for(int j=1;j<=c;j++){
            if(i == j) continue;
            for(int k=1;k<=c;k++){
                if(k == j || k == i) continue;
                ans = min(ans, d[0][i] + d[1][j] + d[2][k]);
            }
        }
    }
    cout << ans << "\n";
}
