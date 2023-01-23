#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 17e6;
int dp[N], p[N];

int dist[25][25];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, x, y;
    memset(dp, 63, sizeof(dp));
    vector<int> v;
    vector<pair<int,int>> cord(25);
    cin >> x >> y >> n;
    cord[0] = {x,y};
    for(int i=1;i<=n;i++){
        cin >> x >> y;
        cord[i] = {x,y};
    }
    for(int i = 0;i<=n;i++){
        for(int j = 0;j<=n;j++){
            x = cord[i].first - cord[j].first;
            y = cord[i].second - cord[j].second;
            dist[i][j] = x*x + y*y; 
        }
    }
    dp[0] = 0;
    int curpot = 1 << 0, potind = 1;
    for(int i=0; i < (1 << n)-1;i++){
        for(int j=0; (1 << j) < (1 << n);j++) if(!(i & 1 << j)){
            potind = j+1;
            break;
        }
        int nxt = i | 1 << (potind-1);
        if(dp[nxt] > dp[i] + 2 * dist[0][potind]){
            dp[nxt] = dp[i] + 2 * dist[0][potind];
            p[nxt] = potind;
        }
        for(int k=(potind+1);k<=n;k++){
            if(nxt & (1 << (k-1))) continue;
            int nnxt = nxt | (1 << (k-1));
            if(dp[nnxt] > dp[i] + dist[0][potind] + dist[potind][k] + dist[k][0]){
                dp[nnxt] = dp[i] + dist[0][potind] + dist[potind][k] + dist[k][0];
                p[nnxt] = 25*potind+k;
            }
        }
    }
    
    int cur = (1 << n) - 1;
    vector<int> ans(1, 0);
    while(cur != 0){
        int j, k;
        k = p[cur] % 25;
        j = p[cur] / 25;
        ans.push_back(k);
        if(j) ans.push_back(j);
        ans.push_back(0);
        if(j) cur ^= (1 << (j-1));
        cur ^= (1 << (k-1));
    }
    reverse(ans.begin(),ans.end());
    cout << dp[(1 << n) - 1] << "\n";
    for(int i=0;i<ans.size();i++) cout << ans[i] << " ";

}
 