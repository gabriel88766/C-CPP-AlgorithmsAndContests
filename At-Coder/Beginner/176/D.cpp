#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
char gr[N][N];
int dist[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(dist, 63, sizeof(dist));
    int h, w;
    cin >> h >> w;
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
        }
    }
    deque<pair<int, int>> dq;
    dq.push_back({si, sj});
    dist[si][sj] = 0;
    while(dq.size()){
        auto [ci, cj] = dq.front();
        dq.pop_front();
        for(int i=-2;i<=2;i++){
            for(int j=-2;j<=2;j++){
                if(ci + i >= 1 && ci + i <= h){
                    if(cj + j >= 1 && cj + j <= w){
                        if(gr[ci+i][cj+j] == '.'){
                            if(abs(i) + abs(j) == 1){
                                if(dist[ci+i][cj+j] > dist[ci][cj]){
                                    dist[ci+i][cj+j] = dist[ci][cj];
                                    dq.push_front({ci+i, cj+j});
                                }
                            }else{
                                if(dist[ci+i][cj+j] > dist[ci][cj] + 1){
                                    dist[ci+i][cj+j] = dist[ci][cj] + 1;
                                    dq.push_back({ci + i, cj + j});
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    if(dist[di][dj] != INF_INT) cout << dist[di][dj] << "\n";
    else cout << "-1\n";
}
