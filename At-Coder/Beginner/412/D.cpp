#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int n;
// vector<vector<vector<int>>> cycl = {{}, {}, {}, {{3}}, {{4}}, {{5}}, {{6}, {3, 3}}, {{7}, {4, 3}}, {{8}, {5, 3}, {4, 4}}};
vector<vector<pair<int, int>>> edg;
vector<pair<int, int>> pedg;
vector<int> cur;
char in[8][8];
char msin[8][8];
void init(){
    if(cur.size() == n){
        vector<int> adjc(n);
        for(auto x : cur){
            adjc[pedg[x].first]++;
            adjc[pedg[x].second]++;
        }
        if(*min_element(adjc.begin(), adjc.end()) == 2 && *max_element(adjc.begin(), adjc.end()) == 2){
            vector<pair<int, int>> cv;
            for(auto x : cur) cv.push_back(pedg[x]);
            edg.push_back(cv);
        }
        return;
    }
    int bg = cur.size() ? cur.back() + 1 : 0;
    for(int i=bg;i<pedg.size();i++){
        cur.push_back(i);
        init();
        cur.pop_back();
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            pedg.push_back({i, j});
        }
    }
    init();
    for(int i=1;i<=m;i++){
        int a, b;
        cin >> a >> b;
        if(a > b) swap(a, b);
        --a, --b ;
        in[a][b] = 1;
    }
    int ans = INF_INT;
    for(auto v : edg){
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                msin[i][j] = 0;
            }
        }
        for(auto [a, b] : v) msin[a][b] = 1;
        int cnt = 0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(msin[i][j] ^ in[i][j]) cnt++;
            }
        }
        ans = min(ans, cnt);
    }
    cout << ans << "\n";

}
