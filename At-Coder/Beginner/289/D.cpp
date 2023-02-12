#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[100005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, m, x;
    cin >> n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a[i];
    cin >> m;
    vector<int> b(m);
    for(int i=0;i<m;i++){
        cin >> b[i];
        dp[b[i]] = -1;
    }
    cin >> x;
    dp[0] = 1;
    for(int i=1;i<=x;i++){
        if(dp[i] == -1) continue;
        for(int j=0;j<n;j++){
            if(a[j] > i) break;
            if(dp[i - a[j]] == 1) dp[i] = 1;
        }
    }
    if(dp[x] == 1) cout << "Yes";
    else cout << "No";
    
}
