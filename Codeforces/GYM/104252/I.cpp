#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bitset<10005> bs[10005];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int r, c;
    cin >> r >> c;
    vector<pair<int,int>> pos(r*c+1);
    vector<vector<int>> v(r, vector<int>(c));
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin >> v[i][j];
            pos[v[i][j]] = {i, j};
        }
    }
    int ans = 0;
    for(int i=r*c;i>=1;i--){
        bs[i][i] = true;
        for(int j=0;j<4;j++){
            int x = pos[i].first+dx[j];
            int y = pos[i].second+dy[j];
            if(x < 0 || x >= r) continue;
            if(y < 0 || y >= c) continue;
            if(v[x][y] > i){
                bs[i] |= bs[v[x][y]];
            }
        }
        ans = max(ans, (int)bs[i].count());
    }
    cout << ans;
}
