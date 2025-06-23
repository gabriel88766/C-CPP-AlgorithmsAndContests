#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 205;
char gr[N][N];
int pl[N][N];
int en[N][N];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    memset(en, 0xFF, sizeof(en));
    int h, w;
    cin >> h >> w;
    int si, sj, di, dj;
    for(int i=1;i<=h;i++){
        for(int j=1;j<=w;j++){
            cin >> gr[i][j];
            if(gr[i][j] == 'S'){
                si = i, sj = j;
            }
            if(gr[i][j] == 'T'){
                di = i, dj = j;
            }
        }
    }
    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        int r, c, e;
        cin >> r >> c >> e;
        pl[r][c] = e;
    }
    en[si][sj] = pl[si][sj];
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq; 
    pq.push({si, sj, en[si][sj]});
    while(pq.size() != 0){
        auto [i, j, eng] = pq.top();
        pq.pop();
        if(eng == 0) continue;
        if(eng != en[i][j]) continue;
        for(int k=0;k<4;k++){
            int xi = i + dx[k];
            int xj = j + dy[k];
            if(xi >= 1 && xi <= h && xj >= 1 && xj <= w && gr[xi][xj] != '#'){
                int nxt = max(eng - 1, pl[xi][xj]);
                if(nxt > en[xi][xj]){
                    en[xi][xj] = nxt;
                    pq.push({xi, xj, nxt});
                }
            }
        }
    }
    if(en[di][dj] != -1) cout << "Yes\n";
    else cout << "No\n";
    
}
