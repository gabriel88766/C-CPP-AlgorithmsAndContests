#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int h, w, k;
    cin >> h >> w >> k;
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    vector<string> gr(h+2);
    for(int i=1;i<=h;i++){
        cin >> gr[i];
        gr[i] = " " + gr[i];
    }
    for(int i=0;i<=h+1;i++) gr[i].resize(w+2);
    vector<vector<vector<pair<int, int>>>> d(2, vector<vector<pair<int, int>>>(h+2,  vector<pair<int, int>>(w+2, make_pair(INF_INT, INF_INT))));
    d[0][x1][y1] = d[1][x1][y1] = {0, 0};
    priority_queue<tuple<int, int, int, int, int>, vector<tuple<int, int, int, int, int>>, greater<tuple<int, int, int, int, int>>> pq;
    pq.push({x1, y1, 0, 0, 0}); //0 move dy
    pq.push({x1, y1, 1, 0, 0}); //1 move dx
    int ttn = 0;
    while(!pq.empty()){
        ttn++;
        assert(ttn <= 10000000);
        auto [x, y, tp, dxx, kx] = pq.top();
        pq.pop();
        if(d[tp][x][y] != make_pair(dxx, kx)) continue;
        if(kx != 0){
            for(int j=tp*2; j<2*(tp+1);j++){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(gr[nx][ny] != '.') continue;
                if(d[tp][nx][ny] > make_pair(d[tp][x][y].first, d[tp][x][y].second+1)){
                    d[tp][nx][ny] = make_pair(d[tp][x][y].first, d[tp][x][y].second+1);
                    pq.push({nx, ny, tp, d[tp][nx][ny].first, d[tp][nx][ny].second});
                }
            }
        }
        for(int j=0;j<4; j++){
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(gr[nx][ny] != '.') continue;
            if(d[j/2][nx][ny] > make_pair(d[tp][x][y].first + 1, -k+1)){
                d[j/2][nx][ny] = make_pair(d[tp][x][y].first + 1, -k+1);
                pq.push({nx, ny, j/2, d[j/2][nx][ny].first, d[j/2][nx][ny].second});
            }
        }
    }
    if(d[0][x2][y2].first != INF_INT || d[1][x2][y2].first != INF_INT) cout << min(d[0][x2][y2].first, d[1][x2][y2].first) << "\n";
    else cout << "-1\n";
}
