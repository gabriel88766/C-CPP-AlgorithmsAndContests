#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 2e5+3;
pair<double, double> dp[N];
//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> v(k);
    for(int i=0;i<k;i++){
        cin >> v[i];
        dp[v[i]] = {0.0, 1.0};
    }
    int tts = 0;
    int cs = 1;
    if(k >= 1) tts = 1;
    for(int i=1;i<k;i++){
        if(v[i] == v[i-1] + 1) cs++;
        else cs = 1;
        tts = max(cs, tts);
    }
    if(tts >= m){
        cout << "-1\n";
        return 0;
    }
    dp[n] = {0, 0};
    pair<double, double> ps;
    for(int i=n-1;i>=0;i--){
        ps.first += dp[i+1].first;
        ps.second += dp[i+1].second;
        ps.first -= dp[i+m+1].first;
        ps.second -= dp[i+m+1].second;
        if(dp[i] == make_pair(0.0, 1.0)){
            continue;
        }
        auto cs = ps;
        cs.first /= m;
        cs.second /= m;
        cs.first += 1;
        dp[i] = cs;
    }
    cout << fixed << setprecision(6) << dp[0].first/(1.0 - dp[0].second) << "\n";
}
