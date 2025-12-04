#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1003;
char gr[N][N];
int ans[N * N];
int dx[] = {0, 0, 1, -1, 1, 1, -1, -1};
int dy[] = {1, -1, 0, 0, 1, -1, 1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, q;
    cin >> n >> m >> q;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin >> gr[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ans[gr[i][j] - '0']++;
            for(int k = 0; k < 8; k++){
                ll cn = 0;
                ll cs = 0, cs2 = 1;
                int ci = i, cj = j;
                bool lo = true;
                for(int u = 0; ; u++){
                    if(ci == 0 || ci > n || cj == 0 || cj > m) break;

                    if(gr[ci][cj] == '+' || gr[ci][cj] == '*'){
                        if(lo) break;
                        lo = true;
                    }else{
                        lo = false;
                    }
                    
                    if(gr[ci][cj] == '+'){
                        cn += cs * cs2;
                        cs = 0;
                        cs2 = 1;
                    }else if(gr[ci][cj] == '*'){
                        cs2 = cs * cs2;
                        cs = 0;
                    }else{
                        cs *= 10;
                        cs += gr[ci][cj] - '0';
                    }
                    if(cn >= N*N || cn + cs * cs2 >= N * N) break;
                    ci += dx[k];
                    cj += dy[k];
                    if(u == 0) continue;
                    if(!lo){
                        ans[cn + cs * cs2]++;
                    }
                    
                }
            }
        }
    }
    for(int i=1;i<=q;i++){
        int x;
        cin >> x;
        cout << ans[x] << "\n";
    }
}
