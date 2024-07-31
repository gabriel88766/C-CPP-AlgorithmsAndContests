#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1 << 25;
int dp[N];
int msk[26];
int dx[] = {1, 1, -1, -1};
int dy[] = {1, -1, 1, -1};
int conv(int i, int j){
    --i;
    --j;
    return 5*i + j;
}

void init(){
    for(int i=0;i<N;i++){
        dp[i] = INF_INT;
    }
    for(int i=1;i<=5;i++){
        for(int j=1;j<=5;j++){
            int cur = 1 << conv(i, j);
            for(int k=0;k<4;k++){
                int di = i + dx[k];
                int dj = j + dy[k];
                if(di >= 1 && di <= 5 && dj >= 1 && dj <= 5) cur |= 1 << conv(di, dj);
            }
            msk[conv(i, j)] = cur;
        }
    }
    for(int i=0;i<(1 << 25);i++){
        int b = __builtin_popcount(i);
        if(b >= 9) continue;
        int cur = 0;
        for(int j=0;j<25;j++){
            if(i & (1 << j)) cur |= msk[j];
        }
        dp[cur] = min(dp[cur], b);
    }

    for(int i=(1 << 25) - 1;i >= 0; i--){
        for(int j=0;j<25;j++){
            if(i & (1 << j)){
                dp[i^(1 << j)] = min(dp[i^(1 << j)], dp[i]);
            }
        }
    }
}

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t = 0;
    cin >> t;
    while(t--){
        vector<string> v(7);
        for(int i=0;i<7;i++) cin >> v[i];
        int msk = 0;
        for(int i=1;i<=5;i++){
            for(int j=1;j<=5;j++){
                bool ok = true;
                if(v[i][j] != 'B') ok = false;
                for(int k=0;k<4;k++){
                    int di = i + dx[k];
                    int dj = j + dy[k];
                    if(v[di][dj] != 'B') ok = false;
                }
                if(ok) msk |= 1 << conv(i, j);
            }
        }
        cout << dp[msk] << "\n";
    }
}
