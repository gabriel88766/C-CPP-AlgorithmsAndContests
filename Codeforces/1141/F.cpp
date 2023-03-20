#include <bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
const ll INF_LL = 0x3f3f3f3f3f3f3f3f, MOD = 998244353; //1e9+7
const int INF_INT = 0x3f3f3f3f;
const long double PI = acosl(-1.), EPS = 1e-9; 
using namespace std;

int dp[1505][1505];

//cout << fixed << setprecision(6)
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("in", "r", stdin); //test input
    int n;
    cin >> n;
    vector<int> v(n+1), ps(n+1);
    for(int i=1;i<=n;i++) cin >> v[i];
    ps[0] = 0;
    for(int i=1;i<=n;i++) ps[i] = ps[i-1]+v[i];

    int maxans = 0, indi, indj;
    set<pair<int,int>> st;
    set<pair<int, pair<int,int>>> upd;
    for(int i=1;i<=n;i++){
        while(!upd.empty() && upd.begin()->first < i){
            st.insert({upd.begin()->second.first, -upd.begin()->second.second});
            upd.erase(upd.begin());
        }
        for(int j=i;j<=n;j++){
            int cs = ps[j] - ps[i-1];
            auto it = st.lower_bound({cs, -INF_INT});
            if(it != st.end() && it->first == cs){
                dp[i][j] = abs(it->second) + 1;
            }else dp[i][j] = 1;
            upd.insert({j, {cs, dp[i][j]}});
            if(dp[i][j] > maxans){
                maxans = dp[i][j];
                indi = i, indj = j;
            }
        }
    }
    int sumv = ps[indj] - ps[indi-1];
    vector<pair<int,int>> ans;
    ans.push_back({indi, indj});
    maxans--;
    int ep = indi-1, bp;
    while(ep > 0){
        bp = ep;
        while(bp > 0){
            if(sumv == (ps[ep]-ps[bp-1]) && dp[bp][ep] == maxans){
                ans.push_back({bp, ep});
                maxans--;
                ep = --bp;
            }else bp--;
        }
        ep--;
    }
    cout << ans.size() << "\n";
    for(auto x : ans ) cout << x.first << ' ' << x.second << "\n";

}
