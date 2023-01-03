#include <bits/stdc++.h>
typedef long long int ll;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
using namespace std;

int dp[100005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    vector<int> h(1005);
    vector<int> s(1005);
    int n, x;
    cin >> n >> x;
    for(int i=0;i<n;i++) cin >> h[i];
    for(int i=0;i<n;i++) cin >> s[i];
    for(int i=0;i<n;i++){
        for(int j=x;j>=1;j--){
            if(h[i] <= j){
                dp[j] = max(dp[j], dp[j-h[i]] + s[i]);
            }
        }
    }
    cout << dp[x];
}
