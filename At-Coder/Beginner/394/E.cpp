#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 105;
int ans[N][N];
char gr[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(ans, 63, sizeof(ans));
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> gr[i][j];
        }
    }
    queue<pair<int,int>> qp;
    for(int i=1;i<=n;i++){
        qp.push({i, i});
        ans[i][i] = 0;
    }
    for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++){
            if(j == k) continue;
            if(gr[j][k] != '-'){
                ans[j][k] = 1;
                qp.push({j, k});
            }
        }
    }
    while(!qp.empty()){
        auto [a, b] = qp.front();
        qp.pop();
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                if(gr[j][a] == gr[b][k] && gr[j][a] != '-' && ans[j][k] > ans[a][b] + 2){
                    ans[j][k] = ans[a][b] + 2;
                    qp.push({j, k});
                }
            }
        }
    }
    for(int j=1;j<=n;j++){
        for(int k=1;k<=n;k++){
            if(ans[j][k] == INF_INT) cout << "-1 ";
            else cout << ans[j][k] << " ";
        }
        cout << "\n";
    }
}
