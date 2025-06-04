#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 405;
int d[N][N];
int dx[] = {1, -1, 1, -1};
int dy[] = {1, 1, -1, -1};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m;
    cin >> n >> m;
    queue<pair<int, int>> q;
    q.push({1, 1});
    memset(d, 63, sizeof(d));
    d[1][1] = 0;
    while(!q.empty()){
        auto [a, b] = q.front();
        q.pop();
        int d1 = n;
        for(int i=0;i<=n;i++){
            while(d1 != 0 && d1*d1 + i*i > m) d1--;
            if(d1 == 0 && d1*d1 + i*i > m) break;
            if(d1*d1 + i*i == m){
                for(int j=0;j<4;j++){
                    if(a+i*dx[j] >= 1 && a + i*dx[j] <= n && b+d1*dy[j] >= 1 && b + d1*dy[j] <= n){
                        if(d[a+i*dx[j]][b+d1*dy[j]] > d[a][b] + 1){
                            d[a+i*dx[j]][b+d1*dy[j]] = d[a][b] + 1;
                            q.push({a+i*dx[j], b+d1*dy[j]});
                        }
                    }
                }
                for(int j=0;j<4;j++){
                    if(a+d1*dx[j] >= 1 && a + d1*dx[j] <= n && b+i*dy[j] >= 1 && b + i*dy[j] <= n){
                        if(d[a+d1*dx[j]][b+i*dy[j]] > d[a][b] + 1){
                            d[a+d1*dx[j]][b+i*dy[j]] = d[a][b] + 1;
                            q.push({a+d1*dx[j], b+i*dy[j]});
                        }
                    }
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(d[i][j] == INF_INT) d[i][j] = -1;
            cout << d[i][j] << " ";
        }
        cout << "\n";
    }
}
