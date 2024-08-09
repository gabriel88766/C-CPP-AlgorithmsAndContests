#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

const int N = 5e5+3;
vector<int> dp(N, INF_INT);

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> ans;
    vector<pair<int,int>> att;
    dp[0] = -1;
    int mv = 0;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        int p = lower_bound(dp.begin(), dp.end(), x) - dp.begin();
        dp[p] = x;
        mv = max(mv, p);
        att.push_back({p, i});
    }
    cout << mv << "\n";
    for(int i=n-1;i>=0;i--){
        if(att[i].first == mv){
            ans.push_back({att[i].second});
            mv--;
        }
    }
    reverse(ans.begin(), ans.end());
    for(auto x : ans) cout << x << " ";
    cout << "\n";

}
