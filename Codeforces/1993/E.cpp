#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dpr[16][1 << 16][16], dpc[16][1 << 16][16];
int adr[16][16], adc[16][16];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        vector<vector<int>> v(n+1,vector<int>(m+1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin >> v[i][j];
            }
        }
        for(int i=0;i<n;i++){
            int cur = 0;
            for(int j=0;j<m;j++) cur ^= v[i][j];
            v[i][m] = cur;
        }
        for(int j=0;j<=m;j++){
            int cur = 0;
            for(int i=0;i<n;i++) cur ^= v[i][j];
            v[n][j] = cur;
        }
        //for j not selected as col
        for(int j=0;j<=m;j++){
            for(int s=0;s<=n;s++){
                for(int d=s+1;d<=n;d++){
                    int cur = 0;
                    for(int c=0;c<=m;c++){
                        if(j == c) continue;
                        cur += abs(v[s][c] - v[d][c]);
                    }
                    adr[s][d] = adr[d][s] = cur;
                }
            }
            for(int i=0;i<(1 << (n+1));i++){
                for(int k=0;k<=n;k++){
                    dpr[j][i][k] = INF_INT;
                }
            }
            for(int i=0;i<=n;i++) dpr[j][1 << i][i] = 0;
            for(int i=1;i<(1 << (n+1)); i++){
                for(int s=0;s<=n;s++){
                    if(i & (1 << s)){
                        for(int d=0;d<=n;d++){
                            if(!(i & (1 << d))){
                                dpr[j][i | (1 << d)][d] = min(dpr[j][i | (1 << d)][d], dpr[j][i][s] + adr[s][d]);
                            }
                        }
                    }
                }
            }
        }
        //for i not selected as row.. (ctrl c ctrl v...)
        for(int i=0;i<=n;i++){
            for(int s=0;s<=m;s++){
                for(int d=s+1;d<=m;d++){
                    int cur = 0;
                    for(int c=0;c<=n;c++){
                        if(i == c) continue;
                        cur += abs(v[c][s] - v[c][d]);
                    }
                    adc[s][d] = adc[d][s] = cur;
                }
            }
            for(int j=0;j<(1 << (m+1));j++){
                for(int k=0;k<=m;k++){
                    dpc[i][j][k] = INF_INT;
                }
            }
            for(int j=0;j<=m;j++) dpc[i][1 << j][j] = 0;
            for(int j=1;j<(1 << (m+1)); j++){
                for(int s=0;s<=m;s++){
                    if(j & (1 << s)){
                        for(int d=0;d<=m;d++){
                            if(!(j & (1 << d))){
                                dpc[i][j | (1 << d)][d] = min(dpc[i][j | (1 << d)][d], dpc[i][j][s] + adc[s][d]);
                            }
                        }
                    }
                }
            }
        }
        //now I can solve analysing all possibilities.
        int ans = INF_INT;
        int mskm = (1 << (m+1)) - 1, mskn = (1 << (n+1)) - 1;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                int minr = INF_INT, minc = INF_INT;
                for(int k=0;k<=n;k++) minr = min(minr, dpr[j][mskn ^ (1 << i)][k]);
                for(int k=0;k<=m;k++) minc = min(minc, dpc[i][mskm ^ (1 << j)][k]);
                ans = min(ans, minc + minr);
            }
        }



        cout << ans << "\n";



    }
}
