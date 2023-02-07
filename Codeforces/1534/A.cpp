#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

char mat[55][55];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        for(int i=0;i<=50;i++) mat[0][i] = mat[n+1][i] = mat[i][0] = mat[i][m+1] = 0;
        queue<pair<int,int>> q;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                cin >> mat[i][j];
                if(mat[i][j] == 'R') q.push({i, j});
                else if(mat[i][j] == 'W') q.push({i, j});
            }
        }
        bool ok = true, emp = false;
        if(q.empty()) emp  = true;
        while(!q.empty()){
            auto [ui, uj] = q.front();
            q.pop();
            char c = mat[ui][uj], nxt;
            nxt = c == 'W' ? 'R' : 'W'; 
            for(int i=0;i<4;i++){
                if(!ok) break;
                auto cell = mat[ui+dx[i]][uj+dy[i]];
                if(cell == nxt) continue;
                else if(cell == c) ok = false;
                else if(cell != 0){
                    q.push({ui+dx[i], uj+dy[i]});
                    mat[ui+dx[i]][uj+dy[i]] = nxt;
                }
            }
            if(!ok) break;
        }
        if(emp){
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    if((i+j)%2) mat[i][j] = 'W';
                    else mat[i][j] = 'R';
                }
            }
        }
        if(ok){
            cout << "YES\n";
            for(int i=1;i<=n;i++){
                for(int j=1;j<=m;j++){
                    cout << mat[i][j];
                }
                cout << "\n";
            }
        }else cout << "NO\n";

    }
}
