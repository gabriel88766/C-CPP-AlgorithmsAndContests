#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int di[] = {0, 0, 1, -1};
int dj[] = {1, -1, 0, 0};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int t;
    cin >> t;
    while(t--){
        int h, w;
        cin >> h >> w;
        vector<string> vs(h+1);
        for(int i=1;i<=h;i++){
            cin >> vs[i];
            vs[i] = " " + vs[i];
        }
        vector<vector<vector<int>>> dist(h+2, vector<vector<int>>(w+2, vector<int>(4, INF_INT)));
        deque<tuple<int, int, int>> qp;
        dist[1][1][0] = 0; //0 is from left, 1 is right, 2 is up 3 is down.
        qp.push_back({1, 1, 0});
        while(qp.size()){
            auto [i, j, tp] = qp.front();
            qp.pop_front();
            if(i >= 1 && i <= h && j >= 1 && j <= w){
                vector<int> cst = {1, 1, 1};
                vector<int> xorv = {0, 2, 3};
                cst[vs[i][j] - 'A'] = 0;
                for(int k=0;k<3;k++){
                    int nv = xorv[k] ^ tp;
                    if(dist[i + di[nv]][j + dj[nv]][nv] > dist[i][j][tp] + cst[k]){
                        dist[i + di[nv]][j + dj[nv]][nv] = dist[i][j][tp] + cst[k];
                        if(cst[k]) qp.push_back({i + di[nv], j + dj[nv], nv});
                        else qp.push_front({i + di[nv], j + dj[nv], nv});
                    }
                }
            }
        }
        cout << dist[h][w+1][0] << "\n";
    }
}
