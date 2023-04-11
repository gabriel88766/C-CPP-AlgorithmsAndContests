#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 1e9+7;
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

ll dp[505][5005];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); test input
    int n, k;
    cin >> n >> k;
    vector<int> cnt(100005, 0);
    vector<int> cnt2(100005, 0);
    set<int> nums;
    for(int i=1;i<=n*k;i++){
        int x;
        cin >> x;
        cnt[x]++;
    }
    for(int i=1;i<=n;i++){
        int x;
        cin >> x;
        cnt2[x]++;
        nums.insert(x);
    }
    vector<int> val(k+1);
    for(int i=1;i<=k;i++) cin >> val[i];
    ll ans =0;
    for(int i=1;i<=n*k;i++){
        for(int j=1;j<=n;j++){
            for(int w=1;w<=k;w++){
                if(i-w >= 0) dp[j][i] = max(dp[j][i], dp[j-1][i-w] + val[w]);
            }
        }
    }
    for(int i=1;i<=100000;i++){
        if(cnt2[i]){
            if(cnt[i] >= (cnt2[i]*k)){
                ans += val[k]*cnt2[i];
            }else{
                ans += dp[cnt2[i]][cnt[i]];
            }
        }
    }
    cout << ans;
}
