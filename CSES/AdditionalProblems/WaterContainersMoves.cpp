#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1005;
ll dp[N][N];
tuple<ll, ll, string> par[N][N];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    ll a, b, x;
    cin >> a >> b >> x;
    priority_queue<tuple<ll, ll, ll>, vector<tuple<ll, ll, ll>>, greater<tuple<ll, ll, ll>>> pq;
    memset(dp, 63, sizeof(dp));
    dp[0][0] = 0;
    pq.push({0, 0, 0});
    while(pq.size()){
        auto [d, x, y] = pq.top();
        pq.pop();
        if(dp[x][y] != d) continue;
        assert(x <= a && y <= b);
        //move B A
        ll d1 = min(a - x, y);
        if(dp[x + d1][y - d1] > dp[x][y] + d1){
            dp[x + d1][y - d1] = dp[x][y] + d1;
            par[x + d1][y - d1] = {x, y, "MOVE B A"};
            pq.push({dp[x + d1][y - d1], x + d1, y - d1});
        } 
        //MOVE A B
        ll d2 = min(x, b - y);
        if(dp[x - d2][y + d2] > dp[x][y] + d2){
            dp[x - d2][y + d2] = dp[x][y] + d2;
            par[x - d2][y + d2] = {x, y, "MOVE A B"};
            pq.push({dp[x - d2][y + d2], x - d2, y + d2});
        }
        //FILL A
        if(dp[a][y] > dp[x][y] + a - x){
            dp[a][y] = dp[x][y] + a - x;
            par[a][y] = {x, y, "FILL A"};
            pq.push({dp[a][y], a, y});
        }
        //FILL B
        if(dp[x][b] > dp[x][y] + b - y){
            dp[x][b] = dp[x][y] + b - y;
            par[x][b] = {x, y, "FILL B"};
            pq.push({dp[x][b], x, b});
        }
        //EMPTY A
        if(dp[0][y] > dp[x][y] + x){
            dp[0][y] = dp[x][y] + x;
            par[0][y] = {x, y, "EMPTY A"};
            pq.push({dp[0][y], 0, y});
        }
        //EMPTY B
        if(dp[x][0] > dp[x][y] + y){
            dp[x][0] = dp[x][y] + y;
            par[x][0] = {x, y, "EMPTY B"};
            pq.push({dp[x][0], x, 0});
        }
    }
    pair<ll, ll> lw = {INF_LL, INF_LL};
    for(int j=0;j<=b;j++){
        if(dp[x][j] < lw.first){
            lw = {dp[x][j], j};
        }
    }
    if(lw.first == INF_LL) cout << "-1\n";
    else{
        vector<string> ans;
        ll u = x, v = lw.second;
        while(u != 0 || v != 0){
            ans.push_back(get<2>(par[u][v]));
            ll nu = get<0>(par[u][v]);
            ll nv = get<1>(par[u][v]);
            u = nu, v = nv;
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << " " << lw.first << "\n";
        for(auto &x : ans) cout << x << "\n";
    }
}   
