#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 1e5+3;
vector<int> dv[N];
int dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    for(int i=2;i<N;i++){
        for(int j=i;j<N;j+=i){
            dv[j].push_back(i);
        }
    }
    int n, ans = 1;
    cin >> n;
    for(int i=1;i<=n;i++){
        int y;
        cin >> y;
        if(y == 1) continue;
        int mx = 0;
        for(auto x : dv[y]) mx = max(mx, dp[x]);
        ans = max(ans, mx + 1);
        for(auto x : dv[y]) dp[x] = mx + 1; 
    }
    cout << ans << "\n";

}

