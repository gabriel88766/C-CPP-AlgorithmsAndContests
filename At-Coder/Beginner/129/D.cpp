#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
char gr[N][N];
int cnv[N][N], cnh[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> gr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        int lst = -1;
        for(int j=0;j<=m;j++){
            if(gr[i][j] != '.'){
                int tt = j - lst - 1;
                if(tt){
                    for(int k=lst+1;k<j;k++){
                        cnh[i][k] = tt;
                    }
                }
                lst = j;
            }
        }
    }
    for(int j=0;j<m;j++){
        int lst = -1;
        for(int i=0;i<=n;i++){
            if(gr[i][j] != '.'){
                int tt = i - lst - 1;
                if(tt){
                    for(int k=lst+1;k<i;k++){
                        cnv[k][j] = tt;
                    }
                }
                lst = i;
            }
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans = max(ans, cnh[i][j] + cnv[i][j]-1);
        }
    }
    cout << ans << "\n";
}
