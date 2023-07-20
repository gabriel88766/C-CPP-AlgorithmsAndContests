#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
vector<int> divs[N];
int dp[N];

void init(){
    for(int i=1;i<=200000;i++){
        for(int j=i;j<=200000;j+=i){
            divs[j].push_back(i);
        }
    }
}
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    init();
    int t;
    cin >> t;
    while(t--){
        memset(dp, 0, sizeof(dp));
        int n;
        cin >> n;
        vector<int> v(n);
        for(int i=0;i<n;i++) cin >> v[i];
        sort(v.begin(), v.end());
        for(int i=0;i<n;i++){
            int maxv = 0;
            for(auto x : divs[v[i]]){
                maxv = max(maxv, dp[x]);
            }
            dp[v[i]] = maxv+1;
        }
        int ans = 0;
        for(int i=0;i<n;i++) ans = max(ans, dp[v[i]]);
        cout << n-ans << "\n";

    }
}
