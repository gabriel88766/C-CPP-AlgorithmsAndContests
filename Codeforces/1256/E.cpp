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
    int n;
    cin >> n;
    vector<pair<int,int>> vp(n);
    for(int i=0;i<n;i++){
        cin >> vp[i].first;
        vp[i].second = i;
    }
    sort(vp.begin(), vp.end());
    vector<int> dp(n, INF_INT);
    vector<int> beg(n, 0);
    for(int i = 1; i<n;i++) dp[i] = vp[i].first - vp[0].first;
    for(int i=5;i<n;i++){
        for(int j=max(2, i-15); j<= i-3; j++){
            int nxt = dp[j] + vp[i].first - vp[j+1].first;
            if(nxt < dp[i]){
                dp[i] = nxt;
                beg[i] = j+1;
            }
        }
    }
    int qt = 1, cur = n-1;    
    vector<int> ans(n);
    while(beg[cur] != 0){
        for(int i=beg[cur]; i<= cur; i++){
            ans[vp[i].second] = qt;
        }
        cur = beg[cur]-1;
        qt++;
    }
    for(int i=beg[cur]; i<= cur; i++){
        ans[vp[i].second] = qt;
    }
    cout << dp[n-1] << " " <<  qt << "\n";
    for(auto x : ans) cout << x << " ";
}
