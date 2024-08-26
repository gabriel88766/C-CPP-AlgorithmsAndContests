#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

bitset<16384> gr[2];
vector<int> tbl[256];

int dp[2][16384];

const int N = 50000;   
int p[N], sz[N], cc[N];

void init(){
    for(int i=0;i<N;i++) {p[i] = i; sz[i] = 1; cc[i] = 0;}
}

int get(int a){ 
    return p[a] = (p[a] == a ? a : get(p[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a == b) return;
    if(sz[a] < sz[b]) swap(a,b);
    p[b] = a;
    sz[a] += sz[b];
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    tbl['0'] = {0, 0, 0, 0};
    tbl['1'] = {0, 0, 0, 1};
    tbl['2'] = {0, 0, 1, 0};
    tbl['3'] = {0, 0, 1, 1};
    tbl['4'] = {0, 1, 0, 0};
    tbl['5'] = {0, 1, 0, 1};
    tbl['6'] = {0, 1, 1, 0};
    tbl['7'] = {0, 1, 1, 1};
    tbl['8'] = {1, 0, 0, 0};
    tbl['9'] = {1, 0, 0, 1};
    tbl['A'] = {1, 0, 1, 0};
    tbl['B'] = {1, 0, 1, 1};
    tbl['C'] = {1, 1, 0, 0};
    tbl['D'] = {1, 1, 0, 1};
    tbl['E'] = {1, 1, 1, 0};
    tbl['F'] = {1, 1, 1, 1};
    int n, m;
    cin >> n >> m;
    int ans = 0, cnt = 0;
    for(int i=0;i<n;i++){
        int b = i % 2;
        for(int j=0;j<m/4;j++){
            char c;
            cin >> c;
            int p = j*4;
            for(int k=0;k<4;k++) gr[b][p+k] = tbl[c][k];
        }
        int cmp = 0;
        init();
        for(int j=0;j<m;j++) if(dp[b^1][j]) unite(dp[b^1][j], m+j);
        for(int j=0;j<m;j++){
            dp[b][j] = 0;
            if(gr[b][j]){
                if(j && dp[b][j-1]){
                    unite(2*m+j, 2*m+j-1);
                    dp[b][j] = dp[b][j-1];
                }else{
                    dp[b][j] = ++ans; // not finished
                }
                if(dp[b^1][j]){
                    if(get(m+j) != get(2*m+j)){
                        unite(m+j, 2*m + j);
                        ++cnt;
                    }
                }
            }
        }
        for(int j=0;j<m;j++){
            if(gr[b][j]){
                int x = get(2*m+j);
                if(!cc[x]) cc[x] = ++cmp;
                dp[b][j] = cc[x];
            }
        }
    }
    cout << ans - cnt << "\n";
}