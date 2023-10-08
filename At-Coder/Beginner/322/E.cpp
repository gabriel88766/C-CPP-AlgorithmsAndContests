#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, k, p;
    cin >> n >> k >> p;
    vector<ll> c(n);
    vector<vector<ll>> up(n, vector<ll>(k));
    for(int i=0;i<n;i++){
        cin >> c[i];
        for(int j=0;j<k;j++) cin >> up[i][j];
    }
    int po[k];
    for(int i=0;i<k;i++){
        if(i == 0) po[i] = 1;
        else po[i] = (p+1) * po[i-1];
    }
    function<vector<int>(int)> int2st = [&p, &k](int val){
        vector<int> ans(k);
        int x = 0;
        while(val){
            ans[x] = val % (p+1);
            val /= (p+1);
            x++;
        }
        return ans;
    };
    function<int(vector<int>)> st2int = [&po, &k, &p](vector<int> st){
        int ans = 0;
        for(int i=0; i<k;i++){
            if(st[i] > p) st[i] = p;
            ans += st[i]*po[i];
        }
        return ans;
    };
    int fs = 0;
    for(int i=0;i<k;i++) fs += p*po[i];

    vector<ll> dp(fs+1, INF_LL);
    dp[0] = 0;
    for(int i=0;i<n;i++){
        for(int j=fs;j>=0;j--){
            if(dp[j] == INF_LL) continue;
            auto vec = int2st(j);
            for(int w=0;w<k;w++){
                vec[w] += up[i][w];
            }
            auto st = st2int(vec);
            if(dp[st] > dp[j] + c[i]){
                dp[st] = dp[j] + c[i];
            }
        }
    }
    if(dp[fs] != INF_LL) cout << dp[fs] << "\n";
    else cout << "-1\n";
}
