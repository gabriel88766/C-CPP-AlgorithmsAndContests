#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2005;
ll v[N], adj[N][N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k;
    cin >> n >> k;
    for(int i=1;i<=n;i++) cin >> v[i];
    /*if(n == k){
        cout << "0\n";
        return 0;
    }*/
    memset(adj, 63, sizeof(adj));
    for(int i=1;i<=n;i++) adj[0][i] = 0;
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            ll dif = abs(v[j] - v[i]);
            ll d = j - i;
            ll md = dif / d;
            if(dif % d) md++;
            adj[i][j] = md;
        }
    }
    int nd = n-k;
    int lo = 0, hi = 2'000'000'001;
    while(lo != hi){
        int mid = lo + (hi-lo)/2;
        vector<int> dp(n+1, 0);
        int mdp = 0;
        for(int i=0;i<=n;i++){
            mdp = max(dp[i], mdp);
            for(int j=i+1;j<=n;j++){
                if(adj[i][j] <= mid) dp[j] = max(dp[j], dp[i] + 1);
            }
        }
        if(mdp >= nd) hi = mid;
        else lo = mid + 1;
    }
    cout << lo << "\n";
}
