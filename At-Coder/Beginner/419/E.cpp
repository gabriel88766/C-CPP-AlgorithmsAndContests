#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 505;
int v[N];
ll dp[N], ndp[N];
int cnt[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, l;
    cin >> n >> m >> l;
    for(int i=1;i<=n;i++) cin >> v[i];
    vector<vector<int>> bkt(l);
    for(int i=1;i<=n;i++){
        bkt[i%l].push_back(v[i]);
    }
    memset(dp, 63, sizeof(dp));
    dp[0] = 0;
    for(int i=0;i<l;i++){
        //one by one
        memset(ndp, 63, sizeof(ndp));
        for(int j=0;j<m;j++) cnt[j] = 0;
        for(auto x : bkt[i]) cnt[x]++;
        //calc cost to 0;
        ll cst = 0;
        for(auto x : bkt[i]) cst += (m - x) % m;
        for(int j=0;j<m;j++){
            for(int fr=0;fr<m;fr++){
                ndp[(fr+j) % m] = min(ndp[(fr+j) % m], dp[fr] + cst);
            }
            cst += bkt[i].size();
            if(j < m-1) cst -= m * cnt[j+1];
        }
        for(int j=0;j<m;j++) dp[j] = ndp[j];
    }
    cout << dp[0] << "\n";
}
